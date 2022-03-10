#include"Worker.h"
#include "Student.h"
Worker::Worker()//defualt ctor
{
	this->name = NULL;
	this->id = NULL;
	this->salary = 0;
	this->totalworkers++;
}
Worker::Worker(char* name, char* id, float salary)//parameter ctor
{
	int temp1 = strlen(name);
	int temp2 = strlen(id);
	this->name = new char[temp1 + 1];
	for (int i = 0; i < temp1 + 1; i++)
	{
		this->name[i] = name[i];
	}
	this->id = new char[temp2 + 1];
	for (int i = 0; i < temp2 + 1; i++)
	{
		this->id[i] = id[i];
	}
	this->salary = salary;
	totalworkers++;
	totalsal = totalsal + this->salary;
}
Worker::Worker(const Worker& other)//copy ctor
{
	int temp1 = strlen(other.name);
	int temp2 = strlen(other.id);
	this->name = new char[temp1 + 1];
	for (int i = 0; i < temp1 + 1; i++)
	{
		this->name[i] = other.name[i];
	}
	this->id = new char[temp2 + 1];
	for (int i = 0; i < temp2 + 1; i++)
	{
		this->id[i] = other.id[i];
	}
	this->salary = other.salary;
	totalworkers++;
	totalsal = totalsal + this->salary;
}
Worker::~Worker()//dtor
{
	delete[]this->name;
	delete[]this->id;
}
ostream& operator<<(ostream& os, const Worker& other)//print operator prints all data of the worker
{
	cout << "Name: ";
	for (int i = 0; i < strlen(other.name); i++)
	{
		os << other.name[i];
	}
	cout << endl;
	cout << "Id: ";
	for (int i = 0; i < strlen(other.id); i++)
	{
		os << other.id[i];
	}
	cout << endl;
	cout << "salary: " << other.salary << endl;
	return os;
}
void Worker::operator+=(int bonus)//+=  operator add amount of money to the worker
{
	if (bonus < 0)
	{
		while (bonus < 0)
		{
			cout << "wrong number enter again" << endl;
			cin >> bonus;
		}
	}
	else
	{
		this->salary = this->salary + bonus;
		totalsal = totalsal + bonus;
	}
}
void Worker::operator*=(float percent)//*= opertator multiplaies the salaray with the percent and adds it to the salary
{
	if (percent < 0)
	{
		while (percent < 0)
		{
			cout << "wrong number enter again" << endl;
			cin >> percent;
		}
	}
	else
	{
		float temp = salary * percent;
		this->salary = this->salary + temp;
		totalsal = totalsal + temp;
	}
}
bool Worker::operator>(const Worker& other)const//> operator return true or false  if the object is bigger than the other object
{
	if (this->salary > other.salary)
	{
		return true;
	}
	else
	{
		return false;
	}
}
float Worker::totalsalavg()//static function returns the avrage salary of all workers
{
	return totalsal / totalworkers;
}
