
#include<iostream>
using namespace std;
template<class T>
T* remove(T* arr, int &size,T val)
{
	int count = 0,j=0;
	T* arr_new = NULL;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != val)
		{
			count++;
		}
	}
	int size2 = count;
	arr_new = new T[size];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != val)
		{
			arr_new[j] = arr[i];
			j++;
		}
	}
	size = count;
	return arr_new;
}

int main()
{
	float* arr1 = NULL,val1, * arr3;
	double* arr2 = NULL,val2, * arr4;
	int size1, size2;
	cout << "Please enter size for the float array" << endl;
	cin >> size1;
	cout << "Please enter size for the double array" << endl;
	cin >> size2;
	arr1 = new float[size1];
	cout << "Please enter numbers to the float array" << endl;
	for (int i = 0; i < size1; i++)
	{
		cin >> arr1[i];
	}
	arr2 = new double[size2];
	cout << "Please enter numbers to the double array" << endl;
	for (int i = 0; i < size2; i++)
	{
		cin >> arr2[i];
	}
	cout << "Please enter a value for the float array" << endl;
	cin >> val1;
	cout << "Please enter a value for the double array" << endl;
	cin >> val2;
	arr3 = remove(arr1, size1, val1);
	cout << "The new float array is: " << endl;
	for (int i = 0; i < size1; i++)
	{
		cout << arr3[i]<<" ";
	}
	cout << endl;
	arr4 = remove(arr2, size2, val2);
	cout << "The new doublet array is: " << endl;
	for (int i = 0; i < size2; i++)
	{
		cout << arr4[i] << " ";
	}
	cout << endl;
}
