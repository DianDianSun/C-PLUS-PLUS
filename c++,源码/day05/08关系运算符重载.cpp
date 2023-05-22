#include <iostream>
using namespace std;

class Dian
{
public:
	int id;
	int age;
public:
	Dian()
	{
		id = 0;
		age = 0;
	}
	Dian(int id,int age)
	{
		this->id = id;
		this->age = age;
	}
};
int operator==(Dian &m1,Dian &m2)
{
	if(m1.id == m2.id&&m1.age == m2.age)
	{
		return 1;
	}else
	{
		return 0;
	}
	
}
void test()
{
	Dian m1(11,20);
	Dian p1;
	
	if(m1 == p1)
	{
		cout << "666";
	}else
	{
		cout << "777";
	}
	
}

int main()
{
	
	test();
	
	return 0;
}