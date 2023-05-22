#include <iostream>
using namespace std;

class Dian
{
public:
	Dian()
	{
		cout << "wucan"<<endl;
	}
	void print()
	{
		cout << "hello"<<endl;
	}
	~Dian()
	{
		cout << "xigou"<<endl;
	}
};
class Sun
{
private:
	Dian *pDian;
public:
	Sun(Dian *m)
	{
		this->pDian = m;
	}
	~Sun()
	{
		cout << "SU nxigou"<<endl;
		if(this->pDian != NULL)
		{
			delete this->pDian;
			this->pDian = NULL;
		}
	}
	Dian *operator->()
	{
		return this->pDian;
	}
	Dian &operator*()
	{
		return *(this->pDian);
	}
};
void test01()
{
	Dian *p = new Dian;
	
	Sun sm(p);//栈区，会调用析构函数
	//当test01函数结束时，会调用Sun的析构函数
	//在这析构函数中delete了Dian的对象，会调用Dian的析构函数
}
void test02()
{
	Dian *p = new Dian;
	
	Sun sm(p);
	
	(*sm).print();
}
int main()
{
	
	
	test02();
	return 0;
}