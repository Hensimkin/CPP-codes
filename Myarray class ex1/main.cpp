
#include"MyArray.h"
int main()
{
	float *empty_arr = NULL, * zero_arr = NULL, * parameter_arr = NULL, * copied_arr = NULL;
	int sizez,sizep,size3;
	cout << "please enter size for zero arr" << endl;
	cin >> sizez;
	cout << "please enter size for parameter arr" << endl;
	cin >> sizep;
	float* arr = new float[sizep];
	cout << "please enter paramters to the array" << endl;
	for (int i = 0; i < sizep; i++)
	{
		cin >> arr[i];
	}
	MyArray emptyarray;
	MyArray parameterarray(arr, sizep);
	MyArray zeroarray(sizez);
	MyArray copiedarray(zeroarray);
	cout << "empty array: " << endl;
	emptyarray.print();
	cout << "parameter array: " << endl;
	parameterarray.print();
	cout << "zero array: " << endl;
	zeroarray.print();
	cout << "copied array: " << endl;
	copiedarray.print();
	cout << "please enter new size for zero array" << endl;
	cin >> sizez;
	float* zarr = new float[sizez];
	cout << "please enter paramters to the zero array" << endl;
	for (int i = 0; i < sizez; i++)
	{
		cin >> zarr[i];
	}
	zeroarray.checkarray(zarr, sizez);
	zeroarray.print();
	cout << "please enter an index to change in zero array" << endl;
	int index;
	cin >> index;
	cout << "please enter an element to change in zero array" << endl;
	float element;
	cin >> element;
	zeroarray.changeindex(element, index);
	int index2;
	float element2;
	cout << "please enter an index to change in parameter array" << endl;
	cin >> index2;
	cout << "please enter an element to change in parameter array" << endl;
	cin >> element2;
	parameterarray.changeindex(element2, index2);
	int index3;
	float element3;
	cout << "please enter an index to change in copied array" << endl;
	cin >> index3;
	cout << "please enter an element to change in copied array" << endl;
	cin >> element3;
	copiedarray.changeindex(element3, index3);
	cout << "empty array: " << endl;
	emptyarray.print();
	cout << "zero array: " << endl;
	zeroarray.print();
	cout << "parameter array: " << endl;
	parameterarray.print();
	cout << "copied array: " << endl;
	copiedarray.print();
	int index4;
	float element4;
	cout << "please enter an index to change in empty array" << endl;
	cin >> index4;
	cout << "please enter an element to change in empty array" << endl;
	cin >> element4;
	emptyarray.changeindex(element4, index4);
	cout << "please enter an index" << endl;
	int index5;
	cin >> index5;
	float num2 = 0,num3=0,num4=0,num5=0;
	int cnum;
	cnum = emptyarray.retrunarray(num2, index5);
	if (cnum == 1)
	{
		cout << "empty array: " << endl;
		cout << "the number in the index is: " << num2 << endl;
	}
	cnum = zeroarray.retrunarray(num3, index5);
	if (cnum == 1)
	{
		cout << "zero array: " << endl;
		cout << "the number in the index is: " << num3 << endl;
	}
	cnum = parameterarray.retrunarray(num4, index5);
	if (cnum == 1)
	{
		cout << "parameter array: " << endl;
		cout << "the number in the index is: " << num4 << endl;
	}
	cnum = copiedarray.retrunarray(num5, index5);
	if (cnum == 1)
	{
		cout << "copied array: " << endl;
		cout << "the number in the index is: " << num5 << endl;
	}
	cout << "empty array length: " << emptyarray.getLentgh()<<" " << "empty array sum: " << emptyarray.sum() << endl;
	cout << "zero array length: " << zeroarray.getLentgh() << " " << "zero array sum: " << zeroarray.sum()<<endl;
	cout << "parameter array length: " << parameterarray.getLentgh() << " " << "parameter array sum: " << parameterarray.sum() << endl;
	cout << "copied array length: " << copiedarray.getLentgh() << " " << "copied array sum: " << copiedarray.sum()<<endl;
	return 0;
}