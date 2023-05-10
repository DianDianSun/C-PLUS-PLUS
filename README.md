[TOC]

# DAY01

## 01.c++概述

> 基于c增加了<mark>**面向对象编程**</mark>和<mark>**泛型编程**</mark>的支持

## 02.第一个hello world

```c++
#include <iostream>
using namespace std;

int main() {
	
	cout<<"hello,world"<<endl;
	return 0;
}
```

## 03.面向对象的三大特征

- 封装
- 继承
- 多态

## 04.命名空间🌟

1.为什么有命名空间

>是因为解决多人合作时取标识符时重命名的问题

2.什么是命名空间

```c++
namespace A {//A是空间的名字
	int a;
	void func(){
		
	}
}
```

3.命名空间的注意事项

> 1.命名空间只能下在全局

> 2.命名空间可以嵌套命名空间

> 3.命名空间是开放的，随时可以加入新成员，但是新成员只能在加入后使用

> 4.匿名命名空间

>5.命名空间可以取别名

> 6.分文件编写代码是，如果h中有两个命名空间，但里面的成员函数或成员变量相同时，在cpp中需要加上命名空间



```c++
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
//命名空间是开放的，随时可以加入新成员，但是新成员只能在加入后使用
namespace Makeer {
	int c;
}
//匿名命名空间类似static int d = 50;
namespace{
	int d = 50;
}
//命名空间可以取别名
void tst01(){
	namespace newMakeer = Makeer;
	cout << newMakeer::c <<endl;
}
//分文件命名空间
test.h文件
#pragma once
using namespace std；
  
namespace myMaker1{
  void func();
}
namespace myMaker2{
  void func();
}

test.cpp文件
#include "test.h"
void myMaker1::func()//需要在函数名前面加入确定命名空间名字
{
  cout<<"666"<<endl;
}
```



4.作用域运算符

> 用来访问某个作用域里买呢成员 <mark>**::**</mark>

## 05.using声明和编译指令

1.using声明是让命名空间中某个标识符可以直接使用

```c++
namespace A{
	int a = 10;
	int b = 20;
	int c = 30;
}

void test01(){
	
	//using声明是让命名空间中某个标识符可以直接使用
	using A::a;
	cout << a << endl;
	
	//int a = 50;注意：using声明了某个变量，在该作用域内不能定义同名的变量
}
```

2.using编译指令，让某个命名空间中的标识符都可以直接使用

```c++
void test02(){
	
	//using编译指令，让某个命名空间中的标识符都可以直接使用
	using namespace A;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	
	int a = 100;//为什么不冲突
	//类似于命名空间中的a是全局变量，这个是局部变量
	cout << a << endl;
}
```

## 06.struct类型加强🌟

加强一：不需要加struct就可以定义变量

加强二：结构体可以写函数

```c++
struct Maker1{
	char name[64];
	int age;
};
//加强一：
void test1(){
	Maker1 a;//不需要加struct就可以定义变量
}
//加强二：
struct Maker2{
	int a;
	void func(){//结构体可以写函数
		cout << "func"<<endl;
	}
};
void test2(){
	Maker2 a2;
	a2.func();
}
```

## 07.更严格的类型转换

```c++
#include <iostream>
using namespace std;

int main() {
	//这种方式不能进行隐式转换，必须是显示的转换
	//即 char *p = malloc(64);
	char *p = (char *)malloc(64);
	
	return 0;
}
```

## 08.三目运算符

