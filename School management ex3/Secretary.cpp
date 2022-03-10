#include"Secretary.h"
Secretary::Secretary() :Worker()//default ctor
{
	extrahours = 0;
}
Secretary::Secretary(char* name, long id, int seniority, int extrahours) : Worker(name, id, seniority)//ctor
{
	this->extrahours = extrahours;
}
Secretary::Secretary(const Secretary& other) : Worker(other)//copy ctor
{
	extrahours = other.extrahours;
}
Secretary:: ~Secretary()//dtor
{
}
void Secretary::print()const//print function
{
	Worker::print();
	cout << "Salary is: " << salcalc() << endl;
}
float Secretary::salcalc()const//salaray calc function
{
	return 5000 + 200 * Worker::getSeniority() + 60 * extrahours;
}
const char* Secretary::get_type()const//rtti function
{
	return "Secretary";
}