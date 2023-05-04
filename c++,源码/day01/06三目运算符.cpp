#include <iostream>
using namespace std;

int main() {
	
	int a = 10;
	int b = 20;
	//c++的三目运算符返回的是左值，c的三目运算符返回的是右值
	(a > b ? a : b) = 100;
	cout<<"b:"<<b<<endl;
	cout<<"a:"<<a<<endl;
	return 0;
}