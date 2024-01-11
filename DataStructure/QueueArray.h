#pragma once
#include <iostream>
#include <assert.h>

template<typename T>
class QueueArray
{

public:
	QueueArray(T _size);
	QueueArray& operator=(const	QueueArray& other);
	QueueArray(const QueueArray& other);



	~QueueArray();
	bool Enqueue(T value); 
	void Dequeue();
	T Front() const;
	bool IsEmpty() const;
	int Size() const;

private: 
	T* ArrPtr = nullptr;;
	int size = 0;
	int front = -1; 
	int rear = -1;
};

template<typename T>
QueueArray<T>& QueueArray<T>::operator=(const QueueArray& other)
{
	if (this != &other) 
	{
		size = other.size;
		front = other.front; 
		rear = other.rear; 

		delete ArrPtr;

		T* newTemp = new T[size];

		for (int i = 0; i < size; ++i) 
		{
			newTemp[i] = other.ArrPtr[i];
		}
		ArrPtr = newTemp;
	}

	return *this;
}

template<typename T>
QueueArray<T>::QueueArray(const QueueArray& other)
{
	*this = other;
}


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
QueueArray<T>::~QueueArray()
{
	delete [] ArrPtr;
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

