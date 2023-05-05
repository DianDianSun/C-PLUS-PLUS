#include <iostream>
#include <string>
using namespace std;


//自定义的数据类型
//设置圆的类
class Circle{
	
public:
	//设置半径的长度
	void setr(double r){
		mR = r;
	}
	//计算圆的周长
	double getL(){
		return 2*3.14*mR;
	}
public://公有权限
	double mR;//成员变量，成员属性
	
};
void test(){
	
	//数据类型定义变量
	//类实力化对象
	Circle c;
	c.setr(20);
	cout << c.getL();
}
void test02(){
	string str = "world";
	cout << str;
}
class Point{
	
public:
	char a;
	char b;
	char bomb;
public:
	void my_set(char A = '.',char C = '0',char B = '0'){
		if(A == '*'){
			
		}
	}
	void my_printf(){
		
	}
	
};
int main() {
	
	test02();
	return 0;
}