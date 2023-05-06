#include <iostream>
using namespace std;


class Dian{
public:
	Dian(const int &a){
		cout << "youcan" << endl;
	}
};
//如果程序员提供了有参构造，那么编译器不会提供默认构造函数，但会提供默认的拷贝构造
void test01(){
	//Dian a;erro
	Dian m(10);//调用了有参构造
	Dian m1(m);//调用了默认拷贝构造
}
//2.如果程序员提供了拷贝构造函数，那么编译器不会提供默认的构造函数和默认的拷贝函数
void test02(){
	//Dian m;error
}
int main() {
	
	
	return 0;
}