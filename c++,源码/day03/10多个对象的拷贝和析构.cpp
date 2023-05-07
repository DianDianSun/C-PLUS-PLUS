#include <iostream>
using namespace std;
class DDS{
public:
	DDS(){
		cout << "DDSgouzao" << endl;
	}
	~DDS(){
		cout << "DDSxigou" << endl;
	}
};
class dds{
public:
	dds(){
		cout << "ddsgouzao" << endl;
	}
	~dds(){
		cout << "ddsxixigou" << endl;
	}
};
class Dian {
private:
	DDS a;
	dds b;
public:
	Dian(){
		cout << "Diangouzao" << endl;
	}
	~Dian(){
		cout << "Dianxixigou" << endl;
	}
};
//1.如果类有成员对象，那么先调用成员对象的构造函数，再调用本身的构造函数
//析构函数的调用顺序相反
//2.成员对象的构造函数调用和定义顺序一样
//3.注意。，如果有成员对象，那么实例化对象时，必须保证成员对象的构造和析构能被调用
void test01(){
	Dian c;
}
//初始化列表时调用成员对象的指定
class DDS1{
public:
	DDS1(int a){
		cout << "DDS1gouzao" << endl;
	}
	~DDS1(){
		cout << "DDS1xigou" << endl;
	}
};
class dds1{
public:
	dds1(int b){
		cout << "dds1gouzao" << endl;
	}
	~dds1(){
		cout << "dds1xixigou" << endl;
	}
};
class Dian1 {
private:
	DDS1 a;
	dds1 b;
public:
	Dian1():a(10),b(10){
		cout << "Dian1gouzao" << endl;
	}
	~Dian1(){
		cout << "Dian1xixigou" << endl;
	}
};
void test02(){
	
}
int main() {
	
	test01();
	return 0;
}