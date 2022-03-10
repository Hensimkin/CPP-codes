#include"MyArray.h"//defaul ctor applies NULL and zero to the fields
MyArray::MyArray()
{
	arr = NULL;
	lentgh = 0;
}


MyArray::MyArray(float* arr, int lentgh)//parameter ctor applies parameters
{
	this->lentgh = lentgh;
	this->arr = new float[this->lentgh];
	for (int i = 0; i < this->lentgh; i++)
	{
		this->arr[i] = arr[i];
	}
}


MyArray::MyArray(int lentgh)//ctor that gets only the length of the array and applies zero in every place
{
	this->lentgh = lentgh;
	this->arr = new float[this->lentgh];
	for (int i = 0; i < this->lentgh; i++)
	{
		this->arr[i] = 0;
	}
}


MyArray::MyArray(const MyArray& other)// copy ctor copies the data from another class to this class
{
	this->lentgh = other.lentgh;
	this->arr = new float[this->lentgh];
	for (int i = 0; i < this->lentgh; i++)
	{
		this->arr[i] = other.arr[i];
	}
}


void MyArray::print()//the function prints the data of the array
{
	//cout << lentgh << endl;
	if (this->arr == NULL)
	{
		cout << "the size is 0 and the array is null" << endl;
	}
	else
	{
		for (int i = 0; i < lentgh; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}


bool MyArray::checkarray(float* arr, int lentgh)//the function checks if the array is null or not and then it makes a new array and copies the array from to the other and then return true or false if it happend
{
	if (this->arr == NULL)
	{
		this->lentgh = lentgh;
		this->arr = new float[this->lentgh];
		for (int i = 0; i < this->lentgh; i++)
		{
			this->arr[i] = arr[i];
		}
		if (this->arr == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		delete[]this->arr;
		this->lentgh = lentgh;
		this->arr = new float[this->lentgh];
		for (int i = 0; i < this->lentgh; i++)
		{
			this->arr[i] = arr[i];
		}
		if (this->arr == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}


bool MyArray::changeindex(float num, int index)//the function gets the index and the element and changes it in the array
{
	if (index<0 || index>lentgh)
	{
		cout << "bad index" << endl;
		return false;
	}
	else
	{		
		arr[index] = num;
		cout << "element changed" << endl;
		return true;
	}
}


bool MyArray::retrunarray(float& num, int index)// the function return the number in the index 
{
	if (index<0 || index>lentgh)
	{
		cout << "bad index" << endl;
		return false;
	}
	else
	{
		num=this->arr[index];
		return true;
	}
}


float MyArray::sum()//the function calculates the sum of the array
{
	float temp = 0;
	for (int i = 0; i < this->lentgh; i++)
	{
		temp = temp + arr[i];
	}
	return temp;
}


int MyArray::getLentgh()//get function returns the lenth of the array
{
	return this->lentgh;
}