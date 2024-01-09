#pragma once
#include <iostream>
#include <assert.h>

template<typename T>
class QueueArray
{

public:
	QueueArray(T _size);

	bool Enqueue(T value); 
	void Dequeue();
	T Front() const;
	bool IsEmpty() const;
	int Size() const;

private: 
	T* ArrPtr;
	int size;
	int front; 
	int rear;
};

template<typename T>
int QueueArray<T>::Size() const
{
	return size;
}

template<typename T>
QueueArray<T>::QueueArray(T _size)
	:size(_size)
{
	ArrPtr = new T[size];
	front = -1;
	rear = -1;
}

template<typename T>
bool QueueArray<T>::IsEmpty() const
{
	return front == -1 && rear == -1;
}

template<typename T>
T QueueArray<T>::Front() const
{
	assert(!IsEmpty());
	return ArrPtr[front];
}

template<typename T>
void QueueArray<T>::Dequeue()
{
	if (IsEmpty())
		return;

	if (front == rear)
	{
		front = -1;
		rear = -1;
		return;
	}

	front = front + 1 % size;
}

template<typename T>
inline bool QueueArray<T>::Enqueue(T value)
{
	if (IsEmpty()) 
	{
		front = 0; 
		rear = 0; 
		ArrPtr[rear] = value;
		return true;
	}

	if ((rear + 1) % size != front) 
	{
		rear = rear + 1 % size;
		ArrPtr[rear] = value;
		return true;
	}

	return false;
}

