#include <iostream>
using namespace std;

//参数的个数不同
void func(){
	cout << "func()"<<endl;
}
void func(int n){
	cout << "func(int n)"<<endl;
}
//参数的类型不同
void func(char c){
	 cout << "func(char)"<<endl;
}
//参数的顺序不同
void func(int a,double n){
	cout << "func(int a,double n)";
}
void func(double n,int a){
	cout << "func(int a,double n)";
}
int main() {
	
	
	return 0;
}