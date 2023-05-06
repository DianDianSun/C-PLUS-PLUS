#include <iostream>
using namespace std;

//1.什么事拷贝构造函数
class Dian{
public:
	Dian(){
		cout << "wucan gouzao"<<endl;
		a = 20;
	}//拷贝构造函数
	Dian(const Dian &m){
		cout << "copy gouzaohanshu"<<endl;
		a = m.a;
		
	}
	void print(){
		cout << a <<endl;
	}
private:
	int a;
};
//2.编译器默认提供了拷贝构造函数
class Dian2{
public:
	Dian2(){
		cout << "wucan gouzao"<<endl;
		a = 20;
		b = 10;
	}
//默认提供了拷贝构造函数
//	Dian(const Dian &m){
//		a = m.a;	
//	}
	void print(){
		cout << a << b << endl;
	}
private:
	int a;
	int b;
};
//3.拷贝构造函数中形参要用引用
void test01(){
	Dian2 m1;
	m1.print();
	//用一个已有的对象去初始化另一个对象
	Dian2 m2(m1);
	m2.print();
}
int main() {
	
	test01();
	return 0;
}