#include <iostream>
using namespace std;
#include "01ClassArray.h"

void printMyArray(MyArray &arr){
	for(int i = 0;i < arr.Size();i++){
		cout << arr.Get(i)<<" ";
	}
	cout<<endl;
}
void test01(){
		
	MyArray arr(20,1);
	printMyArray(arr);
	for(int i = 0;i < arr.Size();i++)
	{
		arr.Get(i) = i + 100;
	}
	printMyArray(arr);
	
	arr.Set(2, 0);
	printMyArray(arr);
	
	MyArray arr2 = arr;
	printMyArray(arr2);
}
void test02(){
	MyArray arr2(10);
	arr2.PopBack();
	printMyArray(arr2);
	arr2.Set(3, 4);
	printMyArray(arr2);
}
int main() {
	
	
	test02();
	return 0;
}