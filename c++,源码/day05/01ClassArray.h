//
// ClassArray.h
// Created by 赵旭日 on 2023/5/18.

#ifndef _ClassArray_h_
#define _ClassArray_h_
#include <iostream>
using namespace std;
class MyArray{
public:
	MyArray();
	MyArray(const MyArray &a);
	MyArray(int capacity,int val = 0);
	
	//重写赋值运算符重载函数
	MyArray &operator=(const MyArray &m);
	
	int &operator[](int index);
	
	~MyArray();
	//头插
	void PushFront(int val);
	//尾插
	void PushBack(int val);
	//头删
	void PopFront();
	//尾珊
	void PopBack();
	//获取数组元素个数
	int Size();
	//获取数组容量
	int Capacity();
	//指定位置插入元素
	void Insert(int pos,int val);
	//获取指定位置的值
	int &Get(int pos);
	//在指定位置修改值
	void Set(int pos,int val);
private:
	int *pArray;//指向堆区空间，存储数据
	int mSize;//元素个数
	int mCapacity;//容量
};


#endif