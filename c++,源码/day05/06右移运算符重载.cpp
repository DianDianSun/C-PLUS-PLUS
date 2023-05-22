#include <iostream>
using namespace std;

class Dian
{
public:
	string name;
	int age;
public:
	Dian(string name , int age)
	{
		this->name = name;
		this->age = age;
	}
	int getAge(){
		return age;
	}
};
istream &operator>>(istream &in,Dian &m)
{
	in>>m.age;
	in>>m.name;
	return in;
}
ostream &operator<<(ostream &out,Dian &m)
{
	out << m.age << endl;
	out << m.name << endl;
	return out;
}
void test02()
{
	Dian m("diandian",0),m2("diandian",0);
	cin >> m >> m2;
	cout << m <<endl;
	cout << m2 << endl;
}
int main()
{
	
	
	test02();
	return 0;
}