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



## 06.函数重载🌟

## 07.函数重载的原理🌟

## 08.c++调用c语言的函数🌟

## 09.类和对象的概念🌟

## 10.类的封装🌟

## 11.类和结构体的区别