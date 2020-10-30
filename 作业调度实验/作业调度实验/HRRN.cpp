#include "HRRN.h"
HRRN::HRRN() {
	while (this->job.size() != 0)
	{
		this->job.pop_back();
	}
}
HRRN::~HRRN() {

}
HRRN::HRRN(std::vector<JOB> Job) {
	this->job = Job;
}

void HRRN::schedule(std::vector<JOB> Job) {
	if (this->job.size() == 0);
	this->job = Job;
}

void HRRN::printSchedule() {

	std::cout << "作业编号" << "作业名称" << "提交时间" << "要求服务运行时间" << "开始时间" << "完成时间" << "等待时间" << "周转时间" << std::endl;
	for (auto j : this->job) {
		j.printf();
	}
}