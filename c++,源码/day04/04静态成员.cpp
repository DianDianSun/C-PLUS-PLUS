#include <iostream>
using namespace std;

class Dian{
public:
	//1.静态成员的身影周期时整个程序 作用域在类内
	static int a2;
public:
	Dian(){
		
	}
	 
	static void setA(int a){
		a2 = a;
		cout << a2 <<endl;
	}
};
//2.静态成员变量要在类内声明，类外初始化
int Dian::a2 = 200;

void test01(){
	//3.静态成员它属于类不属于对象，是所有对象共享的
	cout << Dian::a2 <<endl;
	//4.静态成员变量可以用类访问，也可以用对象访问
	Dian m;
	cout << m.a2 << endl;
}
void test02(){
	Dian::setA(300);
}

int main() {
	
	
	test02();
	return 0;
}