#include <iostream>
using namespace std;

class Dian
{
	friend ostream &operator<<(ostream &out,Dian &m);
public:
	
	int a;
public:
	Dian(int a)
	{
		this->a = a;
	}
	//重载前置++
	Dian &operator++()
	{
		++a;
		return *this;
	}
	//后置++
	Dian operator++(int)//占位参数必须时int
	{
		//后置加加，先返回，后加加
		Dian tmp(*this);
		
		++(this->a);
		return tmp;
	}
};
ostream &operator<<(ostream &out,Dian &m)
{
	out << m.a;
	return out;
}
void test02()
{
	Dian m1(1);
	cout << m1 <<endl;//1
	cout << ++m1 <<endl;//2
	cout << (m1++).a <<endl;//2
	cout << m1 <<endl;//3
	//同等条件下，友夏安使用前置加加
}
int main()
{
	
	
	test02(); 
	return 0;
}