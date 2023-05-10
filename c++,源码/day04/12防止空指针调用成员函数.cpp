#include <iostream>
using namespace std;

class Dian{
private:
	int a;
public:
	Dian(){
		a = 20;
	}
	void print(){
		if(this == NULL){
			cout << "kong";
		}else{
			cout <<this->a <<endl;
		}
	}
};
void test(){
	Dian *a = NULL;
	a->print();
}
int main() {
	
	
	test();
	return 0;
}