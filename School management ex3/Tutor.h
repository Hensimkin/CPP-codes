#pragma once
#include"Teacher.h"
class Tutor:public Teacher
{
private:
	char teachingclass[3];
public:
	Tutor();
	Tutor(char* name, long id, int seniority, int numberofsubjects, char** namesofsubjects, char* teachingclass);
	Tutor(const Tutor& other);
	virtual ~Tutor();
	virtual void print()const;
	virtual float salcalc()const;
	void printt()const;
	virtual const char* get_type()const;
	const char* getclass()const;
};