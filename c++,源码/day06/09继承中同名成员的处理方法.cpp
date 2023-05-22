#include <iostream>
using namespace std;

class Father
{
public:
	int a;
public:
	Father()
	{
		a = 10;
	}
	void func()
	{
		cout << "father func"<<endl;
	}
	void func(int a)
	{
		cout << "father funcint a"<<endl;
	}
	void func(int a,int b)
	{
		cout << "father funcint a,int b"<<endl;
	}
};

class son:public Father
{
public:
	int a;
public:
	son()
	{
		a = 20;
	}
	void func()
	{
		cout << "Son func"<<endl;
	}
};
//当子类和父类有同名成员时，子类的同名成员会隐藏父类的同名成员
void test01()
{
	son b;
	cout << b.a <<endl;
//	通过父类名作用域可以访问
	cout << b.Father::a<<endl;
}
//当子类和父类同名函数时，父类的所有函数重载都会被隐藏
void test02()
{
	son c;
	c.func();
	//c.func(10) error
}
int main()
{
	
	
	test01();
	return 0;
}