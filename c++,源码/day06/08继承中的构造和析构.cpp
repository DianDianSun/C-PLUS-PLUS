#include <iostream>
using namespace std;

class Father
{
public:
	Father()
	{
		cout << "Father creat"<<endl;
	}
	~Father()
	{
		cout <<"Father xigou"<<endl;
	}
};
class Son:public Father
{
public:
	Son()
	{
		cout << "son creat"<<endl;
	}
	~Son()
	{
		cout <<"son xigou"<<endl;
	}
};
//先调用父类构造，再调用本身的构造函数析构函数调用反之
void test01()
{
	Son s;
}
class A
{
public:
	A()
	{
		cout << "A creat"<<endl;
	}
	~A()
	{
		cout <<"A xigou"<<endl;
	}
};
class B
{
public:
	B()
	{
		cout << "B creat"<<endl;
	}
	~B()
	{
		cout <<"B xigou"<<endl;
	}
};

class C
{
public:
	C()
	{
		cout << "C creat"<<endl;
	}
	~C()
	{
		cout <<"C xigou"<<endl;
	}
};
class D:A
{
public:
	D()
	{
		cout << "D creat"<<endl;
	}
	~D()
	{
		cout <<"D xigou"<<endl;
	}
public:
	B b;
	C c;
};

int main()
{
	
	
	D d;
	return 0;
}