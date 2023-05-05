#include <iostream>
using namespace std;

class Dian{//这个是类
public:
	int a;//成员属性（成员变量）
	void func(){//成员方法（成员函数）
		cout << "func" << endl;
	}
};

int main() {
	
	Dian dian;//dian就是对象
	dian.func();
	return 0;
}