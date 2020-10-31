#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include "JOB.h"
#include "SystemOperation.h"
class SJF:public SystemOperation
{
public:
	SJF();
	SJF(std::vector<JOB>);
	~SJF();

	virtual void schedule(std::vector<JOB>);
	void printSchedule();
	struct cmp {
		bool operator()(const JOB& a, const JOB& b) {
			return a.getNeedServerTime() > b.getNeedServerTime();
		}
	};
	
private:

	std::priority_queue<JOB,std::vector<JOB>,cmp> priority_job; //时间较短的在优先队列的前面
	std::vector<JOB> resjob;
};
