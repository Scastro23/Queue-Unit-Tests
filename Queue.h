#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
public:
	Queue(int size_);
	~Queue();
	void enqueue(T data);
	T dequeue();
	T peek();
	bool isEmpty();
	bool isFull();

private:
	T* queue;
	int front;
	int rear;
	int size;
};

#endif // !QUEUE_H

template<class T>
inline Queue<T>::Queue(int size_)
{
	size = size_;
	queue = new T[size];
	front = -1;
	rear = -1;
}

template<class T>
inline Queue<T>::~Queue()
{
	delete[] queue;
}

template<class T>
inline void Queue<T>::enqueue(T data)
{
	if (isFull())
	{
		return;
	}
	if (isEmpty())
	{
		front = 0;
	}
	rear = (rear + 1) % size;
	queue[rear] = data;
}

template<class T>
inline T Queue<T>::dequeue()
{
	if (isEmpty())
	{
		return T();
	}
	T data = queue[front];

	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front = (front + 1) % size;
	}

}

template<class T>
inline T Queue<T>::peek()
{
	return queue[front];
}

template<class T>
inline bool Queue<T>::isEmpty()
{
	if (front == -1 && rear == -1)
	{
		return true;
	}
	return false;
}

template<class T>
inline bool Queue<T>::isFull()
{
	if ((rear + 1) % size == front)
	{
		return true;
	}
	return false;
}
