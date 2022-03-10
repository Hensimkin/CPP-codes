#define _CRT_SECURE_NO_WARNINGS
#include"Teacher.h"
Teacher::Teacher():Worker()//defualt ctor
{
	numberofsubjects = 0;
	listsofsubjects = NULL;
}
Teacher::Teacher(char* name, long id, int seniority, int numberofsubjects, char** listsofsubjects) : Worker(name, id, seniority)//ctor
{
	this->numberofsubjects = numberofsubjects;
	this->listsofsubjects = new char* [numberofsubjects];
	for (int i = 0; i < this->numberofsubjects; i++)
	{
		this->listsofsubjects[i] = new char[10];
		for (int j = 0; j < 10; j++)
		{
			this->listsofsubjects[i][j] = listsofsubjects[i][j];
		}
	}
}
Teacher::Teacher(const Teacher& other) :Worker(other)//copy ctor
{
	numberofsubjects = other.numberofsubjects;
	listsofsubjects = new char* [numberofsubjects];
	for (int i = 0; i < this->numberofsubjects; i++)
	{
		listsofsubjects[i] = new char[10];
		for (int j = 0; j < 10; j++)
		{
			listsofsubjects[i][j] = other.listsofsubjects[i][j];
		}
	}
}
Teacher::~Teacher()//dtor
{
	for (int i = 0; i < numberofsubjects; i++)
	{
		delete listsofsubjects[i];
	}
	delete[]listsofsubjects;
}
void Teacher::print()const//print function
{
	Worker::print();
	cout << "Number of courses of teaching: " << numberofsubjects << endl;
	for (int i = 0; i < numberofsubjects; i++)
	{
		cout << "Subject number " << i+1 <<": " << listsofsubjects[i] << endl;
	}
	cout << "Salary is: " << salcalc() << endl;
}
float Teacher::salcalc()const//function that calculates the salray
{
	int sal = 5000;
	int temp = Worker::getSeniority() * 500;
	int temp2 = 300 * numberofsubjects;
	return sal + temp + temp2;
 }
int Teacher::getNumofsubjects()const
{
	return numberofsubjects;
}

const char* Teacher::get_type()const//rtti function returns type
{
	return "Teacher";
}
void Teacher::nameprint(char* course)const//function with a connection to the function in the menu
{
	for (int i = 0; i < numberofsubjects; i++)
	{
		if (strcmp(course, listsofsubjects[i]) == 0)
		{
			Worker::printnamew();
		}
	}
}