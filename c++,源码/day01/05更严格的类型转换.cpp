#include <iostream>
using namespace std;

int main() {
	//这种方式不能进行隐式转换，必须是显示的转换
	//即 char *p = malloc(64);
	char *p = (char *)malloc(64);
	
	return 0;
}