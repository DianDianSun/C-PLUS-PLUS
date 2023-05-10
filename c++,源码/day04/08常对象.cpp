#include <iostream>
using namespace std;

class Dian{
public:
	int mId;
	int mAge;
	mutable int sorce;
public:
	Dian(int id,int age){
		mAge = age;
		mId = id;
	}
	//常函数,1.函数的()后main加上const，该函数变为常函数
	void print()const{
		//id = 100;err  2.常函数内不能修改普通成员变量
		//3.const 修饰的是this指针指向的空间的变量不能改变
		//Dian *const this
		//const Dian *const this ,这是常函数修饰的
		sorce = 100;//4.mutable 修饰的成员变量在常函数中可以修改
	}
};
void test(){
	//1.在数据类型前加上constant，让对象成为常对象
	const Dian m(1,18);//常对象
	//m.mId = 100;//erro 常对象不能改变普通变量成员变量的值
	//m.print;//擦好难过对象不能调用普通成员函数
	m.print();//常对象可以调用常函数
	m.sorce = 1;//常对象可以调用常函数
	
	
}
int main() {
	
	
	return 0;
}