#include<iostream>
#include"myStack.h"
using namespace std;

int main() {
	// ���Ի�������
	Stack <int> st;
	const int a[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
		st.Push(a[i]);
	st.output();

	// ���Խ���ת��
	Stack <char> s;
	convert(s, 2013,5);
	s.output(); 

	return 0;
}