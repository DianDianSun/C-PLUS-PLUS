#include <iostream>
using namespace std;

//单例模式是一个类只能实例化一个对象

class Dian{
	//1.把构造函数私有化
private:
	Dian(){
		
	}
	Dian(const Dian &a);
	public:
	//静态成员函数，访问静态成员变量
	//把指针的权限设置为私有，然后提供一个静态成员函数让外面获取这个指针
	static Dian* getDian(){
		return  pDian;
	}
private:
	//2.定义一个类内的静态成员指针
	static Dian *pDian;	
};
//3.在类外初始化，new一个对象
Dian *Dian::pDian = new Dian;
void test(){
	Dian *m = Dian::getDian();
	Dian *m2 = Dian::getDian();
	cout << m <<endl;
	cout << m <<endl;
	Dian m3 = *m;//调用拷贝构造
	cout << &m3 <<endl;
}
int main() {
	
	
	test();
	return 0;
}