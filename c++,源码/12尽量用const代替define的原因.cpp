#include <iostream>
using namespace std;
#define MA 128
const short ma = 128;
void func(short a){
	cout <<"func(short a)" <<endl;
}
void func(int a){
	cout << "func(int a)"<< endl;
}
int main() {
	
	func(ma);
	return 0;
}