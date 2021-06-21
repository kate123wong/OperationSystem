#include "SJF.h"
SJF::SJF() {
	while (this->job.size() != 0)
	{
		this->job.pop_back();
	}
}
SJF::~SJF() {

}
SJF::SJF(std::vector<JOB> Job) {
	this->job = Job;
}

void SJF::schedule(std::vector<JOB> Job) {

	if (this->job.size() == 0)
	this->job = Job;

	bool isRun = false; //当前是否正在运行
	while (true && day == 0) {
		if (!priority_job.empty()) {

			// 正在等待的作业的周转时间、等待时间++
			std::priority_queue<JOB, std::vector<JOB>, cmp> priority_job_tmp;
			while (!priority_job.empty()) {
				JOB tmpjob = priority_job.top();
				priority_job.pop();
				tmpjob.setWateTime(tmpjob.getWaitTime() + 1);
				tmpjob.setCycleTime(tmpjob.getCycleTime() + 1);
				priority_job_tmp.push(tmpjob);
			}
			priority_job = priority_job_tmp;
		}
		//当前正在处理的作业的周转时间++，判断作业是否完成，完成的话，开始下一个作业或者设置无正在进行的作业
		if (isRun) {
			resjob[resjob.size()-1].setCycleTime(resjob[resjob.size() - 1].getCycleTime() + 1);
			resjob[resjob.size() - 1].setRunTime(resjob[resjob.size() - 1].getRunTime() + 1);

			if (resjob[resjob.size() - 1].isFinish() && this->day == 0) {
				resjob[resjob.size() - 1].setEndTime(this->timer);
				if (!priority_job.empty()) {
					JOB tmpjob = priority_job.top();
					priority_job.pop();
					tmpjob.setStartTime(this->timer);
					resjob.push_back(tmpjob);
				}
				else if (priority_job.empty()) isRun = false; //当前最后一个作业也处理完毕，无作业可以处理
			}
		}
		
		std::vector<JOB> startjob;
		startjob = this->ComingJob(this->timer);// 将此时提交的作业加入到后备队列中
		for (auto tmpjob : startjob) {
			if (!isRun) {                      // 如果之前没有运行作业，那么现在开始运行刚刚加入的作业
				isRun = true;
				tmpjob.setStartTime(this->timer);
				resjob.push_back(tmpjob);
			}
			else priority_job.push(tmpjob);
		}

		this->timeAdd(1);						// 时间++
		if (!isRun && resjob.size() == Job.size())
		{
			return;
		}
	}
}

void SJF::printSchedule() {

	std::cout << "作业编号" << "\t" << "作业名称" << "\t" << "提交时间" << "\t"
		<< "要求服务运行时间" << "\t" << "开始时间" << "\t" << "完成时间" << "\t" << "等待时间" << "\t" << "周转时间" << "\t" << "带权周转时间" << std::endl;
	double averweightcycletime = 0, avercycletime = 0; 
	for (auto j : this->resjob) {
		j.printf();
		std::cout << std::endl;
		averweightcycletime += (1.0 * j.getCycleTime() / j.getNeedServerTime());
		avercycletime += j.getCycleTime();
	}
	std::cout << "平均带权周转时间： " << averweightcycletime / resjob.size() << std::endl;
	std::cout << "平均周转时间： " << avercycletime / resjob.size()<< std::endl;
}

