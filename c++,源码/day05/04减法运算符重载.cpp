#include <iostream>
using namespace std;

class Dian{
public:
	int id;
public:
	Dian(int id){
		this->id = id;
	}
//	Dian operator-(Dian &m1){
//		Dian m3(this->id - m1.id);
//		return m3;
//	}
};
Dian operator-(Dian &m1,Dian &m2)
{
	Dian m3(m1.id - m2.id);
	return m3;
}
void test()
{
	Dian m1(10);
	Dian m2(20);
	Dian m3 = m1 - m2;
	cout << m3.id << endl;
}
int main() {
	
	
	test();
	return 0;
}