#include <iostream>
using namespace std;

void test01(){
	int a = 10;
	char* p = (char *)"diandiansun";
	int &B = a;
	char* &p1 = p;
	cout << B <<endl;
	cout << p1 <<endl;
}
//被调函数
void func(char *&temp){
	temp = (char *)malloc(64);
	memset(temp,0,64);
	strcpy(temp, "diandiansun01");
}
//主调函数
void test02(){
	char *mp = NULL;
	func(mp);
	cout << mp <<endl;
}
int main() {
	
	test01();
	test02();
	return 0;
}