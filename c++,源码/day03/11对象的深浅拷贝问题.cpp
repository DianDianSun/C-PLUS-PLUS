#include <iostream>
using namespace std;

class Dian {
public:
	int mId;
	int mAge;
public:
	Dian(int id,int age){
		mId = id;
		mAge = age;
	}
};
void test01(){
	Dian m1(1,18);
	Dian m2(m1);
	
	cout << m1.mId<<" "<<m1.mAge<<endl;
	cout << m2.mId<<" "<<m2.mAge<<endl;
	
	/*
	m2.mId = m1.mId;
	m2.mAge = m1.mAge;
	*/
}
class Student{
public:
	Student(const char*name,int Age){
		pname = (char *)malloc(strlen(name)+1);
		strcpy(pname,name);
		age = Age;
	}
	//深拷贝
	Student(const Student &m){
		//1.分配空间
		pname = (char*)malloc(strlen(m.pname)+1);
		//2.拷贝
		strcpy(pname, m.pname);
		age = m.age;
	}
	~Student(){
		if(pname != NULL){
			free(pname);
			pname = NULL;
		}
	}

public:
	char *pname;
	int age;
};
void test02(){
	Student s1("DianDian",19);
	Student s2(s1);
	
	cout << s1.pname<< " "<< s1.age << endl;
	cout << s2.pname<< " "<< s2.age << endl;
}
int main() {
	
	test02();
	return 0;
}