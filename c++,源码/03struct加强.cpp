#include <iostream>
using namespace std;

struct Maker1{
	char name[64];
	int age;
};
//加强一：
void test1(){
	Maker1 a;//不需要加struct就可以定义变量
}
//加强二：
struct Maker2{
	int a;
	void func(){//结构体可以写函数
		cout << "func"<<endl;
	}
};
void test2(){
	Maker2 a2;
	a2.func();
}
int main() {
	
	test2();
	return 0;
}