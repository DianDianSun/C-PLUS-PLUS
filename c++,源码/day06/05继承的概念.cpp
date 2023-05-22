#include <iostream>
using namespace std;


//继承的作用
//1.代码复用   2.扩展类的功能
class Dian
{
public:
	void func1()
	{
		cout << "data with " <<endl;
	}
	void func2()
	{
		cout << "earn money" <<endl;
	}
};
class son :public Dian
{
	void func3()
	{
		cout << "youcai " <<endl;
	}
};
void test()
{
	
}
int main()
{
	
	
	
	return 0;
}