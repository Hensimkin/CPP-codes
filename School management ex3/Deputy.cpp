#include"Deputy.h"
Deputy::Deputy():Tutor()//default ctor
{

}
Deputy::Deputy(char* name, long id, int seniority, int numberofsubjects, char** namesofsubjects, char* teachingclass) : Tutor(name, id, seniority, numberofsubjects, namesofsubjects, teachingclass)//ctor
{

}
Deputy::Deputy(const Tutor& other) : Tutor(other)//copy ctor
{

}
Deputy::~Deputy()//dtor
{

}
float Deputy::salcalc()const//salary function calc
{
	int sal = 2500 + Tutor::salcalc();
	return sal;
}
void Deputy::print()const//print function
{
	Tutor::print();
}
const char*  Deputy:: get_type()const//rtti function
{
	return "Deputy";
}