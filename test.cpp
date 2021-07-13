#include<iostream>
#include"myStack.h"
using namespace std;

int main() {
	Stack <int> st;
	const int a[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++) {
		st.Push(a[i]);
	}
	st.output();

	return 0;
}