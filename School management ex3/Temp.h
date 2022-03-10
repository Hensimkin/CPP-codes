#pragma once
#include"Teacher.h"
class Temp:public Teacher
{
private:
	int weaklyhours;
public:
	Temp();
	Temp(char* name, long id, int seniority, int numberofsubjects, char** namesofsubjects, int weaklyhours);
	Temp(const Temp& other);
	virtual ~Temp();
	virtual void print()const;
	virtual float salcalc()const;
	virtual const char* get_type()const;
	
};