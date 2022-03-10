#pragma once
#include<iostream>
using namespace std;
class Worker
{
private:
	char* name;
	long id;
	int seniority;
public:
	Worker();
	Worker(char* name, long id, int seniority);
	Worker(const Worker& other);
	virtual ~Worker();
	virtual void print()const;
	virtual float salcalc()const;
	int getSeniority()const;
	virtual const char* get_type()const;
	void printnamew()const;
	long getId()const;
};