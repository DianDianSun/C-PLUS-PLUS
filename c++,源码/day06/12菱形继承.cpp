#include <iostream>
using namespace std;

//爷爷
// 
class animal
{
public:
	int ma;
public:
	animal()
	{
		ma = 100;
	}
};
//用虚继承的方法解决菱形继承中的二义性问题
class sheep : virtual public animal
{
	
};
class camel : virtual public animal
{
	
};
class sheepcamel :public sheep,public camel
{
	
};
void test()
{
	sheepcamel sc;
    cout << sc.ma;
}
//用虚继承的方法解决菱形继承中的二义性问题
void test02()
{
	sheep s;
	//1.&s;
	//2.(int*)&s;强转为int *类型
	//3.*(int *)&s;
	//4.(int *)*(int *)&s;//指向表的首地址
	//5.*((int *))(int *)& + 1)
}
int main()
{
	
	
	test();
	return 0;
}