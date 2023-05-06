#include <iostream>
using namespace std;

class Dian{
public:
	Dian(){
		cout << "wucan"<<endl;
	}
	Dian(int a){
		cout << "youcan"<<endl;
	}
	Dian(const Dian &m){
		cout << "copy"<<endl;
	}
	~Dian(){
		cout << "析构函数" << endl;
	}
};
void test01(){
	Dian();//匿名对象的生命周期在当前行
	Dian(10);
	cout << "over" << endl;
	
	//注意：如果匿名对象有名字来接，那么就不是匿名对象了
	Dian m1 = Dian();
}
int main() {
	
	test01();
	return 0;
}