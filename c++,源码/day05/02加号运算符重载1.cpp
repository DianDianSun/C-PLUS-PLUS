#include <iostream>
using namespace std;

class Dian{
public:
	int id;
	int age;
public:
	Dian(int id,int age){
		this->id = id;
		this->age = age;
	}
	//写到成员函数，那么只需要一个参数，这个参数是加号的右边
	Dian operator+(Dian &m2){
		Dian temp(this->id + m2.id,this->age + m2.age);
		return temp;
	}
};
//全局方式//2.编译器调用这个函数
//Dian operator+(Dian &p1,Dian &p2)//3.编译器检查参数是否对应，第一个参数对应左边，第二个参数对应右边
//{
//	Dian temp(p1.id + p2.id,p1.age + p2.age);
//	return temp;
//}
void test01(){
	Dian m1(1,20);
	Dian m2(2,10);
	Dian m3 = m1 + m2;//1.编译器看到两个对象相加，那么编译会找有没有叫operator+的函数
	cout << m3.id << m3.age<<endl;
	Dian m4 = m3 + m2 + m1;
	cout << m4.id << m4.age;
}
int main() {
	
	
	
	test01();
	return 0;
}