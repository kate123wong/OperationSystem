#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include "JOB.h"
#include "SystemOperation.h"
class HRRN:public SystemOperation
{
public:
	HRRN();
	HRRN(std::vector<JOB>);
	~HRRN();

	virtual void schedule(std::vector<JOB>);
	void printSchedule();
	struct cmp {
		bool operator()(const JOB& a, const JOB& b) {
			return a.getResponseRatio() < b.getResponseRatio();
		}
	};
private:
	std::priority_queue<JOB, std::vector<JOB>, cmp> priority_job;
	std::vector<JOB> resjob;
};

