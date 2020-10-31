#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include "JOB.h"
#include "SystemOperation.h"
class RR:public SystemOperation
{
public:
	RR();
	~RR();
	virtual void schedule(std::vector<JOB>);
	void printSchedule();
private:
	std::queue<JOB> jobQueue;
	std::vector<JOB> resjob;
};

