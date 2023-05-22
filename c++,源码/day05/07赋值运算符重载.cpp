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
void test()
{
	Dian m1(10,20);
	Dian m2;
	m1 = m2;//赋值操作
	//默认的赋值运算符重载函数进行了简单的赋值操作

}
class Sun
{
public:
	Sun(const char *name)
	{
		pname = new char[strlen(name) + 1];
		strcpy(pname,name);
	}
	Sun(const Sun &m)
	{
		pname = new char[strlen(m.pname) + 1];
		strcpy(pname,m.pname);
	}
	~Sun()
	{
		delete[] pname;
		pname = NULL;
	}
	Sun &operator=(const Sun &m)
	{
		if(this->pname != NULL)
			{
				delete [] this->pname;
			}
		//1.不能确定this->pname指向的空间是否能装下stu数据，故先释放后重新申请空间
		this->pname = new char[strlen(m.pname) + 1];
		//2
		strcpy(this->pname,m.pname);
		return *this;
	}
	void print()
	{
		cout << pname << endl;
	}
public:
	char *pname;
};

void test02()
{
	Sun s1("diandain");
	Sun s2("sun");
	s2 = s1;
	s1.print();
	s2.print();
}
//赋值运算符重载中为什么要返回引用
void test03()
{
	Sun s1("a");
	Sun s2("b");
	Sun s3("c");
	s1 = s2 = s3;
	cout << s1.pname << endl;
	cout << s2.pname << endl;
	cout << s3.pname << endl;
	//如果返回的是值，s2 = s3 这个表达式会产生一个新的对象
	
	
}
int main()
{
	
	test03();
	
	return 0;
}