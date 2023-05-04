#include <iostream>
using namespace std;

int main() {
	
	//普通引用
	int a = 10;
	int &ref = a;
	ref = 20;
	
	//int &ret2 = 10;//不能给自变量取别名
	const int &ref3 = 10;//可以给const修饰的引用赋予字面量
	//const 修饰符 修饰的引用的原理
	//编译器会吧上面的代码变为：int tmp = 10;const int &ref3 = tmp;
	
	
	//bool类型
	//bool类型定义的变量只有两个值true 和 false，真和假，1 和 0
	bool is = 0;//注意： is 的值除0 外都是真
	if (is){
		cout << "真" <<endl;
	}else{
		cout << "no" <<endl;
	}
	return 0;
}