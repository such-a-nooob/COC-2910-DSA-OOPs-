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
#define beginning -1

using namespace std;

class linkedList
{
public:
	struct node
	{
		int item;
		node* loc; //to store the address of the next node	
	};

	node* start = NULL; //start is a pointer to the first node of the list

	//function to create a node
	node* createNode(int x=0)
	{
		node* temp = (node*)malloc(sizeof(node)); //allocating memory to a node
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
	linkedList l1;	//object of class linkedList to access its member methods
	int ch;
	do
	{
		int k,x;
		cout<<"\n\nA) SELECT THE OPERATION TO BE PERFORMED ON LINKED LIST\n  1. Insert\n  2. Delete\n  3. Search\n  4. Display\n  5. Find length\nB) EXIT (PRESS 0)";
		cout<<"\nEnter your choice : "; cin>>ch;
		switch(ch)
		{
			//Exit
			case 0: break;
			//Insert element X
			case 1:
				int c;
				//if list is empty, insert element at the very beginning and initialise the start pointer
				if(l1.isEmpty())
				{
					cout<<"\nEnter the element to be inserted : "; cin>>x;
					l1.insertX(0,x);
				}
				else
				{
					/*if list is not empty, the element can be inserted 
					-in the beginning
					-at the end, OR
					-after Kth element
					*/
					cout<<"\n\nA)WHERE DO YOU WANT TO INSERT?\n  1. In the BEGINNING of the list\n  2. At the END of the list\n  3. AFTER a node";
					cout<<"\nEnter you choice : "; cin>>c;
					switch(c)
					{
						case 1:
							cout<<"\nEnter the element to be inserted : "; cin>>x;
							l1.insertX(beginning,x);
							break;
						case 2:
							cout<<"\nEnter the element to be inserted : "; cin>>x;
							l1.insertX(l1.length(), x);
							break;
						case 3:
							cout<<"\nEnter the element to be inserted : "; cin>>x;
							cout<<"AFTER how many elements you want "<<x<<" to be inserted? "; 
							cin>>k;
							l1.insertX(k, x);
							break;
						default:
							cout<<"\nInvalid choice!";
					}
				}
				break;
			//Delete element from Kth position of the list
			case 2:
				cout<<"\nEnter the position of the element to be deleted : "; cin>>k;
				l1.deleteX(k, x);
				if(x) cout<<"\nElement "<<x<<" deleted from position "<<k;
				break;
			//Find an element X in the list
			case 3:
				cout<<"\nEnter the element to be searched : "; cin>>x;
				k = l1.find(x);
				if(k) cout<<"\nElement "<<x<<" found at position "<<k;
				else  cout<<"\nElement "<<x<<" not found!";
				break;
			//Display the entire list
			case 4:
				l1.display();
				break;
			//Display the number of elements in the list
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
	//create a node with the given element X
	node* temp;
	temp = createNode(x);

	//if list is empty, initialise the START pointer
	if(isEmpty())
		start = temp;
	//inserting in the beginning of the list
	else if(pos==beginning)
	{
		temp->loc = start;
		start = temp;
	}
	else if(pos>length())
	{
		cout<<"\nCan't Insert!\nThe position you entered exceeds the length of the list!";
		return;
	}
	//inserting the node after K elements 
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
	//can't delete element from an empty list obv dah!
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
	//deleting the first node, START pointer need to be changed
	else if(pos==1)
	{
		x = start->item;
		start = start->loc;
	}
	//deleting the Kth node
	else
	{
		node* ptr = start; //will point to the node to be deleted
		node* prev = start; //will point to the node previous to the desired node

		pos-=1; //to reach to the desired (Kth) node, (K-1) nodes are to be traversed
		while(pos!=0)
		{
			prev = ptr;
			ptr = ptr->loc;
			pos--;
		}
		prev->loc = ptr->loc; 
		x = ptr->item;
	}
	//X stores the element ie deleted
}

int linkedList::find(int x)
{
	int pos = 0;	//to store the position of element X in the list
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
	//START pointer will be null if there is no node in the list
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
