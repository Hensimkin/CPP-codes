
#include"Set.h"
int main()
{
	int size1, size2,size3,size4,size5,size6;
	int* arr1 = NULL, * arr2 = NULL;
	float* arr3 = NULL, * arr4 = NULL;
	char* arr5 = NULL, * arr6 = NULL;
	cout << "please enter the first size for the int array" << endl;
	cin >> size1;
	arr1 = new int[size1];
	cout << "enter numbers to the first int array" << endl;
	for (int i = 0; i < size1; i++)
	{
		cin >> arr1[i];
	}
	Set<int> one(arr1, size1);
	cout << "please enter the second size for the int array" << endl;
	cin >> size2;
	arr2 = new int[size2];
	cout << "enter numbers to the second int array" << endl;
	for (int i = 0; i < size2; i++)
	{
		cin >> arr2[i];
	}
	Set<int> two(arr2, size2);
	cout << "please enter the first size for the float array" << endl;
	cin >> size3;
	arr3 = new float[size3];
	cout << "enter numbers to the first float array" << endl;
	for (int i = 0; i < size3; i++)
	{
		cin >> arr3[i];
	}
	Set<float> three(arr3, size3);
	cout << "please enter the second size for the float array" << endl;
	cin >> size4;
	arr4 = new float[size4];
	cout << "enter numbers to the second float array" << endl;
	for (int i = 0; i < size4; i++)
	{
		cin >> arr4[i];
	}
	Set<float> four(arr4, size4);
	cout << "please enter the first size for the char array" << endl;
	cin >> size5;
	arr5 = new char[size5];
	cout << "enter numbers to the first char array" << endl;
	for (int i = 0; i < size5; i++)
	{
		cin >> arr5[i];
	}
	Set<char> five(arr5, size5);
	cout << "please enter the second size for the char array" << endl;
	cin >> size6;
	arr6 = new char[size6];
	cout << "enter numbers to the first char array" << endl;
	for (int i = 0; i < size6; i++)
	{
		cin >> arr6[i];
	}
	Set<char> six(arr6, size6);
	int num = 5;
	int num2=0;
	while (num != 4)
	{
		cout << "please choose a type" << endl;
		cout << "1. Int" << endl;
		cout << "2. Float" << endl;
		cout << "3. Char" << endl;
		cout << "4.exit" << endl;
		cin >> num;
		if (num == 1)
		{
			cout << "please choose an option" << endl;
			cout << "1. Union" << endl;
			cout << "2. Intersection" << endl;
			cout << "3. Difference" << endl;
			cin >> num2;
			if (num2 == 1)
			{
				Set<int> union1 = one + two;
				union1.print();
			}
			if (num2 == 2)
			{
				Set<int> union2 = one * two;
				union2.print();
			}
			if (num2 == 3)
			{
				Set<int> union3 = one - two;
				union3.print();
			}
		}
		if (num == 2)
		{
			cout << "please choose an option" << endl;
			cout << "1. Union" << endl;
			cout << "2. Intersection" << endl;
			cout << "3. Difference" << endl;
			cin >> num2;
			if (num2 == 1)
			{
				Set<float> union4 = three + four;
				union4.print();
			}
			if (num2 == 2)
			{
				Set<float> union5 = three * four;
				union5.print();
			}
			if (num2 == 3)
			{
				Set<float> union6 = three - four;
				union6.print();
			}
		}
		if (num == 3)
		{
			cout << "please choose an option" << endl;
			cout << "1. Union" << endl;
			cout << "2. Intersection" << endl;
			cout << "3. Difference" << endl;
			cin >> num2;
			if (num2 == 1)
			{
				Set<char> union7 = five + six;
				union7.print();
			}
			if (num2 == 2)
			{
				Set<char> union8 = five * six;
				union8.print();
			}
			if (num2 == 3)
			{
				Set<char> union9 = five - six;
				union9.print();
			}
		}
		if (num == 4)
		{
			cout << "have a nice day" << endl;
			return 0;
		}
	}
}

