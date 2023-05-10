#include <iostream>
using namespace std;
//1.编译器知道类的声明，不知道类的结构；
class Building;
class GoodGay{
public:
	void func(Building &bud);
	
};
class Building{
	//声明
	friend void GoodGay::func(Building &bud);
public:
	Building(){
		keting = "keting";
		woshi = "woshi";
	}
public:
	string keting;
private:
	string woshi;
};
void GoodGay::func(Building &bud){
	cout << "访问" << bud.keting <<endl;
	cout << "卧室" << bud.woshi <<endl;
}
void  test(){
	Building bud;
	GoodGay Gf;
	Gf.func(bud);
}
int main() {
	
	
	test();
	return 0;
}