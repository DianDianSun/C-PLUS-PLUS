#include <iostream>
using namespace std;

class Dian{
public:
	Dian(){
		cout << "wucan"<<endl;
	}
	Dian(int a){
		cout << "youcan"<<endl;
	}
	Dian(const Dian &m){
		cout << "copy"<<endl;
	}
	~Dian(){
		cout << "析构函数" << endl;
	}
};
//1.对象以值方式给函数参数
void func(Dian m){//Dian m = m1;
	
}
void test01(){
	Dian m1;
	func(m1);
}
//2.用一个已有的的对象去初始化另一个对象
void  test02(){
	Dian m1;
	Dian m2(m1);
}
//3.函数的局部对象以值的方式从函数返回
//vs debug 模式下，会调用拷贝构造，vs release 模式下不会调用拷贝构造，qt也不调用
Dian fun2(){
	//局部对象
	Dian m;
	cout << &m <<endl;
	return m;
	
}
void test03(){
	Dian m1 = fun2();
	
	cout << &m1 <<endl;
}
int main() {
	
	test03();
	return 0;
}