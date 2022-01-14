/*

Write a program in C++ for binary tree that implement following methods:
Create(P, X) : P is location of parent of node which is to be created, X is either Left or Right.
Delete(N): N is location of node which is to be deleted. If the node to be deleted is an internal node, fill the space vacated by deleted node by moving the last node (rightmost node at the last level) to the vacant space.
Display() : display the entire binary tree (information and location of each node, location of its left and right children)
Search(v): v is some value, search all node(s) n having value equal to v and print the location of those node(s). Also print the location of parent of those node(s).

Also, implement the inorder, preorder and postorder traversal of binary tree.
Your program should implement two classes. One class should use sequential representation. Second class should use linked representation using arrays.

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

#include<iostream>
#include <math.h>

#define SIZE 10
#define null 0
#define MAX 1000

using namespace std;

class Sequential
{
	int tree[MAX], depth, size;
public:
	
	void initialise()
	{
		cout<<"\nEnter the maximum DEPTH of the tree : ";
		cin>>depth;
		size = pow(2, depth+1)-1;
		for(int i=1; i<=size; i++)
			tree[i] = null;
	}
	
	bool isEmpty()
	{
		if(tree[1] == null)
			return true;
		else
			return false; 
	}
	void findParent(int);
	void Create(int, int=0, char='l');
	void findLast();
	int Delete(int);
	void Display();
	int Search(int);
};

struct node
{
	int info;
	node* left;
	node* right;
};

node* root = NULL;

class LinkedLists
{
public:
	node* createNode(int x)
	{
		node *temp;
		temp = (node*)malloc(sizeof(node));
		temp->info = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}

	bool isEmpty();
	void Create(int, int=0, char='l');
	int Delete(int);
	void Display(node*, int, int=-1);
	int Search(node*, int, int=-1);
};

int flag;

int main()
{
	Sequential S;
	int ch, ch1;
	int x, p, t;
	char where;
	do{
	cout<<"\nBINARY TREE IMPLEMENTATION :\n  1. Sequential representation\n  2. Linked lists representation\nEXIT (Press 0)\nYour choice? ";
	cin>>ch;
	switch(ch)
	{
		case 0: break;
		case 1:	
		//Sequential representation
			S.initialise();			

		 do{
			cout<<"\n ---- Sequential representation ----\nWHAT TO DO?\n  1. Insert\n  2. Delete\n  3. Search\n  4. Display\nSELECT ANOTHER IMPLEMENTATION (Press 0)\nYour choice? ";
			cin>>ch1;
			switch(ch1)
			{
				case 0: break;
				case 1:
					cout<<"\nEnter the number to be inserted : ";
					cin>>x;
					if(S.isEmpty())
						S.Create(x);
					else
					{
						cout<<"What should be the parent node of "<<x<<" ? ";
						cin>>p;
						cout<<"Where would you like to inserted? (L/R) ";
						cin>>where;
						S.Create(x, p, where);
					}
					break;

				case 2:
					cout<<"\nEnter the number to be deleted : ";
					cin>>x;
					if(!S.Delete(x))
						cout<<"\n"<<x<<" is not in the tree!"<<endl;
					else
						cout<<"\n"<<x<<" deleted!"<<endl;
					break;
				case 3:
					cout<<"\nEnter the number to be searched : ";
					cin>>x;
					flag = 0;
					if(!S.Search(x))
						cout<<"\n"<<x<<" is not in the tree!"<<endl;
					else
						cout<<"\n"<<x<<" occured "<<flag<<" times in the tree!"<<endl;
					break;
				case 4:
						S.Display();
					break;
				default:
					cout<<"\nInvalid choice!\n";
			}
		 }while(ch1!=0);
			break;

		case 2:
		//Linked lists representation
			LinkedLists L;

		 do{
			cout<<"\n ---- Linked lists representation ----\nWHAT TO DO?\n  1. Insert\n  2. Delete\n  3. Search\n  4. Display\nSELECT ANOTHER IMPLEMENTATION (Press 0)\nYour choice? ";
			cin>>ch1;
			switch(ch1)
			{
				case 0: break;
				case 1:
					cout<<"\nEnter the number to be inserted : ";
					cin>>x;
					if(L.isEmpty())
						L.Create(x);
					else
					{
						cout<<"What should be the parent node of "<<x<<" ? ";
						cin>>p;
						cout<<"Where would you like to inserted? (L/R) ";
						cin>>where;
						L.Create(x, p, where);
					}
					break;

				case 2:
					cout<<"\nEnter the number to be deleted : ";
					cin>>x;
					if(!L.Delete(x))
						cout<<"\n"<<x<<" is not in the tree!"<<endl;
					else
						cout<<"\n"<<x<<" deleted!"<<endl;
					break;
				case 3:
					cout<<"\nEnter the number to be searched : ";
					cin>>x;
					flag = 0;
					if(!L.Search(root, x))
						cout<<"\n"<<x<<" is not in the tree!"<<endl;
					else
						cout<<"\n"<<x<<" occured "<<flag<<" times in the tree!"<<endl;
					break;
				case 4:
					cout<<"\nTREE TRAVERSAL :\n  1. Pre-order\n  2. In-order\n  3. Post-order\nYour choice? ";
					cin>>t;
					if(!(t==1||t==2||t==3))
						cout<<"\nInvalid choice!\n";
					else
					{
						if(t==1) cout<<"\n--- Pre-order traversal ---";
						else if(t==2) cout<<"\n--- In-order traversal ---";
						else if(t==3) cout<<"\n--- Post-order traversal ---";
						L.Display(root, t);
					}
					break;
				default:
					cout<<"\nInvalid choice!\n";
			}
		 }while(ch1!=0);
			break;

		default:
			cout<<"\nInvalid choice!\n";
	}
	}while(ch!=0);
}

bool LinkedLists::isEmpty()
{
	if(root == NULL)
		return true;
	else
		return false;
}

struct Found
{
	node *a[SIZE];
	node *p[SIZE];
};
Found f;
Found *found = &f;

int I;

void find(node* Node, int x, node* p = root)
{
	if(Node == NULL)
		return;

	if(Node->info == x)
	{
		found->a[I] = Node;
		found->p[I] = p;
		I++;
	}

	find(Node->left, x, Node);
	find(Node->right, x, Node);	
}

void LinkedLists::Create(int x, int p, char where)
{
	node* newNode = createNode(x);
	node* parent;

	if(isEmpty())
	{
		root = newNode;
		cout<<"\n"<<x<<" inserted as the root node!"<<endl;
		return;
	}
	
	for(int i=0; i<SIZE; i++)
	{
		found->a[i] = NULL;
		found->p[i] = NULL;
	}
	I=0;
	
	find(root, p);

	if(found->a[0] == NULL)
	{
		cout<<"\nParent node "<<p<<" not found!"<<endl;
		return;
	}

	int f=0, i=0;
	if(where == 'l' || where == 'L')
	{
		
		while(found->a[i]!=NULL)
		{
			if((found->a[i])->left == NULL)
			{
				f=1;
				(found->a[i])->left = newNode;
				cout<<"\n"<<x<<" inserted to the "<<where<<" of "<<p<<endl;
				return;
			}
			i++;
		}
		if(f == 0) 
		{
			cout<<"\nLeft node of "<<x<<" is already there!"<<endl;
			return;
		}
	}
	else if(where == 'r' || where == 'R')
	{
		while(found->a[i]!=NULL)
		{
			if((found->a[i])->right == NULL)
			{
				f=1;
				(found->a[i])->right = newNode;
				cout<<"\n"<<x<<" inserted to the "<<where<<" of "<<p<<endl;
				return;
			}
			i++;
		}
		if(f == 0) 
		{
			cout<<"\nRight node of "<<x<<" is already there!"<<endl;
			return;
		}
	}
}

struct RM
{
	node* a[SIZE];
	node* p[SIZE];
};
RM rm;
RM *rightMost = &rm;

void findRightMost(node* Node, node* p = root)
{
	if(Node == NULL)
		return;

	if(Node->right == NULL && Node->left == NULL)
	{
		rightMost->a[I] = Node;
		rightMost->p[I] = p;
		I++;
	}

	findRightMost(Node->left, Node);
	findRightMost(Node->right, Node);
}

int LinkedLists::Delete(int x)
{
	for(int i=0; i<SIZE; i++)
	{
		found->a[i] = NULL;
		found->p[i] = NULL;
	}
	I=0;
	
	find(root, x);
	node *toDelete = found->a[0];

	if(toDelete == NULL)
	{
		cout<<"\nNode "<<x<<" not found!"<<endl;
		return 0;
	}

	if(toDelete->right != NULL || toDelete->left != NULL)
	{
		for(int i=0; i<SIZE; i++)
		{
			rightMost->a[i] = NULL;
			rightMost->p[i] = NULL;
		}
		I=0;

		findRightMost(root);

		node *toReplace = rightMost->a[I-1];

		toReplace->right = toDelete->right;
		toReplace->left = toDelete->left;
		
		(rightMost->p[I-1])->right = NULL;

		if(toDelete == root)
			root = toReplace;
		else
		{
			node* parent = found->p[0];
			if(parent->right == toDelete) 
				parent->right = toReplace;
			else
				parent->left = toReplace;
		}

		return 1;
	}
	else
	{
		node* parent = found->p[0];
		if(parent->right == toDelete) 
			parent->right = NULL;
		else
			parent->left = NULL;
		return 1;
	}
}

int LinkedLists::Search(node* Node, int n, int p)
{
	int lc, rc;

	if(Node == NULL)
		return 0;

	if(Node->info == n)
	{
		++flag;
		if(p==-1)
			cout<<"\nParent Node : NULL";
		else
			cout<<"\nParent Node : "<<p;

		if(Node->left == NULL) 
				lc = '\0';
		else
			lc = (Node->left)->info;
		if(Node->right == NULL) 
			rc = '\0';
		else
			rc = (Node->right)->info;

		cout<<"\nLeft child : "<<lc<<"\tRight child : "<<rc<<endl;
	}

	Search(Node->left, n, Node->info);
	Search(Node->right, n, Node->info);

	return flag;
}

void LinkedLists::Display(node* Node, int ch, int p)
{
	int lc,rc;
	switch(ch)
	{
		case 1:
			//pre-order traversal
			if(Node == NULL)
				return;
			if(Node->left == NULL) 
				lc = '\0';
			else
				lc = (Node->left)->info;
			if(Node->right == NULL) 
				rc = '\0';
			else
				rc = (Node->right)->info;
			cout<<"\nNode : "<<Node->info;
			if(p==-1)
				cout<<"\nParent Node : NULL";
			else
				cout<<"\nParent Node : "<<p;
			cout<<"\nLeft child : "<<lc<<"\tRight child : "<<rc<<endl;
			Display(Node->left, ch, Node->info);
			Display(Node->right, ch, Node->info);
		break;

		case 2:
			//in-order traversal
			if(Node == NULL)
				return;
			Display(Node->left, ch, Node->info);
			if(Node->left == NULL) 
				lc = '\0';
			else
				lc = (Node->left)->info;
			if(Node->right == NULL) 
				rc = '\0';
			else
				rc = (Node->right)->info;
			cout<<"\nNode : "<<Node->info;
			if(p==-1)
				cout<<"\nParent Node : NULL";
			else
				cout<<"\nParent Node : "<<p;
			cout<<"\nLeft child : "<<lc<<"\tRight child : "<<rc<<endl;
			Display(Node->right, ch, Node->info);
		break;

		case 3:
			//post-order traversal
			if(Node == NULL)
				return;
			Display(Node->left, ch, Node->info);
			Display(Node->right, ch, Node->info);
			if(Node->left == NULL) 
				lc = '\0';
			else
				lc = (Node->left)->info;
			if(Node->right == NULL) 
				rc = '\0';
			else
				rc = (Node->right)->info;
			cout<<"\nNode : "<<Node->info;
			if(p==-1)
				cout<<"\nParent Node : NULL";
			else
				cout<<"\nParent Node : "<<p;
			cout<<"\nLeft child : "<<lc<<"\tRight child : "<<rc<<endl;
		break;
	}			
}

int foundAt[SIZE];
void Sequential::findParent(int x)
{
	for(int i=1; i<=size; i++)
	{
		if(tree[i] == x)
		{
			foundAt[I] = i;
			I++;
		}
	}
}

void Sequential::Create(int x, int p, char where)
{
	if(isEmpty())
	{
		tree[1]=x;
		cout<<"\n"<<x<<" inserted as the root node!"<<endl;
		return;
	}

	for(int i=0; i<SIZE; i++)
		foundAt[i] = null;
	I=0;

	findParent(p);

	if(foundAt[0] == null)
	{
		cout<<"\nParent node "<<p<<" not found!"<<endl;
		return;
	}

	int f=0, i=0, loc;
	if(where == 'l' || where == 'L')
	{
		
		while(foundAt[i]!=null)
		{
			loc = foundAt[i];
			if(tree[2*loc] == null)
			{
				f=1;
				tree[2*loc] = x;
				cout<<"\n"<<x<<" inserted to the "<<where<<" of "<<p<<endl;
				return;
			}
			i++;
		}
		if(f == 0) 
		{
			cout<<"\nLeft node of "<<x<<" is already there!"<<endl;
			return;
		}
	}
	else if(where == 'r' || where == 'R')
	{
		while(foundAt[i] != null)
		{
			loc = foundAt[i];
			if(tree[2*loc+1] == null)
			{
				f=1;
				tree[2*loc+1] = x;
				cout<<"\n"<<x<<" inserted to the "<<where<<" of "<<p<<endl;
				return;
			}
			i++;
		}
		if(f == 0) 
		{
			cout<<"\nRight node of "<<x<<" is already there!"<<endl;
			return;
		}
	}
}

int leafNodes[SIZE];
void Sequential::findLast()
{
	for(int i=1; i<=size; i++)
	{
		if(tree[i]!=null && tree[2*i] == null && tree[2*i+1] == null)
		{
			leafNodes[I] = i;
			I++;
		}
	}
}

int Sequential::Delete(int x)
{
	for(int i=0; i<SIZE; i++)
		foundAt[i] = null;
	I=0;
	
	findParent(x);
	int toDelete = foundAt[0];

	if(toDelete == null)
		return 0;

	if(tree[2*toDelete] != null || tree[2*toDelete+1] != null)
	{
		for(int i=0; i<SIZE; i++)
			leafNodes[i] = null;
		I=0;

		findLast();
		cout<<"\n----------- "<<leafNodes[I-1]<<endl;
		int toReplace = leafNodes[I-1];

		tree[toDelete] = tree[toReplace];
		tree[toReplace] = null;

		return 1;
	}
	else
	{
		tree[toDelete] = null;
		return 1;
	}
}

int Sequential::Search(int x)
{
	for(int i=0; i<SIZE; i++)
		foundAt[i] = null;
	I=0;

	findParent(x);

	if(foundAt[0] == null)
		return 0;

	int loc;
	while(1)
	{
		--I;
		loc = foundAt[I];
		++flag;
		if(loc == 1)
			cout<<"\nParent Node : NULL";
		else
			cout<<"\nParent Node : "<<tree[(loc/2)];
		cout<<"\nLeft child : "<<tree[2*loc]<<"\tRight child : "<<tree[2*loc+1]<<endl;

		if(I==0) break;
	}
	return flag;
}

void Sequential::Display()
{
	if(isEmpty())
	{
		cout<<"\nTree is Empty!"<<endl;
		return;
	}

	cout<<"\n--- Pre-order traversal ---";
	for (int i=1; i<=size; ++i)
	{
		if(tree[i]!=null)
		{
			cout<<"\nNODE : "<<tree[i];
			if(i==1)
				cout<<"\nParent Node : NULL";
			else
				cout<<"\nParent Node : "<<tree[(i/2)];
			cout<<"\nLeft child : "<<tree[2*i]<<"\tRight child : "<<tree[2*i+1]<<endl;
		}
	}
}