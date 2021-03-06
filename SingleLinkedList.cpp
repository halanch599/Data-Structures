// testSLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;


struct Node
{
	int data;
	Node * next;
};
class List
{
private:
	
public:
	Node *head;
	List()
	{
		head = NULL;
	}
	bool IsEmpty();// check if list is empty
	void InsertLast(int);// inserts at last position from list
	void InsertFirst(int);// inserts at first position from list
	void InsertAtIndex(int,int);//insert data at a specific position from list
	void RemoveLast(); // removes last element from list
	void RemoveFirst(); // remove first element from list
	void RemoveAtIndex(int);// remove at some position
	void Display(); // show all data in list
	int  CountItems();// count the number of elements  in list
	void Find(int);// search for an element in the list
	Node* GetNodeAtIndex(int);// return the address of the a node at specific position	
	void FindMaximum();
	Node* MergeLists(Node* head1, Node* head2);
};

bool List::IsEmpty()
{
	return head == NULL;
}


void List::Find(int val)
{
	bool found = false;
	int index = 0;
	if (!IsEmpty())
	{
		Node * temp = head;
		while (temp != NULL)
		{
			++index;
			
			if (temp->data == val)
			{
				found = true;
				break;
			}
			temp = temp->next;
		}
	}
	if (found)
	{
		cout<<"\n"<< val <<" found at :" <<index;
	}
	else
	{
		cout << "\n" << val << " NOT found ";
	}
}


void List::InsertLast(int val)
{
	if (head == NULL)
	{
		head = new Node;
		head->data = val;
		head->next = NULL;
	}
	else
	{
		Node  * temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		//if(temp->data%2==0)
		//{ 
		Node * newNode = new Node;
		newNode->data = val;
		newNode->next = NULL;
		temp->next = newNode;
		//}
		//else
		//{
		//	cout << "Cannot insert after  odd." << endl;
		//}
	}
}
void List::InsertFirst(int val)
{
	if (head == NULL)
	{
		head = new Node;
		head->data = val;
		head->next = NULL;
	}
	else
	{
		Node  * temp = new Node;
		temp->data = val;
		temp->next = head;
		head = temp;
	}
}
void List::InsertAtIndex(int val, int index)
{
	int count = CountItems();
	if (index>count)
	{
		InsertLast(val);
	}
	else
	{
		if (index<=1)
		{
			InsertFirst(val);
		}
		else
		{
			Node * prev = GetNodeAtIndex(index - 1);
			Node *temp = new Node;
			temp->data = val;
			temp->next = prev->next;
			prev->next = temp;
		}
	}
}
Node* List::GetNodeAtIndex(int index)
{
	int count = CountItems();
	if (count<index)
	{
		return NULL;
	}
	else
	{
		Node  *temp = head;
		int idx = 1;
		while (idx!=index && temp!=NULL)
		{
			temp = temp->next;
			idx++;
		}
		return temp;
	}
}
int  List::CountItems()
{
	Node * temp = head;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
void List::Display()
{
	if (!IsEmpty())
	{
		Node * temp = head;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
}
void List::RemoveFirst()
{
	if (IsEmpty())
	{
		cout << "\nList is empty\n";
	}
	else
	{
		if (head->next == NULL)
		{
			head = NULL;
		}
		else
		{
			Node * temp = head;
			head = head->next;
			delete temp;
		}
	}
}
void List::RemoveLast()
{
	if (!IsEmpty())
	{
		Node * temp = head;
		if (temp->next == NULL)
		{
			head = NULL;
		}
		else
		{
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = NULL;
		}
	}
	else
	{
		cout << "List is empty"<<endl;
	}
}
void List::RemoveAtIndex(int index)
{
	int count = CountItems();
	if (index > count || index < 0)
	{
		cout << "\n Index out of range.";
	}
	else
	{
		if (index == 1)
		{
			RemoveFirst();
		}
		else
		{
			if (index == count)
			{
				RemoveLast();
			}
			else
			{
				Node * prev = GetNodeAtIndex(index - 1);
				Node *temp = prev->next;
				prev->next = temp->next;

				delete temp;
			}
		}
	}
}

void List::FindMaximum()
{
		Node * temp = head;
		//   initialize the int to the minimum int value;
		int max = INT_MIN;
		while (temp != NULL)
		{
			if (max < temp->data)
			{
				max = temp->data;
			}
			temp = temp->next;
		}

		if (max != INT_MIN)
		{
			cout << endl << "Max value :" << max;
		}
		else
		{
			cout << "\nList is empty.";
		}
}
void MyFunction(Node* head)
{
	if (head == NULL)
		return;
	MyFunction(head->next);
	cout<<head->data<<endl;
}

//int RecursiveFunc(int n)
//{
//	if (n == 1)
//		return n;
//	else 
//		return 2 * RecursiveFunc(n - 1);
//}

void RecursiveFunc(int n)
{
	if (n == 0)
		return;
	cout<<n % 2;
	RecursiveFunc(n / 2);
}

Node* List::MergeLists(Node* head1, Node* head2) {
	Node* temp = head1;
	while (head->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = head2;
	return head1;
}
void main()
{
//RecursiveFunc(8);
//
//
//cout << "\nEnd";
	List L1;

	L1.InsertLast(7);
	L1.InsertLast(1);
	L1.InsertLast(7);
	L1.Display();

	List L2;
	L2.InsertLast(3);
	L2.InsertLast(9);
	L2.InsertLast(6);

	List L;
	L.head = L.MergeLists(L1.head, L2.head);
	L.Display();
	//L.FindMaximum();
	//cout << endl;
	//MyFunction(L.head);

	//cout << endl;

	//L.Find(30);
	//L.Find(300);

	/*Node * temp = L.GetNodeAtIndex(2);
	if (temp!=NULL)
	{
		cout << endl << temp->data << endl;

	}*/

	//cout << endl << L.CountItems();



	getchar();
}
