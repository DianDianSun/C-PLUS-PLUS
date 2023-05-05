#include <iostream>
using namespace std;

class Dian{
private:
	int id;
	int age;
	string name;
public:
//	读
	void setName(string Name){
		name = Name;
	}
//	写
	string getName(){
		return name;
	}
//	读
	void setAge(int Age){
		if(Age > 0 && Age < 150){
			age = Age;
		}
	}
//	写
	int getID(){
		return id;
	}
};

int main() {
	
	
	return 0;
}