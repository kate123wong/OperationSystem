#include <string>
#include<iostream>
#include<fstream>
#include "JOB.h"
#include "FCFS.h"
#include "SJF.h"
#include "HRRN.h"
#include "RR.h"

#define MaxNumber 10
using namespace std;

int n; //从文件读入的作业数量
vector<JOB> jobArray,resjobs;

void ReadProcess(string);

int main() {
	string inputPath = "task.txt";

	// cin >> inputPath;
	 ReadProcess(inputPath);
	
	 cout << "------------------------------------------------------------ FCFS ------------------------------------------------- --------" << endl;
	 FCFS fcfs;
	 fcfs.setTime("02:40");
	 fcfs.schedule(jobArray);
	 fcfs.printSchedule();
	 cout << "------------------------------------------------------------ FCFS --------------------------------------- ------------------" << endl << endl;
	
	 cout << "------------------------------------------------------------ SJF ---------------------------------------------------------" << endl << endl;
	 SJF sjf;
	 sjf.setTime("02:40");
	 sjf.schedule(jobArray);
	 sjf.printSchedule();
	 cout << "------------------------------------------------------------ SJF --------------------------------------------------------- " << endl << endl;

	 cout << "----------------------------------------------------------- HRRN ---------------------------------------------------------" << endl;
	 HRRN hrrn;
	 hrrn.setTime("02:40");
	 hrrn.schedule(jobArray);
	 hrrn.printSchedule();
	 cout << "----------------------------------------------------------- HRRN --------------------------------------------------------- " << endl;
	 
	 cout << "------------------------------------------------------------ RR ---------------------------------------------------------" << endl;
	 RR rr;
	 rr.setTime("02:40");
	 rr.schedule(jobArray);
	 rr.printSchedule();
	 cout << "------------------------------------------------------------ RR --------------------------------------------------------- " << endl;

	 return 0;
}

void ReadProcess(string  FilePath) {

	ifstream inFile;
	inFile.open(FilePath.data());
	FilePath.length();
	inFile >> n;
	for (int i = 1; i <= n; i++) {
		int id;
		string name, submissionTime;
		int needServerTime;
		JOB tmpJob;
		inFile >> id >> name >> submissionTime >> needServerTime;
		tmpJob.setId(id);
		tmpJob.setNmae(name);
		tmpJob.setSubmissionTime(submissionTime);
		tmpJob.setNeedServerTime(needServerTime);
		jobArray.push_back(tmpJob);
	}
}
