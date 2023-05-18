#include <iostream>
using namespace std;

class Dian{
public:
	int id;
	int age;
public:
	Dian(int id,int age){
		this->id = id;
		this->age = age;
	}
};
class Sun{
public:
	int id;
public:
	Sun(int id){
		this->id = id;
	}
};
Dian operator+(Dian &m1,Sun &s1){
	Dian tmep(m1.id + s1.id,m1.age);
	
	return tmep;
}
void test(){
	Dian m1(1,18);
	Sun s1(2);
	Dian m2 = m1 + s1;
	cout << m2.id << m2.age<<endl;
}
int main() {
	
	test();
	
	return 0;
}