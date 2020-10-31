#include "JOB.h"
 JOB::JOB() {
	 this->wateTime = 0;
	 this->cycleTime = 0;
	 this->responseRatio = 1;
	 this->runTime = 0;
}

 JOB::~JOB() {

}
void JOB::manage() {

}

void JOB::printf() {
	std::cout  << this->id << "\t\t " << this->name << "  \t" <<std::setw(2) << std::setfill('0')
		<< "\t  " << this->submissionTime 
		<< "  \t\t" << this->needServerTime
		<< "\t\t" << this->startTime
		<< "\t\t" << this->endTime 
		<< "\t\t" << this->wateTime 
		<< "\t\t" << this->cycleTime << std::endl;
}

void JOB::setId(const int id) {
	this->id = id;
}
void JOB::setNmae(const std::string nm) {
	this->name = nm;
}
void JOB::setSubmissionTime(const std::string smt) {
	this->submissionTime = smt;
}
void JOB::setNeedServerTime(const int nt) {
	this->needServerTime = nt;
}
void JOB::setStartTime(const std::string st) {
	this->startTime = st;
}
void JOB::setEndTime(const std::string ent) {
	this->endTime = ent;
}
void JOB::setWateTime(const double wt) {
	this->wateTime = wt;
}
void JOB::setCycleTime(const double ct) {
	this->cycleTime = ct;
}
void JOB::setRunTime(const double rt) {
	this->runTime = rt;
}
void JOB::updataResponseRatio() {
	this->responseRatio = 1.0 * ((double)this->wateTime + this->needServerTime) / this->needServerTime;
}
std::string JOB::getStartTime() const {
	return this->startTime;
}

double JOB::getCycleTime() const {
	return this->cycleTime;
}

double JOB::getWaitTime() const {
	return this->wateTime;
}
bool JOB::isFinish() const {
	return this->runTime >= this->needServerTime;
}

std::string JOB::getSubmissionTime()const {
	return this->submissionTime;
}
double JOB::getNeedServerTime() const {
	return this->needServerTime;
}
double JOB::getResponseRatio() const {
	return this->responseRatio;
}
double JOB::getRunTime() const {
	return this->runTime;
}