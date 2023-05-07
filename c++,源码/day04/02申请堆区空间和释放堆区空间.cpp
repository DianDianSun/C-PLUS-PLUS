#include <iostream>
using namespace std;

class Dian{
public:
	Dian(){
		cout << "gouzao"<<endl;
	}
	Dian(int a){
		cout << "youcangouzao" <<endl;
	}
	~Dian(){
		cout << "xigouzao"<<endl;
	}
};
void test01(){
	//用c语言方式申请堆区空间，不会调用构造函数，释放时不会析构
	Dian *m = (Dian *)malloc(sizeof(Dian));
	//释放时不会析构
	free(m);
}
void test02(){
	//用new方式申请堆区空间，会调用类的构造函数
	Dian *p = new Dian;
	
	//释放堆区空间，会调用类的析构函数
	delete p;
	
	//有参
	Dian *p1 = new Dian(10);
	
	delete p1;
}
int main() {
	
	test02();
	return 0;
}