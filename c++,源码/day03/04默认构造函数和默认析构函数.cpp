#include <iostream>
using namespace std;
class Dian{
private:
	int a;
public:
	Dian(){//默认的构造函数，函数体是空的
		
	}
	~Dian(){//默认的析构函数，函数体是空的
		
	}
	//编译器默认提供默认的构造函数以及析构函数
	void printfDian(){
		a = 100;
		cout << a <<endl;
	}
};
int main() {
	
	Dian a;
	return 0;
}