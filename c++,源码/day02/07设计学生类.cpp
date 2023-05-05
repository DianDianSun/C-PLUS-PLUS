#include <iostream>
using namespace std;

class Student{
	
private://私有权限
	string name;
	string ID;
public:
	void Get_name_and_ID(string a,string b){
		name = a;
		ID = b;
	}
	void My_print(){
		cout << name << endl;
		cout << ID << endl;
	}
};

int main() {
	Student dian;
	dian.Get_name_and_ID("diandian","040825");
	dian.My_print();
	return 0;
}