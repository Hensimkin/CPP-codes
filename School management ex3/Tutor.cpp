#define _CRT_SECURE_NO_WARNINGS
#include"Tutor.h"
Tutor::Tutor():Teacher()//default ctor
{
	strcpy(teachingclass, "");
}
Tutor::Tutor(char* name, long id, int seniority, int numberofsubjects, char** namesofsubjects, char* teachingclass) : Teacher(name, id, seniority, numberofsubjects, namesofsubjects)//ctor
{
	strcpy(this->teachingclass, teachingclass);
}
Tutor::Tutor(const Tutor& other) : Teacher(other)//copy ctor 
{
	strcpy(this->teachingclass, other.teachingclass);
}
Tutor::~Tutor()//dtor
{
}
float Tutor::salcalc()const//function that calculates the salaray of the tutor
{
	int sal = Teacher::salcalc();	
	return sal+1000;
}
void Tutor::print()const//print function
{
	Teacher::print();
	cout << "The class of teaching is :" << teachingclass << endl;
}
void Tutor::printt()const//function that prints the name of the teacher of the course
{
	Worker::printnamew();
	cout <<"Class: " << teachingclass << endl;
}
const char* Tutor::get_type()const//rtti function returns the type
{
	return "Tutor";
}
const char* Tutor::getclass()const//function that returns the teaching class of the tutor
{
	return teachingclass;
}