c++的三目运算符返回的是左值(空间，地址），c的三目运算符返回的是右值

```c++
#include <iostream>
using namespace std;

int main() {
	
	int a = 10;
	int b = 20;
	//c++的三目运算符返回的是左值，c的三目运算符返回的是右值
	(a > b ? a : b) = 100;
	cout<<"b:"<<b<<endl;
	cout<<"a:"<<a<<endl;
	return 0;
}
```



## 09.c/c++的const🌟

1.c语言的const修饰的变量都有空间

2.c语言的const修饰的全局变量具有外部连接属性

3.C++语言的const修饰的变量有时有空间，有时候没有空间(发生率常量折叠，且没有对变量进行取地址操作)

```c++
#include <iostream>
using namespace std;

const int aa = 10;//没有内存
void test01(){
	
	
	//常量折叠
	cout << aa << endl;//编译器偷偷改成： cout << 10 <<endl;
	
	volatile const int bb = 20; //栈区
	//加一个 volatile,禁止
	int *p = (int *)&bb;//进行了取地址操作，所以有空间
	*p = 200;
	cout << bb << endl;//编译器偷偷改成： cout << 20 <<endl;
}
int main() {
	
	test01();
	return 0;
}
```

4.c++语言中const修饰的全局变量具有内部连接属性

```c++
//const int C = 300;
extern const int C = 300;//加上extern便有了外部连接属性
```

5.C++你梦优化的情况

1.**不能优化自定义数据类型**

2.如果用变量给const**修饰的局部变量赋值**，**那么编译器就不能优化**

**3**.**编译器实在编译阶段来优化数据**

```c++
#include <iostream>
using namespace std;
void test(){
	int a = 10;
	const int b =a;//如果用变量给const修饰的全局变量赋值，那么编译器不会优化
	int *p = (int *)&b;
	*p = 100;
	cout << b << endl;
	cout << *p <<endl;
}


//自定义数据类型，编译器不能优化
struct Maker{
	Maker(){
		a = 100;
	}
	int a;
};
void test02(){
	const Maker ma;
	cout << ma.a <<endl;
	Maker *p = (Maker *)&ma;
	p->a = 200;
	cout << ma.a << endl;//没有进行优化，因为不能优化自定义函数
	
}

int main() {
	
	test02();
	return 0;
}
```

**6**.尽量用const来代替**define**

​     1.define没有数据类型，const修饰的变量有数据类型，可以进行数据类型检查

```C++
#define MA 128
const short ma = 128;
void func(short a){
	cout <<"func(short a)" <<endl;
}
void func(int a){
	cout << "func(int a)"<< endl;
}
int main() {
	
	func(ma);
	return 0;
}
```

​     2.const有作用域，define不重视作用域 ，没有常量的使用范围

## 10.引用🌟

1.引用做什么：和c语言的指针一样功能

2.引用是什么：引用时给空间取别名

3.引用的语法

```c++
void func(int &a){// int &a = a;
	a = 200;
}
void test02(){
	int a = 10;
	func(a);
	cout << a << endl;
}
```

4.引用的注意(这传参实在太爽了)

注意1: int &b = a；&不是取地址符号

```C++
#include <iostream>
using namespace std;
void func(int &b){
	b = 100;
}
int main() {
	
	int a = 20;
	func(a);
	cout << a << endl;
	return 0;
}
```

注意2:引用创建时，必须初始化。

```c++
int &pRef;err
```

注意3:引用一旦初始化不能改变它的指向

注意4:引用必须引用一块合法的内存空间

5.数组的引用

```c++
#include <iostream>
using namespace std;

int main() {
	
	int arr[] = {1,2,4,5};
	//第一种方法
	//1.定义数组类型
	typedef int(my)[4];//数组类型
	//2.建立引用
	my &p = arr;
	
	//第二种方法
	//直接定义引用
	int (&my2)[4] = arr;
	
	//第三种方法
	typedef int(&my3)[4];//建立引用数组类型
	my3 p2 = arr;
	return 0;
}
```

6.引用的本质

引用的本质是变异起再内部用常指针来实现

## 11.指针的引用🌟

1.指针的引用

```c++
//被调函数
void func(char *&temp){
	temp = (char *)malloc(64);
	memset(temp,0,64);
	strcpy(temp, "diandiansun01");
}
//主调函数
void test02(){
	char *mp = NULL;
	func(mp);
	cout << mp <<endl;
}
```

## 12.C和C++的区别

1. 1.c语言的结构体不能写函数，c++可以
2. 结构题定义变量时，c++不需要加struct
3. 更加严格的类型检查
4. const修饰的变量，c++有时没有内存，c语言的都有内存
5. 三目运算符返回的值不一样
6. 引用和c u语言的指针功能一样

# DAY02

## 01.引用的使用场景🌟

1.引用作为函数参数

```c++
//1.引用作为函数参数
void func(int &a,int &b){
	int sum = a + b;
	cout << sum << endl;
}
void test01(){
	int a =10;
	int b = 20;
	func(a,b);
}
```

2.引用作为函数 的 返回值

```c++
//2.引用作为函数的返回值
int &func2(){
	int b = 10;//注意1:不要返回局部变量栈区的引用
	int &p = b;
	return p;
}
int &func3(){
	static int b = 10;
	return b;
}
void test02(){
	int &q = func2();
	q = 100;
	cout << q << endl;
	
	func2() = 200;
	cout << q <<endl;
	//-----上面code是错的
	cout << func2() << endl;
	
	func3() = 100;//注意2:如果要函数当左值，一定要返回引用
	func3()++;
	cout << func3() << endl;
}
```

## 02.常量引用

```c++
  int &ret2 = 10;//不能给字面量取别名
	const int &ref3 = 10;//可以给const修饰的引用赋予字面量
	//const 修饰符 修饰的引用的原理
	//编译器会吧上面的代码变为：int tmp = 10;const int &ref3 = tmp;
```

## 03.内联函数

1.宏函数的缺陷

```c++
#define ADD(x,y) x+y
//在普通函数前面加上inline 是向编译器申请成为内联函数
//注意：加上inline可能成为内联函数
inline int Add(int x,int y){
	return x + y;
}
void test01(){
	int ref = ADD(10 ,20)*2;//
	cout << ref << endl;
	int ref2 = Add(10 , 20 )*2;
	cout << ref2 << endl;
}
#define COMAPD(x,y)  ((x)<(y)?(x):(y))
void test02(){
	int a = 1;
	int b = 3;
	//
	cout << COMAPD(++a,b) << endl;//3
}
```

2.什么情况不会成为内联函数

1. 存在过多的条件判断语句
2. 函数体过大
3. 对函数进行取址操作
4. 不能存在任何形式的循环语句

3.内联函数的好处

1. 有宏函数的效率，没有宏函数的缺点
2. 类的成员函数默认加上inline

4.函数前加上了inline 可申请位内联函数

## 04.函数的默认参数🌟

1.函数的默认参数就是给函数的形参赋值

```c++
int my_func(int a,int b = 0){//int b = 0;这就是函数的默认参数，不一定是0
	return a+b;
}
void test01(){
	//函数的恶默认参数的作用
	//当函数内常要用到形参的某个值，丹偶尔要使用其他值
	//增加函数的灵活性
	cout << my_func(10) <<endl;
	cout << my_func(10,200) <<endl;
}
```

2.函数默认参数的注意事项

```C++
//注意1: 函数的默认参数后面的参数必须都是默认参数
int fun3(int a,int b = 1, int c = 1,int d = 3){
	return a+b+c+d;
}
//注意2: 函数的声明和实现不能同时有参数的默认参数
void myfunc3(int a,int b = 1);
void myfunc3(int a,int b){
	
}
```

## 05.函数的占位参数

```c++
//函数的占位参数,占位参数阻碍后面运算符重载时区分前加加和后加加有用
void func(int a,int = 10){//占位参数也有默认值
	
}
void test02(){
	func(10);
}
//占位参数与默认参数混搭
void func3(int a = 20,int b = 20){
	
}
void test03(){
	func();
	func(10);
	func(10,30);
}

```

```c++
//值传递
void swap1(int a,int b){
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
//指针传递
void swap2(int *a,int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
//引用传递
void swap3(int &a,int &b){
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

```



## 06.函数重载(OVERLOAD)🌟

1.函数重载是：允许函数名相同，这种现象叫做函数重载

2.函数重载的作用：为了方便使用函数名

3.函数重载的条件：同一个作用域，参数的个数不同，参数的顺序不同，参数的类型不同

```c++
/参数的个数不同
void func(){
	cout << "func()"<<endl;
}
void func(int n){
	cout << "func(int n)"<<endl;
}
//参数的类型不同
void func(char c){
	 cout << "func(char)"<<endl;
}
//参数的顺序不同
void func(int a,double n){
	cout << "func(int a,double n)";
}
void func(double n,int a){
	cout << "func(int a,double n)";
}
```

4.调用函数重载的注意

1. 严格的类型匹配，如果类型不匹配，那么尝试转换，转换成功就调用，失败就报错

   ```c++
   void test01(){
   	int a =10;
   	double b = 3.14;
   	func();
   	//func(b);err double转换不来 int 或者char
   	
   	func(a,b);
   	char c = 'c';
   	func(c);//char 可以转换 int 成功，调用int参数的函数
   }
   ```

5.函数重载和函数的默认参数一起使用，需要注意二义性问题

```c++
//函数重载和函数的默认参数一起使用
void myfunc(int a,int b = 0){
	cout << "b" << endl;
}
void myfunc(int a){
	cout << "a" << endl;
}
void test02(){
	//myfunc(3);//err,二义性问题，不知道掉用哪个函数
}
```

6.函数的返回值不作为函数重载的条件

编译器是通过你调用函数时，传入的参数来判断调用重载的那个函数，我们调用函数时不需要写返回值，所以
返回值不能作为函数重载的条件

## 07.函数重载的原理🌟

1.函数重载的原理是在汇编时，给各个函数取别名，c语言不能重载的原因是没有取别名

## 08.c++调用c语言的函数🌟

1.c++的函数在汇编时，会给函数取别名，c语言的不会，这时，如果c++来调用c语言的函数，c++会取找取了别名的函数，但是c语言没有别名，这是会出错

```c++


//这是告诉c编译器，找下面的函数，要以c语言的方式去寻找
#ifdef _cplusplus
extern "C"
{
#endif

	void func();//c语言的函数声明

#ifdef _cplusplus
}
#endif
```



## 09.类和对象的概念🌟

1.类是自定义数据类型，是c语言的结构题进化而成的

2.对象是类实例化出的，用数据类型定义一个变量

```c++
#include <iostream>
using namespace std;

class Dian{//这个是类
public:
	int a;//成员属性（成员变量）
	void func(){//成员方法（成员函数）
		cout << "func" << endl;
	}
};

int main() {
	
	Dian dian;//dian就是对象
	dian.func();
	return 0;
}
```

## 10.类的封装🌟

1.封装是把属性（变量）和方法（函数）封装到类内，然后给这些数据赋予权限

2.为什么要有封装

1. 防止乱调用函数，变量，出现错误
2. 维护代码更方便

3.权限

```c++

//封装：1.把属性和方法封装到类中 2.给这些数据赋予权限
class Dian{
private://私有权限
	int id;
	string name;
public://公有权限
	void set(string Name,int ID){
		id = ID;
		name = Name;
	}
	void printDian(){
		cout << id <<" "<< name << endl;
	}
protected:
	int a;
};
class Sun : public Dian{
	void func(){
		a = 20;
	}
};
//类外不能访问私有权限
//类外可以访问公有权限
//类外不能访问保存权限的成员
//子类的类内可以访问父类的保护权限的成员
//类内没有权限之分
void MyPrint(){
	Dian dian;
	dian.set("dian",825);
	dian.printDian();
}

```

4.尽量把属性设置为私有权限

1. 可以控制属性的读写权限
2. 可赋予客户端访问数据的一致性
3. 可以保护属性的合法性

## 11.类和结构体的区别

结构体的默认权限是私有的，类的默认权限是私有的

# DAY03

## 1.立方体案例

1.抽象立方体：属性：长宽高，方法：设置和获取属性的方法

2.一个对象必须要初始化成员变量

3.成员函数中隐藏了一个本类的对象

## 2.点和圆的案例

so easy!

## 3.初始化和清理的案例

1. 当对象产生时，必须初始化成员变量，当对象销毁前，必须清理对象
2. 初始化用构造函数，清理用析构函数，这两个函数时编译器调用

4.构造函数和析构函数的注意

1. 构造函数和析构函数的权限必须时公有的
2. 构造函数可以重载
3. 构造函数没有返回值，不能用void，构造函数可以有参数，析构函数没有返回值，不能用void，没有参数 
4. 有对象产生必然会调用构造函数，有对象销毁必然会调用析构函数
5. 有多少个对象就会调用多少次，有多少个对象销毁就会调用多少次xi

## 4.构造函数🌟

1.初始化的作用和析构函数的作用

```c++
class Dian{
public:
	//构造函数的作用：初始化成员变量，是编译器进行的
	Dian(){
		a = 10;
		cout << "gouzaodiandain"<<endl;
	}
	//析构函数，在对象销毁前，编译器调用析构函数
	~Dian(){
		cout << "diandian"<<endl;
	}
public:
	int a;
};
void test01(){
	//实例化对象，内部做了两件事，1.分配空间 2.调用构造函数进行初始化
	Dian D;
	int b = D.a;
	cout << b << endl;
}
//析构函数的作用
class Dian2{
public:
	Dian2(const char*name,int age){
		cout <<"有参构造"<<endl;
		//从堆区申请空间
		pname = (char*)malloc(strlen(name)+1);
		strcpy(pname,name);
		mage = age;
	}
	~Dian2(){
		cout << "析构函数" <<endl;
		//释放堆区空间
		if(pname != NULL){
			free(pname);
			pname = NULL;
		}
	}
public:
	char *pname;
	int mage;
};
//有参构造函数
class Dian3{
public:
	//注意1:构造函数可以重载
	Dian3(){ 
		cout << "wucan"<<endl;
	}
	Dian3(int a){//有参构造函数
		cout << "youcan"<<endl;
	}
	~Dian3(){
		cout << "xigou"<<endl;
	}
};
void test02(){
	Dian2 d("diandian",19);
	cout << d.pname	<< d.mage << endl;
}
void test03(){
	Dian3 d;//当构造函数私有时，实例化不了对象
	Dian3 d1r(10);
	//有对象产生必然会调用构造函数，有对象销毁必然会调用析构函数
	//有多少个对象就会调用多少次，//有多少个对象销毁就会调用多少次xi
}
```

2.构造函数和析构函数的注意

1. 构造函数和析构函数的权限必须时公有的
2. 构造函数可以重载
3. 构造函数没有返回值，不能用void，构造函数可以有参数，析构函数没有返回值，不能用void，没有参数 
4. 有对象产生必然会调用构造函数，有对象销毁必然会调用析构函数
5. 有多少个对象就会调用多少次，有多少个对象销毁就会调用多少次xi

3.默认的构造函数和默认的析构函数

```c++
class Dian{
private:
	int a;
public:
	Dian(){//默认的构造函数，函数体是空的
		
	}
	~Dian(){//默认的析构函数，函数体是空的
		
	}
	//编译器默认提供默认的构造函数以及析构函数
	void printfDian(){
		a = 100;
		cout << a <<endl;
	}
};
```

4.拷贝构造函数

1. 什么是拷贝构造
2. 编译器提供了默认的拷贝构造

```c++
class Dian2{
public:
	Dian2(){
		cout << "wucan gouzao"<<endl;
		a = 20;
		b = 10;
	}
//默认提供了拷贝构造函数
//	Dian(const Dian &m){
//		a = m.a;	
//	}
	void print(){
		cout << a << b << endl;
	}
private:
	int a;
	int b;
};
```

3.拷贝构造的形参要用引用

## 5.构造函数的分类及调用🌟

1.构造函数的分类：无参构造函数，有参构造函数，拷贝构造函数

2.类默认提供了哪些函数：默认的构造函数，默认的析构函数，默认的拷贝构造函数，默认的赋值函数

3.构造函数的调用

```c++
	Dian m;//使用无参构造函数
	Dian m1(10);//使用有参构造函数
	Dian m2(m1);//使用拷贝构造函数
	
	//不常用
	Dian m4 = Dian(10);//使用的是有参构造函数
	Dian m3 = m2;//调用拷贝函数
	
	Dian m5 = 10;
	
	Dian m6;
	m6 = m5;//赋值操作
```

## 6.匿名对象

1.匿名对象的生命周期在当前行

```c++
void test01(){
	Dian();//匿名对象的生命周期在当前行
	Dian(10);
	cout << "over" << endl;
	
	//注意：如果匿名对象有名字来接，那么就不是匿名对象了
	Dian m1 = Dian();
}
```

## 7.拷贝构造函数调用的时机🌟

```c++
//1.对象以值方式给函数参数
void func(Dian m){//Dian m = m1;
	
}
void test01(){
	Dian m1;
	func(m1);
}
//2.用一个已有的的对象去初始化另一个对象
void  test02(){
	Dian m1;
	Dian m2(m1);
}
//3.函数的局部对象以值的方式从函数返回
//vs debug 模式下，会调用拷贝构造，vs release 模式下不会调用拷贝构造，qt也不调用
Dian fun2(){
	//局部对象
	Dian m;
	cout << &m <<endl;
	return m;
	
}
void test03(){
	Dian m1 = fun2();
	
	cout << &m1 <<endl;
}
```



## 8.拷贝构造函数的调用规则🌟

1.如果程序员提供了有参构造，那么编译器不会提供默认构造函数，但会提供默认的拷贝构造

```c++
//如果程序员提供了有参构造，那么编译器不会提供默认构造函数，但会提供默认的拷贝构造
void test01(){
	//Dian a;erro
	Dian m(10);//调用了有参构造
	Dian m1(m);//调用了默认拷贝构造
}
```

2.如果程序员提供了拷贝构造函数，那么编译器不会提供默认的构造函数和默认的拷贝函数

```c++
//Dian m;error
```



## 9.多个对象的构造和析构🌟

1.如果类有成员对象，那么先调用成员对象的构造函数，再调用本身的构造函数

析构函数的调用顺序相反

2.成员对象的构造函数调用和定义顺序一样

3.注意。，如果有成员对象，那么实例化对象时，必须保证成员对象的构造和析构能被调用

```c++
class DDS{
public:
	DDS(){
		cout << "DDSgouzao" << endl;
	}
	~DDS(){
		cout << "DDSxigou" << endl;
	}
};
class dds{
public:
	dds(){
		cout << "ddsgouzao" << endl;
	}
	~dds(){
		cout << "ddsxixigou" << endl;
	}
};
class Dian {
private:
	DDS a;
	dds b;
public:
	Dian(){
		cout << "Diangouzao" << endl;
	}
	~Dian(){
		cout << "Dianxixigou" << endl;
	}
};
```

2.初始化列表

1.初始化列表是干什么用的，指定调用成员对象的某个构造函数

2.初始化列表只能写在构造函数中

3.如果有多个对象需要指定调用某个构造函数，用逗号隔开

4.如果使用了初始化列表，那么所有的构造函数都要写初始化列表

5.可以使用对象的构造函数传递数值给成员对象的变量

```c++
class dds1{
public:
	dds1(int b){
		cout << "dds1gouzao" << endl;
	}
	~dds1(){
		cout << "dds1xixigou" << endl;
	}
};
class Dian1 {
private:
	DDS1 a;
	dds1 b;
public:
	Dian1():a(10),b(10){
		cout << "Dian1gouzao" << endl;
	}
	~Dian1(){
		cout << "Dian1xixigou" << endl;
	}
};
```



## 10.对象的深浅拷贝🌟

1.默认的拷贝构造函数进行了简单的赋值操作（浅拷贝）

2.浅拷贝的缺点

//同一块空间呗是放两次

```c++
void test02(){
	Student s1("DianDian",19);
	Student s2(s1);
	
	cout << s1.pname<< " "<< s1.age << endl;
	cout << s2.pname<< " "<< s2.age << endl;
}
```

深拷贝

```c++
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
```



# DAY04

## 01.explicit的作用

```c++
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
```

## 02.C++的堆区空间的申请和释放🌟

1.申请和释放变量空间

1. 为什么新方法

   因为要用构造和析构函数

2.  哪些函数关键字

   new ，delete

```c++
class Dian{
public:
	Dian(){
		cout << "gouzao"<<endl;
	}
	Dian(int a){
		cout << "youcangouzao" <<endl;
	}
	~Dian(){
		cout << "xigouzao"<<endl;
	}
};
void test01(){
	//用c语言方式申请堆区空间，不会调用构造函数，释放时不会析构
	Dian *m = (Dian *)malloc(sizeof(Dian));
	//释放时不会析构
	free(m);
}
void test02(){
	//用new方式申请堆区空间，会调用类的构造函数
	Dian *p = new Dian;
	
	//释放堆区空间，会调用类的析构函数
	delete p;
	
	//有参
	Dian *p1 = new Dian(10);
	
	delete p1;
}
```

2.申请和释放数列空间

1. new创建基础类型的数组

   ```c++
   //1.new 创建基础类型的数组
   void test01(){
   	int *pint = new int[10] {1,2,3};
   	for(int i = 0; i< 10 ;i++){
   		cout << pint[i];
   	}
   	cout<<endl;
   	char *pchar = new char[64];
   	memset(pchar, 0, 64);
   	strcpy(pchar, "diandianzhenkeai");
   	cout << pchar;
   	//注意：如果new时有中括号，那么delete时也要有中括号e
   	delete[] pint;
   	delete[] pchar;
   }
   ```

2. new创建对象数组

   ```c++
   class Dian{
   public:
   	Dian(){
   		a = 10;
   		cout << "gouzao"<<endl;
   	}
   	Dian(int a){
   		cout << "youcangouzao" <<endl;
   	}
   	~Dian(){
   		cout << "xigouzao"<<endl;
   	}
   public:
   	int a;
   };
   void test02(){
   	Dian **ms = new Dian*[2];//调用构造
   	ms[0] = new Dian[3];
   	ms[1] = new Dian[3];
   	for(int i = 0;i< 2;i ++){
   		for(int j = 0;j < 3 ; j++){
   			cout << ms[i][j].a <<" ";
   		}
   		cout << endl;
   	}
   	delete[] ms;
   }
   ```

3. delete void*肯出错，不会调用对象的析构函数

   ```c++
   //3.delete void*可能出错，不会调用队形的析构函数
   void test03(){
   	void *m = new Dian;
   	
   	//如果用void*来接new的对象，那么delete时不会调用析构函数
   	
   	delete m;
   	//在编译阶段没那么编译器就确定好了函数的调用地址，
   	//c++编译器不认识void*，不知道只想那个函数，所以不会调用析构
   	//这种方式叫做静态联编
   
   }
   ```

 4.c和c++的申请和释放堆区空间不要混用

3.和c的共同和区别之处

## 03.静态成员

```c++
class Dian{
public:
	//1.静态成员的身影周期时整个程序 作用域在类内
	static int a;
};
//2.静态成员变量要在类内声明，类外初始化
int Dian::a = 100;
void test01(){
	//3.静态成员它属于类不属于对象，是所有对象共享的
	cout << Dian::a <<endl;
	//4.静态成员变量可以用类访问，也可以用对象访问
	Dian m;
	cout << m.a << endl;
}
```

5.//静态成员函数只能访问静态成员变量，不能访问普通成员变量

6.静态成员也有权限，如果为私有 类外也不可以访问

7.const修饰的静态成员变量最好在类内初始化

```c++
class Dian{
public:
   const static int a = 20;
   const static int b;
}；
//类外也可以初始化
const int Dian::b  = 30;
```

8.普通函数也可以访问静态成员变量

## 04.C++的对象模型🌟

1. 空类的大小是1
2. 类的成员不占用类的大小，静态成员比例不占用类的大小，静态成员函数不占用类的大小
3. 普通成员占用类的大小
4. 类的成员中，成员函数和成员变量是分开储存的

## 05.this指针🌟

1.每个对象都有一个隐藏的this指针，但不属于对象，是编译器添加的

2.编译器会把this指针传入成员函数内

3.this指针指向对象的存储空间

4.this的作用

```c++
class Dian{
public:
   //1.当形参和成员变量名相同时，用this区分
   Dian(int id){
     this->id = id;
   }
   //2.返回对象的本身
   Dian &getDian(){
      return *this;//运算符重载时有用
   }
public:
   int id;
}
```

5.拓展

1. this指针指向的空间有没有储存静态成员变量

   没有，

2. this指针的指向可以改变吗

   不能 this jiu

## 06.常函数和常对象🌟

1.常函数

1. 在函数的后面加上const 就变成常函数
2. 常函数内不能修改普通成员变量
3. const 修饰的是this指针指向的空间的变量不能改变 
4. mutable 修饰的成员变量在常函数中可以修改

```c++

class Dian{
public:
	int mId;
	int mAge;
	mutable int sorce;
public:
	Dian(int id,int age){
		mAge = age;
		mId = id;
	}
	//常函数,1.函数的()后main加上const，该函数变为常函数
	void print()const{
		//id = 100;err  2.常函数内不能修改普通成员变量
		//3.const 修饰的是this指针指向的空间的变量不能改变
		//Dian *const this
		//const Dian *const this ,这是常函数修饰的
		sorce = 100;//4.mutable 修饰的成员变量在常函数中可以修改
	}
};

```

2.常对象

1. 在数据类型前加上constant，让对象成为常对象
2. 常对象可以调用常函数
3. 常对象可以调用mutable的值 

```c++
class Dian{
public:
	int mId;
	int mAge;
	mutable int sorce;
public:
	Dian(int id,int age){
		mAge = age;
		mId = id;
	}
	//常函数,1.函数的()后main加上const，该函数变为常函数
	void print()const{
		//id = 100;err  2.常函数内不能修改普通成员变量
		//3.const 修饰的是this指针指向的空间的变量不能改变
		//Dian *const this
		//const Dian *const this ,这是常函数修饰的
		sorce = 100;//4.mutable 修饰的成员变量在常函数中可以修改
	}
};
void test(){
	//1.在数据类型前加上constant，让对象成为常对象
	const Dian m(1,18);//常对象
	//m.mId = 100;//erro 常对象不能改变普通变量成员变量的值
	//m.print;//擦好难过对象不能调用普通成员函数
	m.print();//常对象可以调用常函数
	m.sorce = 1;//常对象可以调用常函数
		
}
```

## 07.友元🌟

- 友元的概念

友元是赋予全局函数，或者类的成员函数，类有访问别的类的私有成员权限

注意：友元函数不会死类的成员函数q

1.全局友元函数

```c++
class Building{
	//声明全局变量为Building类的友元函数
	friend void GoodGay(Building &a);
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

void GoodGay(Building &a){
	cout << "haojiyou"<<a.keting <<endl;
	cout << "sfasfs" << a.woshi <<endl;
}
void test01(){
	Building a;
	GoodGay(a);
}
```

2. 友元类

   ```c++
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
     //通过传入指针来friend
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
   ```

3.类的友元成员函数（难点）

```c++
//1.编译器知道类的声明，不知道类的结构；
class Building;
class GoodGay{
public:
	void func(Building &bud);
	
};
class Building{
	//声明
	friend void GoodGay::func(Building &bud);
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
void GoodGay::func(Building &bud){
	cout << "访问" << bud.keting <<endl;
	cout << "卧室" << bud.woshi <<endl;
}
void  test(){
	Building bud;
	GoodGay Gf;
	Gf.func(bud);
}
```

4.友元的注意

1. 友元关系不能被继承
2. 友元关系是单向的，A是B的朋友，反过来不一定
3. 友元关系不具有传递性

## 08.单例模式🌟

1.单例模式是一个类只能实例化一个对象

2.实现单例化模式的思路

1. 把午餐构造函数和拷贝构造函数私有化

2. 定义一个类内的静态成员指针

3. 在类外初始化，new一个对象

4. 把指针的权限设置为私有，然后提供一个静态成员函数让外面获取这个指针

   