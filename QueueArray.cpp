
#include "pch.h"
#include <iostream>

using namespace std;

// Size of the queue
#define SIZE 10

class queue
{
	int arr[SIZE];		
	int front;		
	int rear;		
	int count;		

public:
	queue();		
	bool isEmpty();
	bool isFull();
	int size();
	void dequeue();
	void enqueue(int val);
	void peek();
};

queue::queue()
{
	front = 0;
	rear = -1;
	count = 0;
}

int queue::size()
{
	return count;
}

bool queue::isEmpty()
{
	return count== 0;
}

bool queue::isFull()
{
	return count == SIZE;
}

void queue::enqueue(int val)
{
	if (!isFull())
	{
		rear = (rear + 1) % SIZE;
		arr[rear] = val;
		count++; 
	}
	else
	{
		cout << "\nQueue OverFlow\n";
	}
}

void queue::dequeue()
{
	if (!isEmpty())
	{
		cout << "\nRemoved :" << arr[front] << endl;
		front = (front + 1) % SIZE;
		count--;
	}
	else
	{
		cout << "\nQueue is empty\n";
	}
}

void queue::peek()
{
	if (!isEmpty())
	{
		cout << "\nFirst element is: " << arr[front]<< endl;
	}
	else
	{
		cout << "\nQueue UnderFlow\n";
	}
}

int main()
{
	queue q;
	q.dequeue();
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(10);
	q.enqueue(20);
	q.dequeue();
	q.enqueue(30);

	q.peek();
	cout << endl << "Size: " << q.size();

	q.dequeue();
	q.dequeue();
	q.peek();
	 cout<<endl<<"Size: " << q.size();
	getchar();

}