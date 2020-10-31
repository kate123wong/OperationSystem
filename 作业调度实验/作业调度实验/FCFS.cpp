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

	int curJob = -1;//��ǰ�����е�job��jobQueue�е��±ꡣ
	bool isRun = false; //��ǰ�Ƿ���������
	while (true && day == 0) {
		if (!isRun && curJob == this->job.size())
		{
			return;
		}
		if (!jobQueue.empty()) {

			// ���ڵȴ�����ҵ����תʱ�䡢�ȴ�ʱ��++
			for (int i = curJob + 1; i < jobQueue.size(); i++) {
				jobQueue[i].setWateTime(jobQueue[i].getWaitTime() + 1);
				jobQueue[i].setCycleTime(jobQueue[i].getCycleTime() + 1);
			}

			//��ǰ���ڴ������ҵ����תʱ��++���ж���ҵ�Ƿ���ɣ���ɵĻ�����ʼ��һ����ҵ�������������ڽ��е���ҵ
			if (isRun) {
				jobQueue[curJob].setCycleTime(jobQueue[curJob].getCycleTime() + 1);
				jobQueue[curJob].setRunTime(jobQueue[curJob].getRunTime() + 1);
				if (jobQueue[curJob].isFinish() && this->day == 0) {
					jobQueue[curJob].setEndTime(this->timer);
					if (curJob + 1 < jobQueue.size()) {
						curJob++;
						jobQueue[curJob].setStartTime(this->timer);
					}
					else if (curJob + 1 == jobQueue.size()) isRun = false; //��ǰ���һ����ҵҲ������ϣ�����ҵ���Դ���
				}
			}
		}

		std::vector<JOB> startjob;
		startjob = this->ComingJob(this->timer);// ����ʱ�ύ����ҵ���뵽�󱸶�����
		for (auto tmpjob : startjob) {
			jobQueue.push_back(tmpjob);
			if (!isRun) {                      // ���֮ǰû��������ҵ����ô���ڿ�ʼ���иոռ������ҵ
				 curJob = jobQueue.size() - 1;
				isRun = true;
				jobQueue[curJob].setStartTime(this->timer);
			}
		}

		this->timeAdd(1);						// ʱ��++
	}
}
void FCFS::printSchedule() {

	std::cout << "��ҵ���" << "\t" << "��ҵ����" << "\t" << "�ύʱ��" << "\t"
		<< "Ҫ���������ʱ��" << "\t" << "��ʼʱ��" << "\t" << "���ʱ��" << "\t" << "�ȴ�ʱ��" << "\t" << "��תʱ��" << std::endl;
	for (auto j : this->jobQueue) {
		j.printf();
		std::cout << std::endl;
	}
}
