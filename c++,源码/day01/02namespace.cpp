#include <iostream>
using namespace std;

//命名空间
namespace A {//A是空间的名字
	int a;
	void func(){
		
	}
}
//命名空间可以嵌套命名空间
namespace Makeer {
	int a;
	namespace B{
		int b;
	}
}
//
namespace Makeer {
	int c = 30;
}
static int e = 50;
//匿名命名空间类似static int d = 50;
namespace{
	int d = 50;
}
//命名空间可以取别名
void tst01(){
	namespace newMakeer = Makeer;
	cout << newMakeer::c <<endl;
}
int mya = 10;
int main() {
	
	int mya = 20;
	Makeer::c = 10;
	d = 60;
	cout<<Makeer::c<<endl;
	cout<<d<<endl;
	e = 70;
	cout<<e<<endl;
	tst01();
	return 0;
}