// testSLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;


struct Node
{
	int data;
	Node * next;
	Node *prev;
};
class DList
{
private:

public:
	Node *head;
	Node *tail;
	DList()
	{
		head = NULL;
		tail = NULL;
	}
	Node* CreateNode(int val);
	bool IsEmpty();// check if DList is empty
	void InsertLast(int);// inserts at last position from DList
	void InsertFirst(int);// inserts at first position from DList
	void InsertAtIndex(int, int);//insert data at a specific position from DList
	void RemoveLast(); // removes last element from DList
	void RemoveFirst(); // remove first element from DList
	void RemoveAtIndex(int);// remove at some position
	void RemoveValue(int val);//removes a given value if found
	void Display(); // show all data in DList
	int  CountItems();// count the number of elements  in DList
	void Find(int);// search for an element in the DList
	Node* GetNodeAtIndex(int index);
	Node* GetNodeAtIndex(int index,int count);
	void DisplayReverse(); // show all data in reverse
	void SortList();
	void FindSum();
	int  CheckDuplicate(int);
	void Square();
	void CountEvenAndOdd();
};

Node* DList::CreateNode(int val)
{
	Node * temp = new Node;
	temp->data = val;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
bool DList::IsEmpty()
{
	return head == NULL;
}
void DList::Find(int val)
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
		cout << "\n" << val << " found at :" << index;
	}
	else
	{
		cout << "\n" << val << " NOT found ";
	}
}
void DList::SortList()
{
}
void DList::FindSum()
{
	int sum = 0;
	Node *temp = head;
	while (temp != NULL)
	{
		sum += temp->data;
	}

	cout << "\nSum is " << sum << endl;
}
int DList::CheckDuplicate(int val)
{
	int count = 0;
	Node *temp = head;
	while (temp!=NULL)
	{
		if (temp->data==val)
		{
			count++;
		}
	}
	return count;
}
void DList::Square()
{
	if (!IsEmpty())
	{
		Node * temp = head;
		while (temp != NULL)
		{
			temp->data = temp->data*temp->data;
			temp = temp->next;
		}
	}
}
void DList::CountEvenAndOdd()
{
	int Even = 0, Odd = 0;
	if (!IsEmpty())
	{
		Node * temp = head;
		while (temp != NULL)
		{
			if (temp->data % 2 == 0)
			{
				Even++;
			}
			else
			{
				Odd++;
			}
			temp = temp->next;
		}

		cout << "\nEven Numbers: " << Even << "Odd Numbers: " << Odd << endl;
	}
}
void DList::InsertLast(int val)
{
	if (head == NULL)
	{
		head = CreateNode(val);
		tail = head;
	}
	else
	{
		Node  * temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		Node * newNode = CreateNode(val);
		newNode->prev = temp;
		temp->next = newNode;
		tail = newNode;
	}
}
void DList::InsertFirst(int val)
{
	if (head == NULL)
	{
		head = CreateNode(val);
		tail = head;
	}
	else
	{
		Node  * newNode = CreateNode(val);
		newNode->next = head;
		head = newNode;
		newNode = NULL;
	}
}
void DList::InsertAtIndex(int val, int index)
{
	Node *temp = head;
	int count = 0;
	while (temp->next!=NULL && count<index)
	{
		count++;
		temp = temp->next;
	}
	if (index==count)
	{
		Node *newNode = CreateNode(val);
		newNode->prev = temp;
		newNode->next = temp->next;
		temp->next->prev= newNode;
		// or you can write like following
		//newNode->next->prev = newNode;
		temp->next= newNode;
	}
	else
	{
		cout << "\nCannot insert here.\n";
	}
	
}
Node* DList::GetNodeAtIndex(int index)
{
	int count = CountItems();
	if (count < index)
	{
		return NULL;
	}
	else
	{
		Node  *temp = head;
		int idx = 1;
		while (idx != index && temp != NULL)
		{
			temp = temp->next;
			idx++;
		}
		return temp;
	}
}
Node* DList::GetNodeAtIndex(int index, int count)
{
	if (count < index)
	{
		return NULL;
	}
	else
	{
		Node  *temp = head;
		int idx = 1;
		while (idx != index)
		{
			temp = temp->next;
			idx++;
		}
		return temp;
	}
}
int  DList::CountItems()
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
void DList::Display()
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
void DList::DisplayReverse()
{
	if (!IsEmpty())
	{
		Node * temp = tail;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->prev;
		}
	}
}
void DList::RemoveFirst()
{
	if (!IsEmpty())
	{
		if (head->next == NULL)
		{
			head = NULL;
		}
		else
		{
			//copy address of head to temp
			Node * temp = head;
			//now head contains address of next node
			head = head->next;
			//make previous NULL as it is first element
			head->prev = NULL;
			// Now delete the temp from memory
			delete temp;
		}
	}
	else
	{
		cout << "\nDList is empty\n";
	}
}
void DList::RemoveLast()//using tail
{
	if (!IsEmpty())
	{
		if (tail==head)
		{
			tail = head = NULL;
		}
		else
		{
			Node * temp = tail;
			tail = tail->prev;
			delete(temp);
		}
	}
	else
	{
		cout << "DList is empty" << endl;
	}
}
//void DList::RemoveLast()
//{
//	if (!IsEmpty())
//	{
//		Node * cur = head;
//		Node *temp=NULL;
//			while (cur->next != NULL)
//			{
//				temp = cur;
//				cur = cur->next;
//			}
//			// if there is one element then set head to NULL as well
//			if (cur==head)
//			{
//				head = NULL;
//				head->next = NULL;
//				head->prev = NULL;
//			}
//			delete(cur);
//	}
//	else
//	{
//		cout << "DList is empty" << endl;
//	}
//}
void DList::RemoveValue(int val)
{
	if (!IsEmpty())
	{
		if (head->data==val)
		{
			head = head->next;
			head->prev = NULL;
		}
		Node * cur = head;
		Node *temp = NULL;
		
		while (cur->next != NULL && cur->data==val)
		{
			temp = cur;
			cur = cur->next;
		}
		// if there is one element then set head to NULL as well
		if (cur->data == val)
		{
			
			delete(cur);
		}
		
	}
	else
	{
		cout << "DList is empty" << endl;
	}
}
void DList::RemoveAtIndex(int index)
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
				Node * prev = GetNodeAtIndex(index - 1, count);
				Node *temp = prev->next;
				prev->next = temp->next;

				delete temp;
			}
		}
	}
}

void main()
{
	DList L;

	L.InsertLast(50);
	L.InsertLast(20);
	L.InsertLast(30);
	L.InsertLast(40);
	L.InsertAtIndex(25, 1);
	L.Display();
	cout << endl;
	L.DisplayReverse();

	getchar();
}
