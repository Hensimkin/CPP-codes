#pragma once
#include"Worker.h"
class Manager:public Worker
{
public:
	Manager();
	Manager(char* name, long id, int seniority);
	Manager(const Manager& other);
	virtual ~Manager();
	virtual void print()const;
	virtual float salcalc()const;
	virtual const char* get_type()const;
};