#include"Student.h"
Student::Student()//default ctor
{
	name = NULL;
	id = NULL;
	numberofcourses = 0;
	gradelist = NULL;
}
Student::Student(char* name, char* id)//parameter ctor gets only name and id
{
	int temp1 = strlen(name);
	int temp2 = strlen(id);
	this->name = new char[temp1+1];
	for (int i= 0; i < temp1+1; i++)
	{
		this->name[i] = name[i];
	}
	this->id = new char[temp2+1];
	for (int i = 0; i < temp2+1; i++)
	{
		this->id[i] = id[i];
	}
	numberofcourses = 0;
	gradelist = NULL;	
}
Student::Student(const Student& other)//copy ctor copies the other object to the current object
{
	int temp1 = strlen(other.name);
	int temp2 = strlen(other.id);
	this->name = new char[temp1+1];
	for (int i = 0; i < temp1+1; i++)
	{
		this->name[i] = other.name[i];
	}
	this->id = new char[temp2+1];
	for (int i = 0; i < temp2+1; i++)
	{
		this->id[i] = other.id[i];
	}
	numberofcourses = other.numberofcourses;
	gradelist = new int[numberofcourses];
	for (int i = 0; i < numberofcourses; i++)
	{
		gradelist[i] = other.gradelist[i];
	}
	totalnumofcourses = totalnumofcourses + other.numberofcourses;
	int temp = 0;
	for (int i = 0; i < other.numberofcourses; i++)
	{
		temp = temp + other.gradelist[i];
	}
	totalsum = totalsum + temp;
}
Student::~Student()//dtor frees all arrays in the class
{
	delete[]name;
	delete[]id;
	delete[]gradelist;
}
float Student::averagecalc()const//function that calcs the avarage  of the student grades
{
	if (numberofcourses == 0)
	{
		return 0;
	}
	else
	{
		float temp = 0;
		for (int i = 0; i < numberofcourses; i++)
		{
			temp = temp + gradelist[i];
		}
		float avarage = temp / numberofcourses;
		return avarage;
	}
}
ostream& operator<<(ostream& os, const Student& other)//print operator prints all data of the class
{
	os << "Name: ";
	for (int i = 0; i < strlen(other.name); i++)
	{
		os << other.name[i];
	}
	os << endl;
	os << "ID: ";
	for (int i = 0; i < strlen(other.id); i++)
	{
		os << other.id[i];
	}
	os << endl;
	os << "Number of courses: " << other.numberofcourses << endl;
	os << "Grade list: ";
	for (int i = 0; i < other.numberofcourses; i++)
	{
		os << other.gradelist[i] << " ";
	}
	os << endl;
	os << "Avarage: " << other.averagecalc() << endl;
	return os;
}
void Student::operator+=(int grade)//operator += adds a grade to the class and increases the grade array
{
	if (grade < 0 || grade>100)
	{
		cout << "Wrong grade" << endl;
	}
	else
	{
		if (numberofcourses == 0)
		{
			numberofcourses++;
			gradelist = new int[numberofcourses];
			gradelist[0] = grade;
			totalnumofcourses++;
			totalsum = totalsum + gradelist[numberofcourses - 1];
			//return *this;
		}
		else
		{
			int* temp = new int[numberofcourses + 1];
			for (int i = 0; i < numberofcourses; i++)
			{
				temp[i] = gradelist[i];
			}
			temp[numberofcourses] = grade;
			delete[]gradelist;
			numberofcourses++;
			gradelist = new int[numberofcourses];
			for (int i = 0; i < numberofcourses; i++)
			{
				gradelist[i] = temp[i];
			}
			totalnumofcourses++;
			totalsum = totalsum + gradelist[numberofcourses - 1];
			//return *this;
		}
	}	
}
bool Student::operator>(const Student& other)const//> operator return true or false  if the object is avrage than the other avarage
{
	if (averagecalc() > other.averagecalc())
	{
		return true;
	}
	else
	{
		return false;
	}
}
float Student::tavg()//static functions that returns the total avarage of the total courses
{
	return totalsum / totalnumofcourses;
}
