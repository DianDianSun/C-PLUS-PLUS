#include <iostream>
using namespace std;


//结构体默认权限是公有的，类默认权限是私有的的
//结构体
struct Dian1{
	int a;
	void func(){
		
	}
public:
	int b;
};
struct Diansun : public Dian1{
	
};
//类
class Dian2{
	int a;
	void func(){
		
	}
public:
	int b;
};
int main() {
	
	
	return 0;
}