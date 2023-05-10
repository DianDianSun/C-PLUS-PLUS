#include <iostream>
using namespace std;

class Dian{
public:
	//1.当形参和成员变量名相同时，用this区分
	Dian(int id){
		this->id = id;
	}
	//2.返回对象的本身
	Dian &getDian(){
		return *this;//运算符重载时有用
	}
public:
	int id;
};
int main() {
	
}