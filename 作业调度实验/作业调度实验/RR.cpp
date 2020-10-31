#include "RR.h"
RR::RR() {

}
RR::~RR() {

}
void RR::schedule(std::vector<JOB> Job) {
	if (this->job.size() == 0)
		this->job = Job;

	bool isRun = false; //当前是否正在运行
	while (true && day == 0) {
		if (!jobQueue.empty()) {

			// 队首的作业执行一个时间片
			JOB topjob = jobQueue.front();
			jobQueue.pop();
			topjob.setRunTime(topjob.getRunTime() + 1);
			topjob.setCycleTime(topjob.getCycleTime() + 1);

			// 没有运行的作业等待时间和周转时间加一个时间片
			int length = jobQueue.size() , cur = 0;
			while (cur++ < length) {
				JOB tmpJob = jobQueue.front();
				jobQueue.pop();
				tmpJob.setCycleTime(tmpJob.getCycleTime() + 1);
				tmpJob.setWateTime(tmpJob.getWaitTime() + 1);
				jobQueue.push(tmpJob);
			}
			//判断队首作业是否是空
			if (topjob.isFinish()) {
				topjob.setEndTime(this->timer);
				resjob.push_back(topjob);
			}
			else {
				jobQueue.push(topjob);
			}
		}
		std::vector<JOB> startjob;
		startjob = this->ComingJob(this->timer);// 将此时提交的作业加入到后备队列中
		for (auto tmpjob : startjob) {
			jobQueue.push(tmpjob);
		}

		this->timeAdd(1);						// 时间++
		if (!isRun && resjob.size() == Job.size())
		{
			return;
		}
	}
}

void RR::printSchedule() {
	std::cout << "作业编号" << "\t" << "作业名称" << "\t" << "提交时间" << "\t"
		<< "要求服务运行时间" << "\t" << "开始时间" << "\t" << "完成时间" << "\t" << "等待时间" << "\t" << "周转时间" << std::endl;
	for (auto j : this->resjob) {
		j.printf();
		std::cout << std::endl;
	}
}