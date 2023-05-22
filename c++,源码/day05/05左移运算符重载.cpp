#include <iostream>
#include <string>
using namespace std;

class Dian
{
	//如果要访问类的私有成员，那么把<<重载函数声明为友元
	friend void operator<<(ostream &out,Dian &m);
private:
	int id;
	string r;
public: 
	Dian(int id,string s = "zhaoxuridiandian")
	{
		this->id = id;
		this->r = s;
	}
};
//1.形参和实参是一个对象
//2.不能改变库类中的代码
//3.ostream中把拷贝构造函数私有化了
//4.如果要和endl一起使用，那么必须返回ostream的对象 

void operator<<(ostream &out,Dian &m)
{
	cout << m.id << " "<< m.r <<endl;
}
void test01()
{
	Dian d(3);
	cout << d ;
}
int main() {
	
	
	test01();
	return 0;
}