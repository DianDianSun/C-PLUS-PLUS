#include <iostream>
using namespace std;

//封装：1.把属性和方法封装到类中 2.给这些数据赋予权限
class Dian{
private://私有权限
	int id;
	string name;
public://公有权限
	void set(string Name,int ID){
		id = ID;
		name = Name;
	}
	void printDian(){
		cout << id <<" "<< name << endl;
	}
	void get(){
		cout << a << endl;
	}
protected:
	int a;
};
//继承，公有继承
class Sun : public Dian{//子类 ：继承 
public:
	void func(){
		//下面这个a是从父类继承的
		a = 20;//子类的类内可以方法父类分保护权限的成员
	}
	void gets(){
		cout << a << endl;
	}
};
void test01(){
	Dian a;
	Sun s;
	s.func();
	a.get();
	s.gets();
}
//类外不能访问私有权限
//类外可以访问公有权限
//类外不能访问保存权限的成员
//子类的类内可以访问父类的保护权限的成员
//类内没有权限之分
void MyPrint(){
	Dian dian;
	dian.set("dian",825);
	dian.printDian();
}

int main() {
	
	test01();
	return 0;
}