
#include"Student.h"
#include"Worker.h"
int Student::totalnumofcourses = 0, Student::totalsum = 0, Worker::totalworkers = 0;
float Worker::totalsal = 0;


void find(Student** other1, Worker** other2, int numofstudents, int numofworkers, char* id)//find functions gets an id and searches if there is a person same id
{
	int count;
	int pcounter=0;
	cout << "Student list: " << endl;
	for (int i = 0; i < numofstudents; i++)
	{
		count = 0;
		for (int h = 0; h < 9; h++)
		{
			if (other1[i][0].id[h] == id[h])
			{
				count++;
			}
		}
		if (count == 9)
		{
			pcounter++;
			cout << endl;
			cout << other1[i][0] << endl;
		}
	}
	if (pcounter == 0)
	{
		cout << "there is no one on the list" << endl;
	}
	pcounter = 0;
	cout << "Worker list: " << endl;
	for (int i = 0; i < numofworkers; i++)
	{
		count = 0;
		for (int h = 0; h < 9; h++)
		{
			if (other2[i][0].id[h] == id[h])
			{
				count++;
			}
		}
		if (count == 9)
		{
			pcounter++;
			cout << endl;
			cout << other2[i][0] << endl;
		}		
	}
	if (pcounter == 0)
	{
		cout << "there is no one on the list" << endl;
	}
}


int best(Student** other, int numofstudents)//functions that returns index of the student with the best avarge
{
	int index=0;
	int biggest=other[0]->averagecalc();
	for (int i = 1; i < numofstudents; i++)
	{
		if (other[i]->averagecalc() > biggest)
		{
			biggest = other[i]->averagecalc();
			index = i;
		}
	}
	return index;
}

int rich(Worker** other, int numofworkers)//friend function that returns the index of the worker with the biigest salary
{
	int index=0;
	int biggest = other[0]->salary;
	for (int i = 1; i < numofworkers; i++)
	{
		if (other[i]->salary > biggest)
		{
			biggest = other[i]->salary;
			index = i;
		}
	}
	return index;
}


void options(Student** students, Worker** workers, int numofstudents, int numofworkers)//options functions lets you choose which option you want to do
{
	int num = 0;
	while (num != 50)
	{
		cout << "Please choose an option: " << endl;
		cout << "1. Print all data." << endl;
		cout << "2. Add grade to the student." << endl;
		cout << "3. Print the student with the biggest avarage." << endl;
		cout << "4. Print the avarage of all courses." << endl;
		cout << "5. Salary change." << endl;
		cout << "6. Salary change with percent." << endl;
		cout << "7. Print the worker with the biggest salary." << endl;
		cout << "8. Print the avarage salray of all." << endl;
		cout << "9. Print bio" << endl;
		cout << "10. End." << endl;
		cin >> num;
		if (num == 1)
		{
			cout << endl;
			cout << "Student data: " << endl;
			cout << endl;
			for (int i = 0; i < numofstudents; i++)
			{
				cout << students[i][0] << endl;
			}
			cout << endl;
			cout << "Workers data:" << endl;
			cout << endl;
			for (int i = 0; i < numofworkers; i++)
			{
				cout << workers[i][0] << endl;
			}
		}
		if (num == 2)
		{
			int index, num2;
			cout << "Please enter an index" << endl;
			cin >> index;
			if (index<0 || index>numofstudents)
			{
				cout << "wrong index" << endl;
			}
			else
			{
				cout << "please enter a grade" << endl;
				cin >> num2;
				students[index][0] += num2;
			}
		}
		if (num == 3)
		{
			int i= best(students, numofstudents);
			cout << "The student with the biggest avrage is: " << endl;
			cout << students[i][0];
		}
		if (num == 4)
		{
			float avg = students[0][0].tavg();
			cout << "The total avarage is: " << avg << endl;
		}
		if (num == 5)
		{
			int index;
			int num2;
			cout << "Please enter an index: " << endl;
			cin >> index;
			if (index<0 || index>numofworkers)
			{
				cout << "wrong index" << endl;
			}
			else
			{
				cout << "Please enter the amount of money you want to add: " << endl;
				cin >> num2;
				workers[index][0] += num2;
			}
		}
		if (num == 6)
		{
			int index;
			float num2;
			cout << "Please enter an index: " << endl;
			cin >> index;
			if (index<0 || index>numofworkers)
			{
				cout << "wrong index" << endl;
			}
			else
			{
				cout << "Please enter the percent of the bonus: " << endl;
				cin >> num2;
				while (num2 < 0 || num2>1)
				{
					cout << "Wrong number please enter a number between 0 and 1" << endl;
					cin >> num2;
				}
				workers[index][0] *= num2;
			}
		}
		if (num == 7)
		{
			int i = rich(workers, numofworkers);
			cout << "The worker with the biggest salary is" << endl;
			cout << workers[i][0]<<endl;
		}
		if (num == 8)
		{
			float avgsal = workers[0][0].totalsalavg();
			cout << "The avarage salary is: " << avgsal << endl;
		}
		if (num == 9)
		{
			char tempid[10];
			cout << "To search in the in the list of all please enter an id" << endl;
			cin >> tempid;
			find(students, workers, numofstudents, numofworkers, tempid);
		}
		if (num == 10)
		{
			num = 50;
			cout << "Have a nice day" << endl;
		}
	}
}


int main()
{
	Student** students = NULL;
	Worker** workers = NULL;
	int numofstudents, numofworkers,salary;
	char name[20], id[10];
	cout << "Please enter amount of students: " << endl;
	cin >> numofstudents;
	students = new Student*[numofstudents];
	for (int i = 0; i < numofstudents; i++)
	{
		cout << "Please enter a name: " << endl;
		cin >> name;
		cout << "Please enter a id: " << endl;
		cin >> id;
		while (strlen(id) != 9)
		{
			cout << "Not enough charcters please enter again" << endl;
			cin >> id;
		}
		students[i] = new Student(name,id);
	}
	cout << "Please enter number of workers: " << endl;
	cin >> numofworkers;
	workers = new Worker * [numofworkers];
	for (int i = 0; i < numofworkers; i++)
	{
		cout << "Please enter a name: " << endl;
		cin >> name;
		cout << "Please enter a id: " << endl;
		cin >> id;
		while (strlen(id) != 9)
		{
			cout << "Not enough charcters please enter again" << endl;
			cin >> id;
		}
		cout << "Please enter salary" << endl;
		cin >> salary;
		workers[i] = new Worker(name, id,salary);
	}
	options(students, workers, numofstudents, numofworkers);
	for (int i = 0; i < numofstudents; i++)
	{
		delete students[i];
	}
	delete[]students;
	for (int i = 0; i < numofworkers; i++)
	{
		delete workers[i];
	}
	delete[]workers;
	return 0;
}


