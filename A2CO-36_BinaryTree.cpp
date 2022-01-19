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
#include <iomanip>
#include <math.h>

#define MAX 1000
#define null 0
#define LEFT 0
#define INFO 1
#define RIGHT 2

using namespace std;

class Sequential
{
	int tree[MAX];
public:
	
	void initialise()
	{
		for(int i=1; i<=MAX; i++)
			tree[i] = null;
	}

	bool isEmpty()
	{
		if(tree[1] == null)
			return true;
		else
			return false;
	}
	void Create(int=null, char='l');
	void Delete(int);
	void Search(int);
	void preorder(int=1);
	void inorder(int=1);
	void postorder(int=1);
	void Traverse(int);
	void Display();
};

class Linked
{
	int tree[MAX][3], size;
	//int visited[MAX];
public:
	
	void initialise()
	{
		size=0;
		for(int i=1; i<MAX; i++)
		{
			tree[i][LEFT] = null;
			tree[i][INFO] = null;
			tree[i][RIGHT] = null;
		}
	}

	bool isEmpty()
	{
		if(tree[1][INFO] == null)
			return true;
		else
			return false;
	}
	int findFree();	//finds the next free location for insertion
	void Create(int=null, char='l');
	int findParent(int);	//finds the parent (location) of a given node (location)
	int findHeight(int=1);	//finds the height of the tree
	void findRightMost(int=1, int=1);	//finds the last element at a particular level of the tree
	void Delete(int);	
	void Search(int);
	void preorder(int=1);
	void inorder(int=1);
	void postorder(int=1);
	void Traverse(int);
	void Display();
};

