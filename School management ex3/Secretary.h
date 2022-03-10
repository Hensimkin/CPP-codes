#pragma once
#include"Worker.h"
class Secretary:public Worker
{
private:
	int extrahours;
public:
	Secretary();
	Secretary(char* name, long id, int seniority, int extrahours);
	Secretary(const Secretary& other);
	virtual ~Secretary();
	virtual void print()const;
	virtual float salcalc()const;
	virtual const char* get_type()const;
};