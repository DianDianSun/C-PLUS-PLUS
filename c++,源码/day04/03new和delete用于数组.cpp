#include <iostream>
using namespace std;

//1.new 创建基础类型的数组
void test01(){
	int *pint = new int[10] {1,2,3};
	for(int i = 0; i< 10 ;i++){
		cout << pint[i];
	}
	cout<<endl;
	char *pchar = new char[64];
	memset(pchar, 0, 64);
	strcpy(pchar, "diandianzhenkeai");
	cout << pchar;
	//注意：如果new时有中括号，那么delete时也要有中括号e
	delete[] pint;
	delete[] pchar;
}
class Dian{
public:
	Dian(){
		a = 10;
		cout << "gouzao"<<endl;
	}
	Dian(int a){
		cout << "youcangouzao" <<endl;
	}
	~Dian(){
		cout << "xigouzao"<<endl;
	}
public:
	int a;
};
void test02(){
	Dian **ms = new Dian*[2];//调用构造
	ms[0] = new Dian[3];
	ms[1] = new Dian[3];
	for(int i = 0;i< 2;i ++){
		for(int j = 0;j < 3 ; j++){
			cout << ms[i][j].a <<" ";
		}
		cout << endl;
	}
	delete[] ms;
}
//3.delete void*可能出错，不会调用队形的析构函数
void test03(){
	void *m = new Dian;
	
	//如果用void*来接new的对象，那么delete时不会调用析构函数
	
	delete m;
	//在编译阶段没那么编译器就确定好了函数的调用地址，
	//c++编译器不认识void*，不知道只想那个函数，所以不会调用析构
	//这种方式叫做静态联编

}
int main() {
	
	test03();
	return 0;
}