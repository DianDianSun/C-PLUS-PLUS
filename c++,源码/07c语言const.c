#include <stdio.h>


const int a = 10;//常量区，一旦初始化，不能修改

void test(){
	//a = 200;//全局的const不能直接修改
	int *p = (int *)&a;
	//*p = 100;//全局的const不能间接修改
	printf("%d\n",a);
}
int main() {
	
	const int b = 520;//展区
	//b= 200 // 局部的const修饰的变量不能直接修改
	int *p = (int *)&b;
	*p = 200;
	int c = b + 2;
	printf("%d",c);
	return 0;
}