int main()
{
	Sequential S;
	Linked L;
	int ch, ch1;
	int x, p, t;
	char where;
	do{
	cout<<"\nBINARY TREE IMPLEMENTATION :\n  1. Sequential representation\n  2. Linked representation\nEXIT (Press 0)\nYour choice? ";
	cin>>ch;
	switch(ch)
	{
		case 0: break;
		case 1:	
		//Sequential representation		
		 S.initialise();
		 do{
			cout<<"\n ---- Sequential representation ----\nWHAT TO DO?\n  1. Insert\n  2. Delete\n  3. Search\n  4. Traverse\n  5. Display\nBACK (Press 0)\nYour choice? ";
			cin>>ch1;
			switch(ch1)
			{
				case 0: break;
				case 1:
					if(S.isEmpty())
						S.Create();
					else
					{
						cout<<"\nEnter the location of the parent node: ";
						cin>>p;
						cout<<"Where would you like to insert - Left/Right? (Enter L/R) ";
						cin>>where;
						S.Create(p, where);
					}
					break;

				case 2:
					cout<<"\nEnter the location of the number to be deleted : ";
					cin>>x;
					S.Delete(x);
					break;
				case 3:
					cout<<"\nEnter the number to be searched : ";
					cin>>x;
					S.Search(x);
					break;
				case 4:
					if(S.isEmpty())
						cout<<"\nTree is empty!"<<endl;
					else
					{
						cout<<"\nTREE TRAVERSAL :\n  1. Pre-order\n  2. In-order\n  3. Post-order\nYour choice? ";
						cin>>t;
						S.Traverse(t);
					}
					break;
				case 5:
					if(S.isEmpty())
						cout<<"\nTree is empty!"<<endl;
					else
						S.Display();
					break;
				default:
					cout<<"\nInvalid choice!\n";
			}
		 }while(ch1!=0);
			break;

		case 2:
		//Linked representation
		 L.initialise();
		 do{
			cout<<"\n ---- Linked representation ----\nWHAT TO DO?\n  1. Insert\n  2. Delete\n  3. Search\n  4. Traverse\n  5. Display\nBACK (Press 0)\nYour choice? ";
			cin>>ch1;
			switch(ch1)
			{
				case 0: break;
				case 1:
					if(L.isEmpty())
						L.Create();
					else
					{
						cout<<"\nEnter the location of the parent node: ";
						cin>>p;
						cout<<"Where would you like to insert - Left/Right? (Enter L/R) ";
						cin>>where;
						L.Create(p, where);
					}
					break;

				case 2:
					cout<<"\nEnter the location of the number to be deleted : ";
					cin>>x;
					L.Delete(x);
					break;
				case 3:
					cout<<"\nEnter the number to be searched : ";
					cin>>x;
					L.Search(x);
					break;
				case 4:
					if(L.isEmpty())
						cout<<"\nTree is empty!"<<endl;
					else
					{
						cout<<"\nTREE TRAVERSAL :\n  1. Pre-order\n  2. In-order\n  3. Post-order\nYour choice? ";
						cin>>t;
						L.Traverse(t);
					}
					break;
				case 5:
					if(L.isEmpty())
						cout<<"\nTree is empty!"<<endl;
					else
						L.Display();
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

void Sequential::Create(int p, char where)
{
	int x;
	cout<<"Enter the number to be inserted : ";
	cin>>x;

	if(isEmpty())
	{
		tree[1]=x;
		cout<<"\n"<<x<<" inserted as the root node!"<<endl;
		return;
	}

	if(tree[p] == null)
	{
		cout<<"\nLocation "<<p<<" is empty!"<<endl;
		return;
	}

	if(where == 'l' || where == 'L')
	{
		if(tree[2*p] == null)
		{
			tree[2*p] = x;
			cout<<"\n"<<x<<" inserted to the LEFT of node at INDEX "<<p<<endl;
			return;
		}
		else
			cout<<"\nLEFT of the node at INDEX "<<p<<" is already there!"<<endl;
	}
	else if(where == 'r' || where == 'R')
	{
		if(tree[2*p+1] == null)
		{
			tree[2*p+1] = x;
			cout<<"\n"<<x<<" inserted to the RIGHT of node at INDEX "<<p<<endl;
			return;
		}
		else 
			cout<<"\nRIGHT of the node at INDEX "<<p<<" is already there!"<<endl;
	}
}

void Sequential::Delete(int x)
{
	if(tree[x] == null)
	{
		cout<<"\nLocation "<<x<<" is already empty!"<<endl;
		return;
	}

	if(tree[2*x] != null || tree[2*x+1] != null)
	{
		int toReplace;
		for(int i=MAX; i>1; i--)
		{
			if(tree[i]!=null)
			{
				toReplace = i;
				break;
			}
		}

		cout<<"\nNode at Location "<<x<<" ( "<<tree[x]<<" ) deleted!"<<endl;

		tree[x] = tree[toReplace];
		tree[toReplace] = null;
	}
	else
	{
		cout<<"\nNode at Location "<<x<<" ( "<<tree[x]<<" ) deleted!"<<endl;
		tree[x] = null;
	}
}

void Sequential::Search(int x)
{
	int count=0;
	for(int i=1; i<MAX; i++)
	{
		if(tree[i] == x)
		{
			++count;
			cout<<"\nValue : "<<x<<" occured at Location : "<<i<<" \nLocation of :";
			if(i == 1)
				cout<<"\n-- Parent Node : NULL";
			else
				cout<<"\n-- Parent Node : "<<i/2<<" ( Value : "<<tree[i/2]<<" ) ";
			cout<<"\n-- Left child : "<<2*i<<" ( Value : "<<tree[2*i]<<" ) ";
			cout<<"\n-- Right child : "<<2*i+1<<" ( Value : "<<tree[2*i+1]<<" ) "<<endl;
		}
	}

	if(!count)
	{
		cout<<"\n"<<x<<" is not in the tree!"<<endl;
		return;
	}
	else
		cout<<"\n"<<x<<" occured "<<count<<" times in the tree!"<<endl;
}

void Sequential::preorder(int node)
{
	if(tree[node] == null)
		return;

	cout<<tree[node]<<"\t";
	preorder(2*node);
	preorder(2*node+1);
}

void Sequential::inorder(int node)
{
	if(tree[node] == null)
		return;

	inorder(2*node);
	cout<<tree[node]<<"\t";
	inorder(2*node+1);
}

void Sequential::postorder(int node)
{
	if(tree[node] == null)
		return;

	postorder(2*node);
	postorder(2*node+1);
	cout<<tree[node]<<"\t";
}

void Sequential::Traverse(int ch)
{
	switch(ch)
	{
		case 1:
			cout<<"\n--- Pre-order traversal ---\n";
			preorder();
			cout<<endl;
			break;
		case 2:
			cout<<"\n--- In-order traversal ---\n";
			inorder();
			cout<<endl;
			break;
		case 3:
			cout<<"\n--- Post-order traversal ---\n";
			postorder();
			cout<<endl;
			break;
		default:
			cout<<"\nInvalid choice"<<endl;
	}
}

void Sequential::Display()
{
	for(int i=1; i<MAX; i++)
	{
		if(tree[i] != null)
		{
			cout<<"\nNode : "<<tree[i];
			if(i == 1)
				cout<<"\nParent Node : NULL";
			else
				cout<<"\nParent Node : "<<tree[(i/2)];
			cout<<"\nLeft child : "<<tree[2*i]<<"\tRight child : "<<tree[2*i+1]<<endl;
		}
	}
}

int Linked::findFree()
{
	for(int i=1; i<MAX; i++)
	{
		if(tree[i][INFO] == null)
			return i;
	}
	return 0;
}

void Linked::Create(int p, char where)
{
	int x;
	cout<<"Enter the number to be inserted : ";
	cin>>x;
	
	if(isEmpty())
	{
		tree[1][INFO]=x;
		++size;
		cout<<"\n"<<x<<" inserted as the root node!"<<endl;
		return;
	}

	if(p == null)
	{
		cout<<"\nLocation "<<p<<" is empty!"<<endl;
		return;
	}

	int pos;
	if(where == 'l' || where == 'L')
	{
		if(tree[p][LEFT] == null)
		{
			++size;
			pos = findFree();
			tree[pos][INFO] = x;
			tree[p][LEFT] = pos;
			cout<<"\n"<<x<<" inserted to the LEFT of node at INDEX "<<p<<endl;
			return;
		}
		else
			cout<<"\nLEFT of the node at INDEX "<<p<<" is already there!"<<endl;
	}
	else if(where == 'r' || where == 'R')
	{
		if(tree[p][RIGHT] == null)
		{
			++size;
			pos = findFree();
			tree[pos][INFO] = x;
			tree[p][RIGHT] = pos;
			cout<<"\n"<<x<<" inserted to the RIGHT of node at INDEX "<<p<<endl;
			return;
		}
		else 
			cout<<"\nRIGHT of the node at INDEX "<<p<<" is already there!"<<endl;		
	}
}

int Linked::findParent(int x)
{
	for(int i=1; i<=size; i++)
	{
		if(tree[i][LEFT] == x || tree[i][RIGHT] == x)
			return i;
	}
	return 0;
}

int Linked::findHeight(int node)
{
	if(node == null)
		return 0;

	int hleft = findHeight(tree[node][LEFT]);
	int hright = findHeight(tree[node][RIGHT]);
	if(hleft > hright)
		return hleft+1;
	else
		return hright+1;
}

int toReplace;
void Linked::findRightMost(int node, int l)
{
	if(node==null)
		return;
	
	if(l == 1)
		toReplace = node;

	findRightMost(tree[node][LEFT], l-1);
	findRightMost(tree[node][RIGHT], l-1);	
}

void Linked::Delete(int x)
{
	if(tree[x][INFO] == null)
	{
		cout<<"\nLocation "<<x<<" is already empty!"<<endl;
		return;
	}

	if(tree[x][LEFT] != null || tree[x][RIGHT] != null)
	{
		toReplace = 0; 
		int h = findHeight();
		findRightMost(h);
		int parent = findParent(toReplace);

		if(parent != null) 
		{
			if(tree[tree[parent][LEFT]][INFO] == tree[toReplace][INFO])
				tree[parent][LEFT] = null;
			else 
				tree[parent][RIGHT] = null;
		}

		cout<<"\nNode at Location "<<x<<" ( "<<tree[x][INFO]<<" ) deleted!"<<endl;

		tree[x][INFO] = tree[toReplace][INFO];
		tree[toReplace][INFO] = null;
	}
	else
	{
		int parent = findParent(x);
		if(tree[tree[parent][LEFT]][INFO] == tree[x][INFO])
			tree[parent][LEFT] = null;
		else 
			tree[parent][RIGHT] = null;

		cout<<"\nNode at Location "<<x<<" ( "<<tree[x][INFO]<<" ) deleted!"<<endl;
		tree[x][INFO] = null;
	}
}

void Linked::Search(int x)
{
	int count=0;
	for(int i=1; i<size; i++)
	{
		if(tree[i][INFO] == x)
		{
			++count;
			cout<<"\nValue : "<<x<<" occured at Location : "<<i<<" \nLocation of :";
			if(i == 1)
				cout<<"\n-- Parent Node : NULL";
			else
				cout<<"\n-- Parent Node : "<<findParent(i)<<" ( Value : "<<tree[findParent(i)][INFO]<<" )";
			cout<<"\n-- Left child : "<<tree[i][LEFT]<<" ( Value : "<<tree[tree[i][LEFT]][INFO]<<" )";
			cout<<"\t-- Right child : "<<tree[i][RIGHT]<<" ( Value : "<<tree[tree[i][RIGHT]][INFO]<<" )"<<endl;
		}
	}

	if(!count)
	{
		cout<<"\n"<<x<<" is not in the tree!"<<endl;
		return;
	}
	else
		cout<<"\n"<<x<<" occured "<<count<<" times in the tree!"<<endl;
}

void Linked::preorder(int node)
{
	if(node == null)
		return;

	cout<<tree[node][INFO]<<"\t";
	preorder(tree[node][LEFT]);
	preorder(tree[node][RIGHT]);
}

void Linked::inorder(int node)
{
	if(node == null)
		return;

	inorder(tree[node][LEFT]);
	cout<<tree[node][INFO]<<"\t";
	inorder(tree[node][RIGHT]);
}

void Linked::postorder(int node)
{
	if(node == null)
		return;

	postorder(tree[node][LEFT]);
	postorder(tree[node][RIGHT]);
	cout<<tree[node][INFO]<<"\t";
}

void Linked::Traverse(int ch)
{
	switch(ch)
	{
		case 1:
			cout<<"\n--- Pre-order traversal ---"<<endl;
			preorder();
			cout<<endl;
			break;
		case 2:
			cout<<"\n--- In-order traversal ---"<<endl;
			inorder();
			cout<<endl;
			break;
		case 3:
			cout<<"\n--- Post-order traversal ---"<<endl;
			postorder();
			cout<<endl;
			break;
		default:
			cout<<"\nInvalid choice"<<endl;
	}
}

void Linked::Display()
{
	cout<<"\nINDEX\t  LEFT\t    INFO     RIGHT\n";
	for(int i=1; i<=size; i++)
	{
		cout<<setw(2)<<i;
		for(int j=0; j<3; j++)
			cout<<setw(10)<<tree[i][j];
		cout<<endl;
	}
}
