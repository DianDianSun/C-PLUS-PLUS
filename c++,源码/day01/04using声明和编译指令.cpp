#include <iostream>
using namespace std;

namespace A{
	int a = 10;
	int b = 20;
	int c = 30;
}
void test01(){
	
	//using声明是让命名空间中某个标识符可以直接使用点点真可爱
	using A::a;
	cout << a << endl;
	
	//int a = 50;注意：using声明了某个变量，在该作用域内不能定义同名的变量
}

void test02(){
	
	//using编译指令，让某个命名空间中的标识符都可以直接使用
	using namespace A;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	
	int a = 100;//为什么不冲突
	//类似于命名空间中的a是全局变量，这个是局部变量
	cout << a << endl;
}
int main() {
	
	test02();
	return 0;
}