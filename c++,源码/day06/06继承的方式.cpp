#include <iostream>
using namespace std;

class Father
{
public:
	int a;
private:
	int b;
protected:
	int c;
};

class son1:public Father
{
	void func1()
	{
		cout << a;
//		cout << b  error
		cout << c;
	}
//	1.父类的共有属性成员，到子类还是public有
//	2.父类的私有属性成员，到子类还是私有
//	3.父类的保护属性成员，到子类还是保护
};
class son2:protected Father
{
public:
	void func()
	{
		cout << this->a;
		//b;error;
		cout << c;
//		保护继承
//	1.父类的共有属性成员，到子类还是保护
//	2.父类的私有属性成员，到子类还是私有
//	3.父类的保护属性成员，到子类还是保护
	}
};
class son3:protected Father
{
public:
	void func()
	{
		cout << this->a;
		
		cout << c;
		//		私有继承
		//	1.父类的共有属性成员，到子类还是保护
		//	2.父类的私有属性成员，到子类还是私有
		//	3.父类的保护属性成员，到子类还是保护
	}
};
int main()
{
	
	son1 m;
	cout << m.a;
//	cout << m.b; error 
//	cout << m.c; error
	son2 m2;
	son3 m3;
	return 0;
}