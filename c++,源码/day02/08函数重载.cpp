#include <iostream>
using namespace std;

//参数的个数不同
void func(){
	cout << "func()"<<endl;
}
void func(int n){
	cout << "func(int n)"<<endl;
}
//参数的类型不同
void func(char c){
	 cout << "func(char)"<<endl;
}
//参数的顺序不同
void func(int a,double n){
	cout << "func(int a,double n)";
}
void func(double n,int a){
	cout << "func(int a,double n)";
}
void test01(){
	int a =10;
	double b = 3.14;
	func();
	//func(b);err double转换不来 int 或者char
	
	func(a,b);
	char c = 'c';
	func(c);//char 可以转换 int 成功，调用int参数的函数
}
int main() {
	
	test01();
	return 0;
}