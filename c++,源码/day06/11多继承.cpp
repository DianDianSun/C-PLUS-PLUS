#include <iostream>
using namespace std;

class Father1
{
public:
	int bmw;
};
class Father2
{
public:
	int bmw;
};
class son : public Father1,public Father2
{
	
};
void test01()
{
	son s;
	//s.bmw;有二义性的问题
}
int main()
{
	
	
	
	return 0;
}