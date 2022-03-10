#include "Temp.h"
Temp::Temp():Teacher()//defualt ctor
{
	weaklyhours = 0;
}
Temp::Temp(char* name, long id, int seniority, int numberofsubjects, char** namesofsubjects, int weaklyhours) : Teacher(name, id, seniority, numberofsubjects, namesofsubjects)//ctor
{
	this->weaklyhours = weaklyhours;
}
Temp::Temp(const Temp& other) : Teacher(other)//copy ctor
{
	weaklyhours = other.weaklyhours;
}
Temp::~Temp()//dtor
{
}
void Temp::print()const//print function
{
	Teacher::print();
	cout << "Weakly hours: " << weaklyhours << endl;
}
float Temp::salcalc()const//salary calc function
{
	if (Worker::getSeniority() > 5 && weaklyhours > 10)
	{
		return weaklyhours * 300 + 700;
	}
	else
	{
		return weaklyhours * 300;
	}
}
const char* Temp::get_type()const//rtti type function
{
	return "Temp";
}