#pragma once
#include <iostream>
using namespace std;
class Student;
class Worker
{
private:
	char* name;
	char* id;
	float salary;
	static int totalworkers;
	static float totalsal;
public:
	Worker();
	Worker(char* name, char* id, float salary);
	Worker(const Worker& other);
	~Worker();
	friend ostream& operator<<(ostream& os, const Worker& other);
	void operator+=(int bonus);
	void operator*=(float percent);
	bool operator>(const Worker& other)const;
	static float totalsalavg();
	friend void find(Student** other2, Worker** other1, int numofstudents, int numofworkers, char* id);
	friend int rich(Worker** other, int numofworkers);

};