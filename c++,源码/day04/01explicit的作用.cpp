#include <iostream>
using namespace std;
class Dian{
public:
	//explicit 只能放在构造函数前面，构造函数只有一个参数或其他参数有默认值时
	explicit Dian(int n){//防止编译器优化Dian m = 10这种格式
		
	}
};
void test01(){
	
}
int main() {
	
	Dian m = 10;//erro
	return 0;
}