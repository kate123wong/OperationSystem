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

	std::cout << "��ҵ���" << "��ҵ����" << "�ύʱ��" << "Ҫ���������ʱ��" << "��ʼʱ��" << "���ʱ��" << "�ȴ�ʱ��" << "��תʱ��" << std::endl;
	for (auto j : this->job) {
		j.printf();
	}
}