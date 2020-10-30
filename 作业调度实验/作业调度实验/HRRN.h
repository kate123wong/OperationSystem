#pragma once
#include <vector>
#include <iostream>
#include "JOB.h"
class HRRN
{
public:
	HRRN();
	HRRN(std::vector<JOB>);
	~HRRN();

	void schedule(std::vector<JOB>);
	void printSchedule();
private:
	std::vector<JOB> job;
};

