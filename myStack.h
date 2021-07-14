#pragma once
#include <iostream>
#include <vector>
using namespace std;

// 实现一个手写栈
template <typename T>
class Stack
{ // public vector<T> 可以公有继承自向量基类，但是非栈顶元素会泄露，不推荐；
private:
	vector<T> data;

public:
	bool Empty();		   // check if this stack is empty
	void Push(T const &e); // add e to stack;
	void Pop();			   // remove item at top of the stack;
	T top();			   // return item at top of the stack
	void output();		   // display and pop all elements;
};

// implement the function above

template <typename T>
bool Stack<T>::Empty()
{ //check if this stack is empty
	return data.empty();
}

template <typename T>
void Stack<T>::Push(T const &e)
{ // add e to stack;
	data.push_back(e);
}

template <typename T>
void Stack<T>::Pop()
{ // remove item at top of the stack;
	data.pop_back();
}

template <typename T>
T Stack<T>::top()
{ // return item at top of the stack
	if (!data.empty())
		// return data.back();
		return data[data.size() - 1];
	else
		cout << "Stack is empty" << endl;
}
template <typename T>
void Stack<T>::output()
{ // display and pop all elements;
	while (!this->Empty())
	{
		cout << this->top(); // display the top element;
		this->Pop();		 // Pop the top element;
	}
	cout << endl;
}

// implement some algorithms

// 参考DSA MOOC
void convert(Stack<char> &s, _int64 n, int base)
{ // n:input number; base: base to convert;
	static char digit[] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	while (n > 0)
	{
		s.Push(digit[n % base]); // 余数入栈
		n /= base;				 // 更新商
	}
}