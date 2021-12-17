/*

Write a program in C/C++ to implement a linear list data structure using linked list representation. In a linked list representation space allocation is done to each node on demand also each node stores the pointer to the next node of linked list and its integar ‘x’ data.

Implement the following functions/methods in the linked list :
1) insert(k,x), insert a new element x just after the k th element.  
2) delete(k,x), delete the kth element and return it in x. 
3) void display(), to print the complete linked list.
4) find(x), return the position of x in the linked list, return 0 if x is not found.
5) bool isempty(), return true if the list is empty, false otherwise.
6) int length(), return the number of elements in the linked list.

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/
#include <iostream>
#include <stdlib.h>

using namespace std;

class linkedList
{
public:
	struct node
	{
		int item;
		node* loc;	
	};

	node* start = NULL;

	node* createNode(int x=0)
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->item = x;
		temp->loc = NULL;
		return temp;
	}

	void insertX(int, int);
	void deleteX(int, int&);
	void display();
	int find(int);
	bool isEmpty();
	int length();
};

int main()
{
	linkedList l1;
	int ch;
	do
	{
		int k,x;
		cout<<"\n\nA) SELECT THE OPERATION TO BE PERFORMED ON LINKED LIST\n  1. Insert\n  2. Delete\n  3. Search\n  4. Display\n  5. Find length\nB) EXIT (PRESS 0)";
		cout<<"\nEnter your choice : "; cin>>ch;
		switch(ch)
		{
			case 0: break;
			case 1:
				int c;
					if(l1.isEmpty())
					{
						cout<<"\nEnter the element to be inserted : "; cin>>x;
						l1.insertX(0,x);
					}
					else
					{
						cout<<"\n\nA)WHERE DO YOU WANT TO INSERT?\n  1. In the BEGINNING of the list\n  2. At the END of the list\n  3. AFTER a node";
						cout<<"\nEnter you choice : "; cin>>c; 
						switch(c)
						{
							case 1:
								cout<<"\nEnter the element to be inserted : "; cin>>x;
								l1.insertX(1,x);
								break;
							case 2:
								cout<<"\nEnter the element to be inserted : "; cin>>x;
								l1.insertX(l1.length(), x);
								break;
							case 3:
								cout<<"\nEnter the element to be inserted : "; cin>>x;
								cout<<"After how many elements you want "<<x<<" to be inserted? "; 
								cin>>k;
								l1.insertX(k, x);
								break;
							default:
								cout<<"\nInvalid choice!";
						}
					}
				break;
			case 2:
				cout<<"\nEnter the position of the element to be deleted : "; cin>>k;
				l1.deleteX(k, x);
				if(x) cout<<"\nElement "<<x<<" deleted from position "<<k;
				break;
			case 3:
				cout<<"\nEnter the element to be searched : "; cin>>x;
				k = l1.find(x);
				if(k) cout<<"\nElement "<<x<<" found at position "<<k;
				else  cout<<"\nElement "<<x<<" not found!";
				break;
			case 4:
				l1.display();
				break;
			case 5:
				cout<<"\nNumber of elements in the Linear list : "<<l1.length();
				break;
			default:
				cout<<"\nInvalid choice!";
			}
	}while(ch!=0);
	return 0;
}

void linkedList::insertX(int pos, int x)
{
	//create a node with the given element
	node* temp;
	temp = createNode(x);

	if(isEmpty())
		start = temp;
	//inserting in the beginning of the list
	else if(pos==1)
	{
		temp->loc = start;
		start = temp;
	}
	else if(pos>length())
	{
		cout<<"\nCan't Insert!\nThe position you entered exceeds the length of the list!";
		return;
	}
	else
	{
		pos-=1;
		node* ptr = start;
		while(pos!=0)
		{
			ptr = ptr->loc;
			pos--;
		} 
		temp->loc = ptr->loc;
		ptr->loc = temp;
	}
}

void linkedList::deleteX(int pos, int &x)
{
	if(isEmpty())
	{
		cout<<"\nThe list is already empty!";
		x = 0;
		return;
	}
	if(pos>length())
	{
		cout<<"\nCan't Delete!\nThe position you entered exceeds the length of the list!";
		x = 0;
		//return;
	}
	else if(pos==1)
	{
		x = start->item;
		start = start->loc;
	}
	else
	{
		node* ptr = start;
		node* prev = start;

		pos-=1;
		while(pos!=0)
		{
			prev = ptr;
			ptr = ptr->loc;
			pos--;
		}
		prev->loc = ptr->loc; 
		x = ptr->item;
	}
}

int linkedList::find(int x)
{
	int pos = 0;
	if(isEmpty())
	{
		cout<<"\nList is empty!";
		return 0;
	}
	node* temp = start;
	while(temp!=NULL)
	{
		++pos;
		if(temp->item == x)	return pos;
		temp = temp->loc;
	}
	return 0;
}

void linkedList::display()
{
	node* temp = start;
	cout<<"\n";
	while(temp!=NULL)
	{
		cout<<temp->item<<"\t-->\t";
		temp = temp->loc;
	}
	cout<<"\\0";
}

bool linkedList::isEmpty()
{
	if(start == NULL)
		return true;
	else
		return false;
}

int linkedList::length()
{
	node* temp = start;
	int len = 0;
	while(temp!=NULL)
	{
		len++;
		temp = temp->loc;
	}
	return len;
}
