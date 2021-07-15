#pragma once
#include<iostream>
template<class ElemType> class Node {
public:
	ElemType data;// data field
	Node<ElemType>* next;
	Node(ElemType e, Node* t) {	// initialize a Node object
		this->data = e;
		this->next = t;
	}
};

template<class ElemType> class Queue {
private:
	Node<ElemType>* front;		// begin of queue
	Node<ElemType>* rear;		// end of queue
	int size;
public:
	Queue() { front = rear = nullptr; size = 0; }
	~Queue() { clear(); }
	void clear();
	bool empty() { return size == 0; }	// if empty,return true;
	int getSize() { return size; }
	bool EnQueue(ElemType item);
	bool DeQueue();

	void diaplay();	// Diaplay all the elements
	ElemType getFront() { return front->data; }
	ElemType getRear() { return rear->data; }

};

template<class ElemType> void Queue<ElemType>::clear() {
	while (DeQueue());
}

template<class ElemType> bool Queue<ElemType>::EnQueue(ElemType item) {	// insert item
	Node<ElemType>* tmp = new Node<ElemType>(item, nullptr);
	if (front==nullptr) { front = tmp; rear = tmp; }
	else { rear->next = tmp; rear = tmp; }
	size++;
	return true;
}

template<class ElemType>bool Queue<ElemType>::DeQueue() {	// remove the first item
	if (front == nullptr)return false;
	Node<ElemType>* tmp = front;
	front = front->next;
	delete tmp;
	size--;
	return true;
}

template<class ElemType> void Queue<ElemType>::diaplay() {	// display all the elements and clear
	while (!empty()) {
		cout << this->getFront();	// get the front element
		this->DeQueue();
	}
	cout << endl;
}