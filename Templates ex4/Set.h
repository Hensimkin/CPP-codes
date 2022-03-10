#pragma once
#include<iostream>
using namespace std;
template <class T>
class Set
{
private:
	T* arr;
	int size;
public:
	Set();
	Set(T* arr, int size);
	Set(const Set& other);
	~Set();
	const Set operator+(const Set& s) const;
	const Set operator-(const Set& s) const;
	const Set operator*(const Set& s) const;
	Set& operator=(const Set& s);
	bool operator==(const Set& s) const;
	bool in(T element) const;
	void print() const;
};


template <class T>
Set<T>::Set()
{
	arr = NULL;
	size = 0;
}

template<class T>
Set<T>::Set(T* arr, int size)
{
	this->size = size;
	this->arr = new T[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = arr[i];
	}
}


template<class T>
Set<T>::Set(const Set& other)
{
	size = other.size;
	this->arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

template<class T>
Set<T>::~Set()
{
	delete[]arr;
}

template<class T>
const Set<T> Set<T>::operator+(const Set& s) const
{
	T* newarr;
	int newsize,tsize=s.size,counter,Dsize=size;
	for (int i = 0; i < s.size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (s.arr[i] == arr[j])
			{
				tsize--;
			}
		}
	}
	newsize = size + tsize;
	newarr = new T[newsize];
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}
	for (int i = 0; i < s.size; i++)
	{
		counter = 0;
		for (int j = 0; j < size; j++)
		{
			if (arr[j] == s.arr[i])
			{
				counter++;
			}
		}
		if (counter == 0)
		{
			newarr[Dsize] = s.arr[i];
			Dsize++;
		}
	}
	return Set(newarr, newsize);
}

template<class T>
void Set<T>::print() const
{
	for (int i = 0; i < this->size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
const Set<T> Set<T>::operator-(const Set& s) const
{
	T* newarr = NULL;
	int newsize=size, tsize = s.size, counter2;
	int counter=0;
	for (int i = 0; i < size; i++)
	{
		counter = 0;
		for (int j = 0; j < s.size; j++)
		{
			if (arr[i] == s.arr[j])
			{
				newsize--;
			}
		}
	}
	newarr = new T[newsize];
	if (newsize == size)
	{		
		for (int i = 0; i < newsize; i++)
		{
			newarr[i] = arr[i];
		}
		return Set(newarr, newsize);
	}
	else
	{
		int k = 0;
		for (int i = 0; i < size; i++)
		{
			counter2 = 0;
			for (int j = 0; j < s.size; j++)
			{
				if (arr[i] == s.arr[j])
				{
					counter2++;
				}
			}
			if (counter2 == 0)
			{
				newarr[k] = arr[i];
				k++;
			}
		}
		return Set(newarr, newsize);
	}

}


template<class T>
const Set<T> Set<T>::operator*(const Set& s) const
{
	T* newarr;
	int newsize=0, tsize = s.size, counter;
	for (int i = 0; i < size; i++)
	{
		counter = 0;
		for (int j = 0; j < s.size; j++)
		{
			if (arr[i] == s.arr[j])
			{
				counter++;
			}
		}
		newsize = newsize + counter;
	}
	int k = 0;
	newarr = new T[newsize];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < s.size; j++)
		{
			if (arr[i] == s.arr[j])
			{
				newarr[k] = arr[i];
				k++;
			}
		}
	}
	return Set(newarr, newsize);
}


template<class T>
Set<T>& Set<T>::operator=(const Set& s)
{
	size = s.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = s.arr[i];
	}
	return Set(arr, size);
}

template<class T>
bool Set<T>::operator==(const Set& s) const
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == s.arr[i])
		{
			count++;
		}
	}
	if (size == s.size && count == size)
	{
		return true;
	}
	else
	{
		return false;
	}
}


template<class T>
bool Set<T>::in(T element) const
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == element)
		{
			counter++;
		}
	}
	if (counter > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}