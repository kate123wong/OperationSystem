#include "JOB.h"
 JOB::JOB() {
	 this->wateTime = 0;
	 this->cycleTime = 0;
}

 JOB::~JOB() {

}
void JOB::manage() {

}

void JOB::printf() {
	std::cout  << this->id << "\t\t " << this->name << "  \t" <<std::setw(2) << std::setfill('0')
		<< "\t\t" << this->submissionTime 
		<< "\t\t" << this->needServerTime
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
void JOB::setWateTime(const int wt) {
	this->wateTime = wt;
}
void JOB::setCycleTime(const int ct) {
	this->cycleTime = ct;
}

std::string JOB::getStartTime() const {
	return this->startTime;
}

int JOB::getCycleTime() const {
	return this->cycleTime;
}

int JOB::getWaitTime() const {
	return this->wateTime;
}
bool JOB::isFinish() const {
	return this->needServerTime == this->cycleTime - this->wateTime;
}

std::string JOB::getSubmissionTime()const {
	return this->submissionTime;
}
int JOB::getNeedServerTime() const {
	return this->needServerTime;
}