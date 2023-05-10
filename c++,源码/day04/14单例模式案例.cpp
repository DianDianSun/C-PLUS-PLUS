#include <iostream>
using namespace std;

//需要，获取打印机使用的次数
class Printer{
private:
	int actimes;//记录打印次数
private:
	//1.把无参构造和拷贝私有化
	Printer(){
		actimes = 0;
	}
	Printer(const Printer&a){}
public:
	static Printer *getp(){
		return p;
	}
	void printp(string name){
		cout << name << "print"<<endl;
		actimes++;
	}
	int getact(){
		return actimes;
	}
private:
	static Printer *p;//定义静态成员指针
};
//3.类外初始化，new对象
Printer *Printer::p = new Printer; 

void test(){
	Printer *p1 = Printer::getp();
	p1->printp("sell");
	Printer *p2 = Printer::getp();
	p1->printp("technology");
	Printer *p3 = Printer::getp();
	p1->printp("gongguan");
	cout << p1->getact()<<endl;
}
int main() {
	
	test();
	
	return 0;
}