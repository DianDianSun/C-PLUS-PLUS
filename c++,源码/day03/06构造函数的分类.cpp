#include <iostream>
using namespace std;

class Dian{
public:
	//按照参数分类：
	Dian(){
		cout << "wucan" << endl;
	}
	Dian(int a){
		cout << "youcan" << endl;
	}
	//按早类型：普通构造函数，拷贝构造函数
	Dian(const Dian &m){
		cout << "拷贝构造"<< endl;
	}
	
	//默认的

};
void test01(){
	Dian m;//使用无参构造函数
	Dian m1(10);//使用有参构造函数
	Dian m2(m1);//使用拷贝构造函数
	
	//不常用
	Dian m4 = Dian(10);//使用的是有参构造函数
	Dian m3 = m2;//调用拷贝函数
	
	Dian m5 = 10;
	
	Dian m6;
	m6 = m5;//赋值操作
}
int main() {
	
	test01();
	return 0;
}