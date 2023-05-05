#include <iostream>
using namespace std;

int my_func(int a,int b = 0){//int b = 0;这就是函数的默认参数，不一定是0
	return a+b;
}
void test01(){
	//函数的恶默认参数的作用
	//当函数内常要用到形参的某个值，丹偶尔要使用其他值
	//增加函数的灵活性
	cout << my_func(10) <<endl;
	cout << my_func(10,200) <<endl;
}

//注意1: 函数的默认参数后面的参数必须都是默认参数
int fun3(int a,int b = 1, int c = 1,int d = 3){
	return a+b+c+d;
}
//注意2: 函数的声明和实现不能同时有参数的默认参数
void myfunc3(int a,int b = 1);
void myfunc3(int a,int b){
	
}

//函数的占位参数,占位参数阻碍后面运算符重载时区分前加加和后加加
void func(int a,int = 10){//占位参数也有默认值
	
}
void test02(){
	func(10);
}
//占位参数与默认参数混搭
void func3(int a = 20,int b = 20){
	
}
void test03(){
	func3();
	func3(10);
	func3(10,30);
}

int main() {
	
	test01();
	return 0;
}