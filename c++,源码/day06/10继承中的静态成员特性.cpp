#include <iostream>
using namespace std;

class father
{
public:
	static int ma;
public:
	static void func()
	{
		cout << "father func"<<endl;
	}
	static void func(int a)
	{
		cout << "father funcint a"<<endl;
	}
	static void func(int a,int b)
	{
		cout << "father funcint a,int b"<<endl;
	}
};
int father::ma = 10;
class son:public father
{
public:
	static int mb;
	static void func()
	{
		cout << "son func"<<endl;
	}
};
int son::mb = 20;
void test01()
{
	son s;
	s.func();
}
int main()
{
	
	
	test01();
	return 0;
}