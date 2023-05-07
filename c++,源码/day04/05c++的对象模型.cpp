#include <iostream>
using namespace std;
//1.空类的大小时1，不是0

class Dian{
	 
	
};
class Dian2{
public:
	void func(){
		int a;
	}
	static int a;
};
void test01(){
	cout << sizeof(Dian2);
	//为什么空类是1，英文编译器从内存更好区分对象
}
int main() {
	
	test01();
	return 0;
}