#include <iostream>
using namespace std;

#define ADD(x,y) x+y
//在普通函数前面加上inline 是向编译器申请成为内联函数
//注意：加上inline可能成为内联函数
inline int Add(int x,int y){
	return x + y;
}
void test01(){
	int ref = ADD(10 ,20)*2;//
	cout << ref << endl;
	int ref2 = Add(10 , 20 )*2;
	cout << ref2 << endl;
}
#define COMAPD(x,y)  ((x)<(y)?(x):(y))
void test02(){
	int a = 1;
	int b = 3;
	//
	cout << COMAPD(++a,b) << endl;//3
}
int main() {
	
	test02();
	return 0;
}