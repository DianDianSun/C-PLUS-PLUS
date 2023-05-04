#include <iostream>
using namespace std;

int main() {
	
	int arr[] = {1,2,4,5};
	//第一种方法
	//1.定义数组类型
	typedef int(my)[4];//数组类型
	//2.建立引用
	my &p = arr;
	
	//第二种方法
	//直接定义引用
	int (&my2)[4] = arr;
	
	//第三种方法
	typedef int(&my3)[4];//建立引用数组类型
	my3 p2 = arr;
	return 0;
}