#include <iostream>
#include "01ClassArray.h"
using namespace std;

void test()
{
	MyArray arr;
	for(int i = 0; i < 20;i++)
	{
		arr[i] = i + 20;
	}
	for(int i = 0;i < 20;i++)
	{
		cout << arr[i] << endl;
	}
	MyArray arr2;
	arr2 = arr;
	for(int i = 0;i < 20;i++)
		{
			cout << arr2[i] << endl;
		}
}
int main()
{
	
	
	test();
	return 0;
}