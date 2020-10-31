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
	void setWateTime(const double);
	void setCycleTime(const double);
	void setRunTime(const double);
	void updataResponseRatio();


	std::string getStartTime()const;
	std::string getSubmissionTime()const;
	double getNeedServerTime() const;
	double getCycleTime()const;
	double getWaitTime()const;
	bool isFinish()const;
	double getResponseRatio()const;
	double getRunTime() const;

private:
	int id;
	std::string name;
	std::string submissionTime;
	std::string startTime;
	std::string endTime;
	double responseRatio; //响应比

	double needServerTime;
	double wateTime;//等待时间(秒数)
	double cycleTime;//周转时间(秒数);
	double runTime;

	void stringTomin_sec(std::string const t, const int& min, const int& sec);
};

