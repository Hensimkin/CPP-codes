#include"Manager.h"
Manager::Manager() :Worker()//default ctor
{
}
Manager::Manager(char* name, long id, int seniority) : Worker(name, id, seniority)//ctor
{
}
Manager::Manager(const Manager& other) : Worker(other)//copy ctor
{
}
Manager::~Manager()//dtor
{
}
void Manager::print()const//print function
{
	Worker::print();
	cout << "Salary is: " << salcalc() << endl;
}
float Manager::salcalc()const//salary calc function
{
	return 10000 + Worker::getSeniority() * 800;
}
const char* Manager::get_type()const//rtti function
{
	return "Manager";
}