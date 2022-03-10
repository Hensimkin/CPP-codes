#pragma once
#include"Deputy.h"
#include"Temp.h"
#include"Secretary.h"
#include"Manager.h"
class School
{
private:
	int numofworkers;
	Worker** listofworkers;
	bool manager;
public:
	School();
	~School();
	int Menu();
	void operator+(Worker *worker);
};