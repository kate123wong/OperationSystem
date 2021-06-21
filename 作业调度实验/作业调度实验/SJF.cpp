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

	bool isRun = false; //��ǰ�Ƿ���������
	while (true && day == 0) {
		if (!priority_job.empty()) {

			// ���ڵȴ�����ҵ����תʱ�䡢�ȴ�ʱ��++
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
		//��ǰ���ڴ������ҵ����תʱ��++���ж���ҵ�Ƿ���ɣ���ɵĻ�����ʼ��һ����ҵ�������������ڽ��е���ҵ
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
				else if (priority_job.empty()) isRun = false; //��ǰ���һ����ҵҲ������ϣ�����ҵ���Դ���
			}
		}
		
		std::vector<JOB> startjob;
		startjob = this->ComingJob(this->timer);// ����ʱ�ύ����ҵ���뵽�󱸶�����
		for (auto tmpjob : startjob) {
			if (!isRun) {                      // ���֮ǰû��������ҵ����ô���ڿ�ʼ���иոռ������ҵ
				isRun = true;
				tmpjob.setStartTime(this->timer);
				resjob.push_back(tmpjob);
			}
			else priority_job.push(tmpjob);
		}

		this->timeAdd(1);						// ʱ��++
		if (!isRun && resjob.size() == Job.size())
		{
			return;
		}
	}
}

void SJF::printSchedule() {

	std::cout << "��ҵ���" << "\t" << "��ҵ����" << "\t" << "�ύʱ��" << "\t"
		<< "Ҫ���������ʱ��" << "\t" << "��ʼʱ��" << "\t" << "���ʱ��" << "\t" << "�ȴ�ʱ��" << "\t" << "��תʱ��" << "\t" << "��Ȩ��תʱ��" << std::endl;
	double averweightcycletime = 0, avercycletime = 0; 
	for (auto j : this->resjob) {
		j.printf();
		std::cout << std::endl;
		averweightcycletime += (1.0 * j.getCycleTime() / j.getNeedServerTime());
		avercycletime += j.getCycleTime();
	}
	std::cout << "ƽ����Ȩ��תʱ�䣺 " << averweightcycletime / resjob.size() << std::endl;
	std::cout << "ƽ����תʱ�䣺 " << avercycletime / resjob.size()<< std::endl;
}

