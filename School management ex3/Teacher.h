#pragma once
#include"Worker.h"
class Teacher:public Worker
{
private:
	int numberofsubjects;
	char** listsofsubjects;
public:
	Teacher();
	Teacher(char* name, long id, int seniority, int numberofsubjects, char** namesofsubjects);
	Teacher(const Teacher& other);
	virtual ~Teacher();
	virtual void print()const;
	virtual float salcalc()const;
	int getNumofsubjects()const;
	virtual const char* get_type()const;
	void nameprint(char *course)const;
};