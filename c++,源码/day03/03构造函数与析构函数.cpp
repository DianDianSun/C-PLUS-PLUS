#include <iostream>
using namespace std;

class Dian{
public:
	//构造函数的作用：初始化成员变量，是编译器进行的
	Dian(){
		a = 10;
		cout << "gouzaodiandain"<<endl;
	}
	//析构函数，在对象销毁前，编译器调用析构函数
	~Dian(){
		cout << "diandian"<<endl;
	}
public:
	int a;
};
void test01(){
	//实例化对象，内部做了两件事，1.分配空间 2.调用构造函数进行初始化
	Dian D;
	int b = D.a;
	cout << b << endl;
}
//析构函数的作用
class Dian2{
public:
	Dian2(const char*name,int age){
		cout <<"有参构造"<<endl;
		//从堆区申请空间
		pname = (char*)malloc(strlen(name)+1);
		strcpy(pname,name);
		mage = age;
	}
	~Dian2(){
		cout << "析构函数" <<endl;
		//释放堆区空间
		if(pname != NULL){
			free(pname);
			pname = NULL;
		}
	}
public:
	char *pname;
	int mage;
};
//有参构造函数
class Dian3{
public:
	//注意1:构造函数可以重载
	Dian3(){ 
		cout << "wucan"<<endl;
	}
	Dian3(int a){//有参构造函数
		cout << "youcan"<<endl;
	}
	~Dian3(){
		cout << "xigou"<<endl;
	}
};
void test02(){
	Dian2 d("diandian",19);
	cout << d.pname	<< d.mage << endl;
}
void test03(){
	Dian3 d;//当构造函数私有时，实例化不了对象
	Dian3 d1r(10);
	//有对象产生必然会调用构造函数，有对象销毁必然会调用析构函数
	//有多少个对象就会调用多少次，//有多少个对象销毁就会调用多少次xi
}
int main() {
	test03();
	return 0;
}