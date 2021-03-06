#include "pch.h"
#include <iostream>

using namespace std;
// define size of stack
#define SIZE 10

class stack
{
private:
	int arr[SIZE];
	int top;

public:
	stack();
	bool isEmpty();
	bool isFull();
	void push(int);
	int pop();
	void peek();
	int size();
};

stack::stack()
{
	top = -1;
}
bool stack::isEmpty()
{
	return top == -1;
}
bool stack::isFull()
{
	return top == SIZE - 1;
}

void stack::push(int x)
{
	if (isFull())
	{
		cout << "Stack is full"<<endl;
	}
	else
	{
		top++;
		arr[top] = x;
	}
}

int stack::pop()
{
	if (isEmpty())
	{
		cout << "Stack is enmpt";
	}
	else
	{
		int r =  arr[top];
		top--;
		return r;
	}
}
void stack::peek()
{
	if (!isEmpty())
		cout<<arr[top]<<endl;
}
int stack::size()
{
	return top + 1;
}


void main()
{
	stack pt;

	pt.push(1);
	pt.push(2);
	pt.push(10);
	pt.push(20);

	pt.peek();
	cout << pt.size() <<endl;
	cout<<endl<<"Removed: "<<pt.pop()<<endl;
	cout<< endl << "Removed: " << pt.pop()<<endl;
	getchar();
}