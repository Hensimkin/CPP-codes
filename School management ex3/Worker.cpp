#include"Worker.h"
Worker::Worker()//default ctor
{
	name = NULL;
	id = 0;
	seniority = 0;
}
Worker::Worker(char* name, long id, int seniority)//ctor
{
	this->name = new char[strlen(name) + 1];
	for (int i = 0; i < strlen(name)+1; i++)
	{
		this->name[i] = name[i];
	}
	this->id = id;
	this->seniority = seniority;
}
Worker::Worker(const Worker& other)//copy ctor
{
	this->name = new char[strlen(other.name) + 1];
	for (int i = 0; i < strlen(other.name)+1; i++)
	{
		this->name[i] = other.name[i];
	}
	this->id = other.id;
	this->seniority = other.seniority;
}
Worker::~Worker()//dtor
{
	delete[]name;
}
void Worker::print()const//print function
{
	cout << "Name: " << name << endl;
	cout << "Id: " << id << endl;
	cout << "Seniority: " << seniority << endl;
}
float Worker::salcalc()const
{
	return 0;
}
int Worker::getSeniority()const//retrun seniority
{
	return seniority;
}
const char* Worker::get_type()const//get type function
{
	return "Worker";
}
void Worker::printnamew()const//name print
{
	cout <<"Name: "<< name << endl;
}
long Worker::getId()const//return id function
{
	return id;
}