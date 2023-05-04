#include <iostream>
using namespace std;

const int aa = 10;//没有内存
void test01(){
	
	
	//常量折叠
	cout << aa << endl;//编译器偷偷改成： cout << 10 <<endl;
	
	volatile const int bb = 20; //栈区
	//加一个 volatile,禁止
	int *p = (int *)&bb;
	*p = 200;
	cout << bb << endl;//编译器偷偷改成： cout << 20 <<endl;
}
int main() {
	
	//test01();
	//c++语言中const修饰的全局变量具有内部连接属性
	extern const int C;
	cout << C << endl;
	return 0;
}