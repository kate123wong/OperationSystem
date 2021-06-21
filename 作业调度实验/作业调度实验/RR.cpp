#include "RR.h"
RR::RR() {

}
RR::~RR() {

}
void RR::schedule(std::vector<JOB> Job) {
	if (this->job.size() == 0)
		this->job = Job;

	bool isRun = false; //��ǰ�Ƿ���������
	while (true && day == 0) {
		if (!jobQueue.empty()) {

			// ���׵���ҵִ��һ��ʱ��Ƭ
			JOB topjob = jobQueue.front();
			jobQueue.pop();
			if (topjob.getStartTime() == "00:00") {
				topjob.setStartTime(this->timer);
			}
			topjob.setRunTime(topjob.getRunTime() + 1);
			topjob.setCycleTime(topjob.getCycleTime() + 1);

			// û�����е���ҵ�ȴ�ʱ�����תʱ���һ��ʱ��Ƭ
			int length = jobQueue.size() , cur = 0;
			while (cur++ < length) {
				JOB tmpJob = jobQueue.front();
				jobQueue.pop();
				tmpJob.setCycleTime(tmpJob.getCycleTime() + 1);
				tmpJob.setWateTime(tmpJob.getWaitTime() + 1);
				jobQueue.push(tmpJob);
			}
			//�ж϶�����ҵ�Ƿ��ǿ�
			if (topjob.isFinish()) {
				topjob.setEndTime(this->timer);
				resjob.push_back(topjob);
			}
			else {
				jobQueue.push(topjob);
			}
		}
		std::vector<JOB> startjob;
		startjob = this->ComingJob(this->timer);// ����ʱ�ύ����ҵ���뵽�󱸶�����
		for (auto tmpjob : startjob) {
			jobQueue.push(tmpjob);
		}

		this->timeAdd(1);						// ʱ��++
		if (!isRun && resjob.size() == Job.size())
		{
			return;
		}
	}
}

void RR::printSchedule() {
	std::cout << "��ҵ���" << "\t" << "��ҵ����" << "\t" << "�ύʱ��" << "\t"
		<< "Ҫ���������ʱ��" << "\t" << "��ʼʱ��" << "\t" << "���ʱ��" << "\t" << "�ȴ�ʱ��" << "\t" << "��תʱ��" << "\t" << "��Ȩ��תʱ��" << std::endl;
	double averweightcycletime = 0, avercycletime = 0;
	for (auto j : this->resjob) {
		j.printf();
		std::cout << std::endl;
		averweightcycletime += (1.0 * j.getCycleTime() / j.getNeedServerTime());
		avercycletime += 1.0 * j.getCycleTime();
	}
	std::cout << "ƽ����Ȩ��תʱ�䣺 " << averweightcycletime / resjob.size() << std::endl;
	std::cout << "ƽ����תʱ�䣺 " << 1.0 * avercycletime / resjob.size() << std::endl;
}