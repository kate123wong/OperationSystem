#include "SystemOperation.h"
SystemOperation::SystemOperation() {
	this->day = 0;
	this->hour = 0;
	this->min = 0;
}
SystemOperation::~SystemOperation() {

}
void SystemOperation::printSchedule() {
	std::cout << "作业编号" <<"\t" << "作业名称" << "\t" << "提交时间" << "\t" 
		<< "要求服务运行时间" << "\t" << "开始时间" << "\t" << "完成时间" << "\t" << "等待时间" << "\t" << "周转时间" << std::endl;
	for (auto j : this->job) {
		j.printf();
	}
}
void SystemOperation::setTime(std::string time) {
	this->timer = time;
	std::string tmp = this->timer;
	this->hour = 0, this->min = 0;
	int flag = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == ':') {
			flag = 1;
			continue;
		}
		if (!flag) {
			hour = hour * 10 + (tmp[i] - '0');
		}
		else {
			min = min * 10 + (tmp[i] - '0');
		}
	}
	return;
}

void SystemOperation::timeAdd(int t) {
	std::string tmp = "";

	if (min + t < 60) {
		min += t;
	}
	else {
		min = min + t - 60;
		hour++;
		if (hour > 24) {
			hour -= 24;
			this->day++;
		}
	}

	tmp += (hour / 10) + '0';
	tmp += (hour % 10) + '0';
	tmp += ":";
	tmp += (min / 10) + '0';
	tmp += (min % 10) + '0';

	this->timer = tmp;
}

