#include <iostream>
using namespace std;

//一个类如果重载了函数调用符号，那么这个类实例化出的对象也叫仿函数
//仿函数的作用：
//1.代码容易维护
//2.方便有去拿下的调用函数
//3.作为苏三发的策略（后stl
class Dian
{
public:
	string name;
public:
	Dian()
	{
		name = "cuihua";
	}
	void print()
	{
		cout << name << endl;
	}
	void operator() (int a,int b = 0)
	{
		cout << "heallo" << endl;
		cout << a << " " << b;
	}
};
void test()
{
	Dian func;
	
	func(3,3);//看起来像函数，其实func是对象
}
int main()
{
	test();
	
	
	
	
	return 0;
}