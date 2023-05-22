#include <iostream>
using namespace std;

class animal
{
public:
	virtual void speak()
	{
		cout << "animal speak"<<endl;
	}
};
class dog:public animal
{
public:
	void speak()
	{
		cout << "dog "<<endl;
	}
};
class dog1:public animal
{
public:
	void speak()
	{
		cout << "dog1 "<<endl;
	}
};
class dog2:public animal
{
public:
	void speak()
	{
		cout << "dog2jineng "<<endl;
	}
};
void dologin(animal *c)
{
	c->speak();
}
void test01()
{
	animal an;
	an.speak();//在编译阶段就确定了调用speak这个函数的地址
}
void test02()
{
	dog *d = new dog;
	dologin(d);
	dog1 *dw = new dog1;
	dologin(dw);
	dog2 *dw2 = new dog2;
	dologin(dw2);
	
}
int main()
{
	
	
	test02();
	return 0;
}