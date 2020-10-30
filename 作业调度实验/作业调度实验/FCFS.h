#pragma once
#include <vector>
#include <queue>
#include <iostream>
#include "JOB.h"
#include "SystemOperation.h"
class FCFS :public SystemOperation
{
public:
	FCFS();
	FCFS(std::vector<JOB>);
	~FCFS();
	virtual void schedule(std::vector<JOB>);
	virtual std::vector<JOB> ComingJob(const std::string);
	void printSchedule();
private:
	std::vector<JOB> jobQueue;
};