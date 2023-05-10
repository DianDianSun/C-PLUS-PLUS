#include <iostream>
using namespace std;

class Building{
	friend class Goodf;
	friend class Goodf2;
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

class Goodf{
public:
	void func(Building &a){
		cout << a.keting <<endl;
		cout << a.woshi <<endl;
	}
};
class Goodf2{
public:
	Building *pbu;
public:
	Goodf2(){
		pbu = new Building;
	}
	Goodf2(const Goodf2 &a){
		//1.申请空间
 		pbu = new Building;
		cout << "kkao";
	
	};
	void func(){
		cout << pbu->keting <<endl;
		cout << pbu->woshi<< endl;
	}
	~Goodf2(){
		if(pbu != NULL){
			delete pbu;
			pbu = NULL;
		}
	}
};
//1.通过传入参数来访问类的私有成员
void test01(){
	Building bd;
	Goodf f;
	f.func(bd);
}
void test02(){
	Goodf2 f;
	f.func();
	
	Goodf2 f2 = f;
}
//2.通过类内指针来访问类的私有成员
int main() {
	
	test02();
	return 0;
}