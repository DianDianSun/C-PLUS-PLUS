#include <iostream>
using namespace std;
void test(){
	int a = 10;
	const int b =a;//如果用变量给const修饰的全局变量赋值，那么编译器不会优化
	int *p = (int *)&b;
	*p = 100;
	cout << b << endl;
	cout << *p <<endl;
}


//自定义数据类型，编译器不能优化
struct Maker{
	Maker(){
		a = 100;
	}
	int a;
};
void test02(){
	const Maker ma;
	cout << ma.a <<endl;
	Maker *p = (Maker *)&ma;
	p->a = 200;
	cout << ma.a << endl;//没有进行优化，因为不能优化自定义函数
	
}

int main() {
	
	test02();
	return 0;
}