#include "FCFS.h"
FCFS::FCFS() {

	this->day = 0;
	while (this->job.size() != 0)
	{
		this->job.pop_back();
	}
}
FCFS::~FCFS() {

}
FCFS::FCFS(std::vector<JOB> Job) {
	this->job = Job;
	this->day = 0;
}

void FCFS::schedule(std::vector<JOB> Job) {

	if (this->job.size() == 0);
	this->job = Job;

	int curJob = -1;//当前在运行的job在jobQueue中的下标。
	bool isRun = false; //当前是否正在运行
	while (true && day == 0) {
		if (!isRun && curJob == this->job.size())
		{
			return;
		}
		if (!jobQueue.empty()) {

			// 正在等待的作业的周转时间、等待时间++
			for (int i = curJob + 1; i < jobQueue.size(); i++) {
				jobQueue[i].setWateTime(jobQueue[i].getWaitTime() + 1);
				jobQueue[i].setCycleTime(jobQueue[i].getCycleTime() + 1);
			}

			//当前正在处理的作业的周转时间++，判断作业是否完成，完成的话，开始下一个作业或者设置无正在进行的作业
			if (isRun) {
				jobQueue[curJob].setCycleTime(jobQueue[curJob].getCycleTime() + 1);
				jobQueue[curJob].setRunTime(jobQueue[curJob].getRunTime() + 1);
				if (jobQueue[curJob].isFinish() && this->day == 0) {
					jobQueue[curJob].setEndTime(this->timer);
					if (curJob + 1 < jobQueue.size()) {
						curJob++;
						jobQueue[curJob].setStartTime(this->timer);
					}
					else if (curJob + 1 == jobQueue.size()) isRun = false; //当前最后一个作业也处理完毕，无作业可以处理
				}
			}
		}

		std::vector<JOB> startjob;
		startjob = this->ComingJob(this->timer);// 将此时提交的作业加入到后备队列中
		for (auto tmpjob : startjob) {
			jobQueue.push_back(tmpjob);
			if (!isRun) {                      // 如果之前没有运行作业，那么现在开始运行刚刚加入的作业
				 curJob = jobQueue.size() - 1;
				isRun = true;
				jobQueue[curJob].setStartTime(this->timer);
			}
		}

		this->timeAdd(1);						// 时间++
	}
}
void FCFS::printSchedule() {

	std::cout << "作业编号" << "\t" << "作业名称" << "\t" << "提交时间" << "\t"
		<< "要求服务运行时间" << "\t" << "开始时间" << "\t" << "完成时间" << "\t" << "等待时间" << "\t" << "周转时间" << std::endl;
	for (auto j : this->jobQueue) {
		j.printf();
		std::cout << std::endl;
	}
}
