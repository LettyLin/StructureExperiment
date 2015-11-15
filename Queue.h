#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
template<class T>
struct Node
{
	T data;
	Node<T>* next;
};

template<class T>
class Queue
{
public:
	Queue(){ first = tail = NULL; }
	~Queue();
	T Front();
	bool IsEmpty();
	void Push(T& x);
	void Pop();
private:
	Node<T>* first;
	Node<T>* tail;
};

template<class T>
Queue<T>::~Queue()
{
	Node<T>* p = NULL;
	if (first)
	{
		p = first;
		first = first->next;
		delete p;
	}
}

template<class T>
T Queue<T>::Front()
{
	if (NULL == first)
	{
		return NULL;
	}
	else{
		return first->data;
	}
}

template<class T>
void Queue<T>::Push(T& x)
{
	Node<T>* p = new Node<T>;
	p->data = x;
	p->next = NULL;
	if (NULL != tail)
	{
		tail->next = p;
	}
	else{
		first = p;
	}
	tail = p;
}

template<class T>
void Queue<T>::Pop()
{
	Node<T>* p = first;
	first = first->next;
	delete p;
	if (NULL == first)
	{
		tail = NULL;
	}
}

template<class T>
bool Queue<T>::IsEmpty()
{
	return NULL == first&&NULL == tail;
}
#endif