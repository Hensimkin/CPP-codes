#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
using namespace std;
class Worker
{
private:
	char name[15];
	long id;
	double hoursalary;
	int hours;
	int extrahours;
public:
	Worker();
	Worker(char *name, long id, double hoursalary, int hours, int extrahours);
	//Worker(const Worker& other);
	//~Worker();
	void setHoursalary(double hoursalary);
	void setHours(int hours);
	void setExtrahours(int extrahours);
	char *getName();
	long getId();
	double getHoursalary();
	int getHours();
	int getExtrahours();
	double calcsaray();
	void showinfo();

};