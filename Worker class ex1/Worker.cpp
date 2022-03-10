#include"Worker.h"
Worker::Worker()//default ctor
{
	char name2[15] = "noname";
	strcpy(this->name, name2);	
	this->hours = 0;
	this->hoursalary = 0;
	this->id = 0;
	this->extrahours = 0;
}


Worker::Worker(char* name, long id, double hoursalary, int hours, int extrahours)//parameter ctor, gets all parameters
{
	this->hours = hours;
	if (this->hours < 0)
	{
		while (this->hours < 0)
		{
			cout << "please enter again hours" << endl;
			cin >> this->hours;
		}
	}
	this->hoursalary = hoursalary;
	if (this->hoursalary < 0)
	{
		while (this->hoursalary < 0)
		{
			cout << "please enter again hourly salary" << endl;
			cin >> this->hoursalary;
		}
	}
	this->id = id;
	this->extrahours = extrahours;
	if (this->extrahours < 0)
	{
		while (this->extrahours < 0)
		{
			cout << "please enter again extra hours" << endl;
			cin >> this->extrahours;
		}
	}
	strcpy(this->name, name);
}


 char* Worker::getName()//get function , returns the name
{
	return this->name;
}


long Worker::getId()//get function , returns the id
{
	return this->id;
}


double Worker::getHoursalary()//get functions , return the salary
{
	return this->hoursalary;
}


int Worker::getHours()//get functions , return the hours
{
	return this->hours;
}


int Worker::getExtrahours()//get function , returns the hours
{
	return this->extrahours;
}


void Worker::setHoursalary(double hoursalary)//set function , set the salary. it checks if the salary is above 0 if its not it repairs it 
{
	if (hoursalary > 0)
	{
		this->hoursalary = hoursalary;
	}
	else
	{
		this->hoursalary = hoursalary;
		while (this->hoursalary < 0)
		{
			cout << "please enter again hourly salary" << endl;
			cin >> this->hoursalary;
		}		
	}
}


void Worker::setHours(int hours)//set function , set the hours. it checks if the hours is above 0 if its not it repairs it
{
	if (hours > 0)
	{
		this->hours = hours;
	}
	else
	{
		this->hours = hours;
		while (this->hours < 0)
		{
			cout << "please enter again hours" << endl;
			cin >> this->hours;
		}
	}
}


void Worker::setExtrahours(int extrahours)//set function , set the extrahours. it checks if the extrahours is above 0 if its not it repairs it
{
	if (extrahours > 0)
	{
		this->extrahours = extrahours;
	}
	else
	{
		this->extrahours = extrahours;
		while (this->extrahours < 0)
		{
			cout << "please enter again extra hours" << endl;
			cin >> this->extrahours;
		}
	}
}


double Worker::calcsaray()//the function calcs the salary with the hours and extra hours in total
{
	double tsalary = (hoursalary * hours) + (1.5 * extrahours * hoursalary);
	return tsalary;
}


void Worker::showinfo()//the function prints the worker bio
{
	cout << "worker's name is: " << name << endl;
	cout << "worker's id is: " << id << endl;
	cout << "worker's hour salary is: " << hoursalary << endl;
	cout << "worker's monthly hours are: " << hours << endl;
	cout << "worker's extra hours are: " << extrahours << endl;
	double tsalary = (hoursalary * hours) + (1.5 * extrahours * hoursalary);
	cout <<fixed<<setprecision(2)<< "worker's salary is: " << tsalary << endl;
	cout << endl;
}