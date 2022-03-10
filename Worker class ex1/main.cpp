
#include"Worker.h"
int main()
{
	char name[15];
	long id;
	double salaryperhour;
	int workhours;
	int extrahours,num;
	cout << "please enter your name" << endl;
	cin >> name;
	cout << "please enter your id" << endl;
	cin >> id;
	cout << "please enter your hourly salary" << endl;
	cin >> salaryperhour;
	cout << "please enter the amount of hours you worked this month" << endl;
	cin >> workhours;
	cout << "please enter the amount of extra hours you worked" << endl;
	cin >> extrahours;
	Worker worker(name, id, salaryperhour, workhours, extrahours);
	num = 1;
	while (num != 0)
	{
		cout << "1. update regular hours" << endl;
		cout << "2. update extra hours" << endl;
		cout << "3. update salary per hour" << endl;
		cout << "4. print info" << endl;
		cout << "5. print your salary" << endl;
		cout << "6. exit" << endl;
		cin >> num;
		if (num == 1)
		{
			cout << "please enter your regular hours" << endl;
			cin >> workhours;
			worker.setHours(workhours);
		}
		if (num == 2)
		{
			cout << "please enter your extra hours" << endl;
			cin >> extrahours;
			worker.setExtrahours(extrahours);
		}
		if (num == 3)
		{
			cout << "please enter salary per hour" << endl;
			cin >> salaryperhour;
			worker.setHoursalary(salaryperhour);
		}
		if (num == 4)
		{
			worker.showinfo();
		}
		if (num == 5)
		{
			int temp = worker.calcsaray();
			cout<<fixed << setprecision(2) <<"your salary is: " << temp << endl;
		}
		if (num == 6)
		{
			cout << "have a nice day" << endl;
			num = 0;
		}
	}
	return 0;


	
}