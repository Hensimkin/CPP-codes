#pragma once
#include<iostream>
using namespace std;
class Worker;
class Student
{
private:
	char* name;
	char* id;
	int numberofcourses;
	int* gradelist;
	static int totalnumofcourses, totalsum;
public:
	Student();
	Student(char* name, char* id);
	Student(const Student& other);
	~Student();
	float averagecalc()const;
	friend ostream& operator<<(ostream& os, const Student& other);
	void operator+=(int grade);
	bool operator>(const Student& other)const;
	static float tavg();
	friend void find(Student** other1, Worker** other2, int numofstudents, int numofworkers, char* id);
	friend int best(Student** other, int numofstudents);
};