#include<iostream>
#include"myStack.h"
using namespace std;

int main() {
	// 测试基本功能
	Stack <int> st;
	const int a[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
		st.Push(a[i]);
	st.output();

	// 测试进制转换
	Stack <char> s;
	convert(s, 2013,5);
	s.output(); 

	return 0;
}