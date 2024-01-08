#pragma once
#include <iostream>

template<typename T>
class QueueArray
{

public:
	QueueArray(int _size);

	void Enqueue(T value); 
	void Dequeue();
	T Front() const;
	bool IsEmpty() const;

private: 
	T* valueArrPtr;
	int size;
	int front; 
	int rear;
};

template<typename T>
bool QueueArray<T>::IsEmpty() const
{

}

template<typename T>
T QueueArray<T>::Front() const
{

}

template<typename T>
void QueueArray<T>::Dequeue()
{

}

template<typename T>
QueueArray<T>::QueueArray(int _size)
	:size(_size), valueArrPtr(new T[size])
{
}

template<typename T>
inline void QueueArray<T>::Enqueue(T value)
{
}

