#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class JOB
{
public:
	JOB();
	~JOB();

	void manage();
	void printf();

	void setId(const int);
	void setNmae(const std::string);
	void setSubmissionTime(const std::string);
	void setNeedServerTime(const int);
	void setStartTime(const std::string);
	void setEndTime(const std::string);
	void setWateTime(const int);
	void setCycleTime(const int);

	std::string getStartTime()const;
	std::string getSubmissionTime()const;
	int getNeedServerTime() const;
	int getCycleTime()const;
	int getWaitTime()const;
	bool isFinish()const;

private:
	int id;
	std::string name;
	std::string submissionTime;
	std::string startTime;
	std::string endTime;

	int needServerTime;
	int wateTime;//等待时间(秒数)
	int cycleTime;//周转时间(秒数);
};

