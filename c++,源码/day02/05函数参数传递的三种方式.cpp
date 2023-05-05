#include <iostream>
using namespace std;


void myprint(int &a,int &b){
	cout << a <<" "<< b <<endl;
}
int main() {
	int a = 10,b = 20;
	swap3(a,b);
	myprint(a,b);
	return 0;
}