#pragma once

template<typename T>
class QueueLinked
{
public:
	QueueLinked();
	QueueLinked(const QueueLinked& other);
	QueueLinked& operator=(const QueueLinked& other);
	QueueLinked(const QueueLinked&& other);
	QueueLinked& operator=(const QueueLinked&& other);
	~QueueLinked();

public:
	void Enqueue(T value);
	void Dequeue();
	T Front() const;
	bool IsEmpty() const;
	int Size() const;

protected:
	template<typename U>
	struct Node
	{
		Node(U _value)
		{
			value = _value;
			next = nullptr;
		}

		U value;
		Node<U>* next;
	};
private:
	Node<T>* Head;
	Node<T>* Tail;
	int size;
};

template<typename T>
inline QueueLinked<T>::QueueLinked()
{
	Head = nullptr;
	Tail = nullptr;
	size = 0;
}

template<typename T>
inline QueueLinked<T>::QueueLinked(const QueueLinked& other)
{
}

template<typename T>
inline QueueLinked<T>& QueueLinked<T>::operator=(const QueueLinked& other)
{
	// TODO: insert return statement here
}

template<typename T>
inline QueueLinked<T>::QueueLinked(const QueueLinked&& other)
{
}

template<typename T>
inline QueueLinked<T>& QueueLinked<T>::operator=(const QueueLinked&& other)
{
	// TODO: insert return statement here
}

template<typename T>
inline QueueLinked<T>::~QueueLinked()
{
	if (!IsEmpty())
	{
		while (Head)
		{
			Node<T>* temp = Head;
			Head = Head->next;
			delete temp;
		}
	}
	Head = nullptr;
	Tail = nullptr;
}

template<typename T>
inline void QueueLinked<T>::Enqueue(T value)
{
	Node<T>* Temp = new Node<T>(value);

	if (IsEmpty())
	{
		Head = Temp;
		Tail = Temp;
		++size;
		return;
	}

	Tail->next = Temp;
	Tail = Temp;
	++size;
}

template<typename T>
inline void QueueLinked<T>::Dequeue()
{
	if (IsEmpty())
		return;

	Node<T>* temp = Head;

	if (Head == Tail)
	{
		Head = nullptr;
		Tail = nullptr;
		delete temp;
		size = 0;
		return;
	}

	Head = Head->next;
	delete temp;
	--size;
}

template<typename T>
inline T QueueLinked<T>::Front() const
{
	assert(!IsEmpty() && "Cannot access value from empty container");

	return Head->value;
}

template<typename T>
inline bool QueueLinked<T>::IsEmpty() const
{
	return Head == nullptr && Tail == nullptr && size == 0;
}

template<typename T>
inline int QueueLinked<T>::Size() const
{
	return size;
}