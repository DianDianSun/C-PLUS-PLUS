#include <iostream>
using namespace std;


class Building{
	//声明全局变量为Building类的友元函数
	friend void GoodGay(Building &a);
public:
	Building(){
		keting = "keting";
		woshi = "woshi";
	}
public:
	string keting;
private:
	string woshi;
};

void GoodGay(Building &a){
	cout << "haojiyou"<<a.keting <<endl;
	cout << "sfasfs" << a.woshi <<endl;
}
void test01(){
	Building a;
	GoodGay(a);
}
int main() {
	
	test01();
	return 0;
}