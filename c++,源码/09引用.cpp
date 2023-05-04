#include <iostream>
using namespace std;
void test01(){
	int a = 10;
	int &b = a;//给空间取别名叫b
	b = 100;
	cout << a <<endl;
}
void func(int &a){
	a = 200;
}
void test02(){
	int a = 10;
	func(a);
	cout << a << endl;
}
int main() {
	
	test01();
	test02();
	return 0;
}