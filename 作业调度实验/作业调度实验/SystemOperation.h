#pragma once
#include <string>
#include <vector>
#include "JOB.h"
class SystemOperation
{
public:
	SystemOperation();
	~SystemOperation();
	void setTime(std::string);
	virtual void schedule(std::vector<JOB>) = 0;
	void printSchedule();
	std::vector<JOB> ComingJob(const std::string);
	void timeAdd(int);
protected:
	std::vector<JOB> job;
	std::string timer;
	int min;
	int hour;
	int day;
};

