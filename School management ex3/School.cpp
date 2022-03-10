#include"School.h"
School::School()
{
	numofworkers = 0;
	listofworkers = NULL;
	manager = false;
}
School::~School()
{
	for (int i = 0; i < numofworkers; i++)
	{
		delete listofworkers[i];
	}
	delete[]listofworkers;
}
int School::Menu()
{
	int num = 50;
	while (num != 6)
	{
		cout << "Please choose an option from the list: " << endl;
		cout << "1. Add Worker " << endl;
		cout << "2. Print workers " << endl;
		cout << "3. Print profession " << endl;
		cout << "4. Print tutors " << endl;
		cout << "5. Print management " << endl;
		cout << "6. Exit " << endl;
		cin >> num;
		while (num < 0 || num > 6)
		{
			cout << "Wrong choise please enter option again" << endl;
			cin >> num;
		}
		if (num == 1)
		{
			int num2;
			cout << "Choose type of worker" << endl;
			cout << "1. Teacher" << endl;
			cout << "2. Temporary teacher" << endl;
			cout << "3. Tutor" << endl;
			cout << "4. Deputy" << endl;
			cout << "5. Manager" << endl;
			cout << "6. Secretary" << endl;
			cin >> num2;//the function adds new workers to the array
			while(num2<0||num2>6)
			{
				cout << "Wrong choise please enter option again" << endl;
				cin >> num2;
			}
			int counter=0,counter2=0;
			char name[10],clas[3];
			long id;
			int seniority, numofsubjects,weaklyhours,extrahours;
			char** listofsubjects;
			cout << "Please enter your name" << endl;
			cin >> name;
			cout << "Please enter your Id" << endl;
			cin >> id;
			cout << "Please enter your seniority" << endl;
			cin >> seniority;
			if (numofworkers >= 1)
			{
				counter = 0;
				for (int i = 0; i < numofworkers; i++)
				{
					if (id == listofworkers[i]->getId())
					{
						counter++;
					}
				}
			}
			if (counter == 0)
			{
				if (num2 == 1)
				{
					cout << "Please enter the number of subjects you teach" << endl;
					cin >> numofsubjects;
					listofsubjects = new char* [numofsubjects];
					for (int i = 0; i < numofsubjects; i++)
					{
						listofsubjects[i] = new char[10];
						cout << "Enter " << i + 1 << " subject" << endl;
						cin >> listofsubjects[i];
					}
					Worker* worker = new Teacher(name, id, seniority, numofsubjects, listofsubjects);
					operator+(worker);
				}
				if (num2 == 2)
				{
					cout << "Please enter the number of subjects you teach" << endl;
					cin >> numofsubjects;
					listofsubjects = new char* [numofsubjects];
					for (int i = 0; i < numofsubjects; i++)
					{
						listofsubjects[i] = new char[10];
						cout << "Enter " << i + 1 << " subject" << endl;
						cin >> listofsubjects[i];
					}
					cout << "Please enter weakly hours" << endl;
					cin >> weaklyhours;
					Worker* worker = new Temp(name, id, seniority, numofsubjects, listofsubjects, weaklyhours);
					operator+(worker);
				}
				if (num2 == 3)
				{
					cout << "Please enter the number of subjects you teach" << endl;
					cin >> numofsubjects;
					listofsubjects = new char* [numofsubjects];
					for (int i = 0; i < numofsubjects; i++)
					{
						listofsubjects[i] = new char[10];
						cout << "Enter " << i + 1 << " subject" << endl;
						cin >> listofsubjects[i];
					}
					cout << "Please enter your class" << endl;
					cin >> clas;
					if (numofworkers >= 1)
					{
						counter2 = 0;
						for (int i = 0; i < numofworkers; i++)
						{
							if (strcmp(listofworkers[i]->get_type(), "Tutor") == 0 || strcmp(listofworkers[i]->get_type(), "Deputy") == 0)
							{
								if (dynamic_cast<Tutor*>(listofworkers[i]) != NULL)
								{
									if (strcmp(dynamic_cast<Tutor*>(listofworkers[i])->getclass(), clas) == 0)
									{
										counter2++;
									}
								}
							}
						}
					}
					if (counter2 == 0)
					{
						Worker* worker = new Tutor(name, id, seniority, numofsubjects, listofsubjects, clas);
						operator+(worker);
					}
					else
					{
						cout << "The class is already taken" << endl;
					}
				}
				if (num2 == 4)
				{
					cout << "Please enter the number of subjects you teach" << endl;
					cin >> numofsubjects;
					listofsubjects = new char* [numofsubjects];
					for (int i = 0; i < numofsubjects; i++)
					{
						listofsubjects[i] = new char[10];
						cout << "Enter " << i + 1 << " subject" << endl;
						cin >> listofsubjects[i];
					}
					cout << "Please enter your class" << endl;
					cin >> clas;
					if (numofworkers >= 1)
					{
						counter2 = 0;
						for (int i = 0; i < numofworkers; i++)
						{
							if (strcmp(listofworkers[i]->get_type(), "Tutor") == 0 || strcmp(listofworkers[i]->get_type(), "Deputy") == 0)
							{
								if (dynamic_cast<Tutor*>(listofworkers[i]) != NULL)
								{
									if (strcmp(dynamic_cast<Tutor*>(listofworkers[i])->getclass(), clas) == 0)
									{
										counter2++;
									}
								}
							}
						}
					}
					if (counter2 == 0)
					{
						Worker* worker = new Deputy(name, id, seniority, numofsubjects, listofsubjects, clas);
						operator+(worker);
					}
					else
					{
						cout << "The class is already taken" << endl;
					}
				}
				if (num2 == 5)
				{
					if (manager == false)
					{
						manager = true;
						Worker* worker = new Manager(name, id, seniority);
						operator+(worker);
					}
					else
					{
						cout << "Cant add another manager" << endl;
					}
				}
				if (num2 == 6)
				{
					cout << "Please enter extrahours" << endl;
					cin >> extrahours;
					Worker* worker = new Secretary(name, id, seniority, extrahours);
					operator+(worker);
				}
			}
			else
			{
				cout << "The ID is already taken" << endl;
			}

		}
		if (num == 2)//the function prints all workers
		{
			for (int i = 0; i < numofworkers; i++)
			{
				listofworkers[i]->print();
				cout << endl;
			}
		}
		if (num == 3)//the function gets a course name and prints all workers that teach that class
		{
			char* subject = new char[10];
			cout << "Please enter a subject" << endl;
			cin >> subject;
			cout << "The teachers of " << subject << " :" << endl;
			for (int i = 0; i < numofworkers; i++)
			{
				if (strcmp(listofworkers[i]->get_type(),"Teacher") == 0|| strcmp(listofworkers[i]->get_type(), "Temp") == 0|| strcmp(listofworkers[i]->get_type(), "Tutor") == 0|| strcmp(listofworkers[i]->get_type(), "Deputy") == 0)
				{
					if (dynamic_cast<Teacher*>(listofworkers[i]) != NULL)
					{
						dynamic_cast<Teacher*>(listofworkers[i])->nameprint(subject);
					}
				}
			}
		}
		if (num == 4)//the function prints all tutors
		{
			for (int i = 0; i < numofworkers; i++)
			{
				if (strcmp(listofworkers[i]->get_type(),"Tutor") == 0||strcmp(listofworkers[i]->get_type(),"Deputy") == 0)
				{
					if (dynamic_cast<Tutor*>(listofworkers[i]) != NULL)
					{
						dynamic_cast<Tutor*>(listofworkers[i])->printt();
					}
				}
			}
		}
		if (num == 5)//the function prints all the managment staff
		{
			for (int i = 0; i < numofworkers; i++)
			{
				if (strcmp(listofworkers[i]->get_type(),"Manager") == 0)
				{
					if (dynamic_cast<Manager*>(listofworkers[i]) != NULL)
					{
						cout << "Manager:" << endl;
						dynamic_cast<Manager*>(listofworkers[i])->printnamew();
					}
				}
			}
			cout << "Deputy:" << endl;
			for (int i = 0; i < numofworkers; i++)
			{
				if (strcmp(listofworkers[i]->get_type(),"Deputy") == 0)
				{
					if (dynamic_cast<Deputy*>(listofworkers[i]) != NULL)
					{
						dynamic_cast<Deputy*>(listofworkers[i])->printnamew();
					}
				}
			}
		}
		if (num == 6)
		{
			cout << "Have a nice day :)" << endl;
		}
		
	}
	return 0;
}
void School::operator+(Worker* worker)//the operator is adds a new worker every time we call it 
{
	if (numofworkers == 0)
	{

		listofworkers = new Worker * [1];
		listofworkers[0] = worker;
		numofworkers++;
		cout << "Worker added" << endl;
	}
	else
	{

		Worker** temp = new Worker * [numofworkers + 1];
		for (int i = 0; i < numofworkers; i++)
		{
			temp[i] = listofworkers[i];
		}
		temp[numofworkers] = worker;
		numofworkers++;
		delete[]listofworkers;
		listofworkers = temp;
		cout << "Worker added" << endl;
	}
}