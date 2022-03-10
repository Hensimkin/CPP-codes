#pragma once
#include "Tutor.h"
class Deputy:public Tutor
{
public:
	Deputy();
	Deputy(char* name, long id, int seniority, int numberofsubjects, char** namesofsubjects, char* teachingclass);
	Deputy(const Tutor& other);
	virtual ~Deputy();
	virtual void print()const;
	virtual float salcalc()const;
	virtual const char* get_type()const;
};