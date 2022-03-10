#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class MyArray
{
private:
	float* arr;
	int lentgh;
public:
	MyArray();
	MyArray(float *arr,int lentgh);
	MyArray(int lentgh);
	MyArray(const MyArray& other);
	int getLentgh();
	bool checkarray(float* arr, int lentgh);
	bool changeindex(float num, int index);
	bool retrunarray(float& num, int index);
	void print();
	float sum();
	int returnsize;
	
};