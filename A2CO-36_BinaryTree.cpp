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
#define LEFT 0
#define INFO 1
#define RIGHT 2
#define MAX 1000

using namespace std;

class Sequential
{
	int tree[MAX], depth, size;
	int visited[MAX];
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
	void Create(int, int=null, char='l');
	void findLast();
	int Delete(int);
	void preorder(int=1, int=0);
	void inorder(int=1, int=0);
	void postorder(int=1, int=0);
	void Display(int);
	int Search(int);
};

class Linked
{
	int tree[MAX][3];
	int visited[MAX];
public:
	
	void initialise()
	{
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
	void findParent(int, int=1, int=null);
	int findFree();
	void Create(int, int=null, char='l');
	void findLast(int=1, int=null);
	int Delete(int);
	void preorder(int=1, int=0);
	void inorder(int=1, int=0);
	void postorder(int=1, int=0);
	void Display(int);
	int Search(int);
};

int flag;
int I=0;
int foundAt[SIZE];
int leafNodes[SIZE];
int FoundAt[2][SIZE];
int LeafNodes[2][SIZE];

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
						cout<<"\nTREE TRAVERSAL :\n  1. Pre-order\n  2. In-order\n  3. Post-order\nYour choice? ";
						cin>>t;
						S.Display(t);
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
			cout<<"\n ---- Linked representation ----\nWHAT TO DO?\n  1. Insert\n  2. Delete\n  3. Search\n  4. Display\nSELECT ANOTHER IMPLEMENTATION (Press 0)\nYour choice? ";
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
					if(!L.Search(x))
						cout<<"\n"<<x<<" is not in the tree!"<<endl;
					else
						cout<<"\n"<<x<<" occured "<<flag<<" times in the tree!"<<endl;
					break;
				case 4:
					cout<<"\nTREE TRAVERSAL :\n  1. Pre-order\n  2. In-order\n  3. Post-order\nYour choice? ";
					cin>>t;
					L.Display(t);
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
			cout<<"\nLeft node of "<<p<<" is already there!"<<endl;
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
			cout<<"\nRight node of "<<p<<" is already there!"<<endl;
			return;
		}
	}
}

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

void Sequential::preorder(int node, int p)
{
	int lc,rc;
	if(visited[node] != 1)
	{
		visited[node] = 1;
		if(tree[node] == null)
			return;
		if(tree[2*node] == null) 
			lc = '\0';
		else
			lc = tree[2*node];
		if(tree[2*node+1] == null) 
			rc = '\0';
		else
			rc = tree[2*node+1];
		cout<<"\nNode : "<<tree[node];
		if(p==null)
			cout<<"\nParent Node : NULL";
		else
			cout<<"\nParent Node : "<<p;
		cout<<"\nLeft child : "<<lc<<"\tRight child : "<<rc<<endl;
	
		preorder(2*node, tree[node]);
		preorder(2*node+1, tree[node]);
	}
}

void Sequential::inorder(int node, int p)
{
	int lc,rc;
	if(visited[node] != 1)
	{
		visited[node] = 1;
		
		if(tree[node] == null)
			return;

		inorder(2*node, tree[node]);

		if(tree[2*node] == null) 
			lc = '\0';
		else
			lc = tree[2*node];
		if(tree[2*node+1] == null) 
			rc = '\0';
		else
			rc = tree[2*node+1];
		cout<<"\nNode : "<<tree[node];
		if(p==null)
			cout<<"\nParent Node : NULL";
		else
			cout<<"\nParent Node : "<<p;
		cout<<"\nLeft child : "<<lc<<"\tRight child : "<<rc<<endl;
	
		inorder(2*node+1, tree[node]);
	}
}

void Sequential::postorder(int node, int p)
{
	int lc,rc;
	if(visited[node] != 1)
	{
		visited[node] = 1;
		
		if(tree[node] == null)
			return;
		
		postorder(2*node, tree[node]);
		postorder(2*node+1, tree[node]);
		
		if(tree[2*node] == null) 
			lc = '\0';
		else
			lc = tree[2*node];
		if(tree[2*node+1] == null) 
			rc = '\0';
		else
			rc = tree[2*node+1];
		cout<<"\nNode : "<<tree[node];
		if(p==null)
			cout<<"\nParent Node : NULL";
		else
			cout<<"\nParent Node : "<<p;
		cout<<"\nLeft child : "<<lc<<"\tRight child : "<<rc<<endl;
	}
}


void Sequential::Display(int ch)
{
	for(int i=1; i<=MAX; i++)
		visited[i] = null;
	switch(ch)
	{
		case 1:
			cout<<"\n--- Pre-order traversal ---";
			preorder();
			break;
		case 2:
			cout<<"\n--- In-order traversal ---";
			inorder();
			break;
		case 3:
			cout<<"\n--- Post-order traversal ---";
			postorder();
			break;
		default:
			cout<<"\nInvalid choice"<<endl;
	}
}

void Linked::findParent(int x, int node, int p)
{
	if(node == null)
		return;

	if(tree[node][INFO] == x)
	{
		FoundAt[0][I] = node;
		FoundAt[1][I] = p;
		I++;
	}

	findParent(x, tree[node][LEFT], node);
	findParent(x, tree[node][RIGHT], node);
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

void Linked::Create(int x, int p, char where)
{
	if(isEmpty())
	{
		tree[1][INFO]=x;
		cout<<"\n"<<x<<" inserted as the root node!"<<endl;
		return;
	}

	for(int i=0; i<SIZE; i++)
		FoundAt[0][i] = null;
	I=0;

	findParent(p);

	if(FoundAt[0][0] == null)
	{
		cout<<"\nParent node "<<p<<" not found!"<<endl;
		return;
	}

	int pos;
	int f=0, i=0, loc;
	if(where == 'l' || where == 'L')
	{
		
		while(i<I)
		{
			loc = FoundAt[0][i];
			
			if(tree[loc][LEFT] == null)
			{
				f=1;
				pos = findFree();
				tree[pos][INFO] = x;
				tree[loc][LEFT] = pos;
				cout<<"\n"<<x<<" inserted to the "<<where<<" of "<<p<<endl;
				return;
			}
			i++;
		}
		if(f == 0) 
		{
			cout<<"\nLeft node of "<<p<<" is already there!"<<endl;
			return;
		}
	}
	else if(where == 'r' || where == 'R')
	{
		while(i<I)
		{
			loc = FoundAt[0][i];
			if(tree[loc][RIGHT] == null)
			{
				f=1;
				pos = findFree();
				tree[pos][INFO] = x;
				tree[loc][RIGHT] = pos;
				cout<<"\n"<<x<<" inserted to the "<<where<<" of "<<p<<endl;
				return;
			}
			i++;
		}
		if(f == 0) 
		{
			cout<<"\nRight node of "<<p<<" is already there!"<<endl;
			return;
		}
	}
}

void Linked::findLast(int node, int p)
{
	if(node==null)
		return;
	
	if(tree[node][INFO]!=null && tree[node][LEFT] == null && tree[node][RIGHT] == null)
	{
		LeafNodes[0][I] = node;
		LeafNodes[1][I] = p;
		I++;
	}

	findLast(tree[node][LEFT], node);
	findLast(tree[node][RIGHT], node);
	
}

int Linked::Delete(int x)
{
	for(int i=0; i<SIZE; i++)
	{
		FoundAt[0][i] = null;
		FoundAt[1][i] = null;
	}
	I=0;
	
	findParent(x);
	int toDelete = FoundAt[0][0];

	if(toDelete == null)
		return 0;

	if(tree[toDelete][LEFT] != null || tree[toDelete][RIGHT] != null)
	{
		for(int i=0; i<SIZE; i++)
		{
			LeafNodes[0][i] = null;
			LeafNodes[1][i] = null;
		}
		I=0;

		findLast();
		int toReplace = LeafNodes[0][I-1];
		tree[toDelete][INFO] = tree[toReplace][INFO];

		int parent = LeafNodes[1][I-1];

		if(parent != null) 
		{
			if(tree[tree[parent][LEFT]][INFO] == tree[toReplace][INFO])
				tree[parent][LEFT] = null;
			else 
				tree[parent][RIGHT] = null;
		}

		tree[toReplace][INFO] = null;

		return 1;
	}
	else
	{
		int parent = FoundAt[1][0];
		if(tree[tree[parent][LEFT]][INFO] == tree[toDelete][INFO])
			tree[parent][LEFT] = null;
		else 
			tree[parent][RIGHT] = null;

		tree[toDelete][INFO] = null;
		return 1;
	}
}

int Linked::Search(int x)
{
	for(int i=0; i<SIZE; i++)
	{
		FoundAt[0][i] = null;
		FoundAt[1][i] = null;
	}
	I=0;

	findParent(x);

	if(FoundAt[0][0] == null)
		return 0;

	int loc;
	while(1)
	{
		--I;
		loc = FoundAt[0][I];
		++flag;
		if(loc == 1)
			cout<<"\nParent Node : NULL";
		else
			cout<<"\nParent Node : "<<tree[FoundAt[1][I]][INFO];
		cout<<"\nLeft child : "<<tree[tree[loc][LEFT]][INFO]<<"\tRight child : "<<tree[tree[loc][RIGHT]][INFO]<<endl;

		if(I==0) break;
	}
	return flag;
}

void Linked::preorder(int node , int p)
{
	if(visited[node]!=1)
	{
		visited[node]=1;
		
		if(node == null)
			return;

		int lc,rc;
		if(tree[node][LEFT] == null) 
			lc = '\0';
		else
			lc = tree[tree[node][LEFT]][INFO];
		if(tree[node][RIGHT] == null) 
			rc = '\0';
		else
			rc = tree[node][RIGHT];
		cout<<"\nNode : "<<tree[node][INFO];
		if(p==null)
			cout<<"\nParent Node : NULL";
		else
			cout<<"\nParent Node : "<<p;
		cout<<"\nLeft child : "<<lc<<"\tRight child : "<<rc<<endl;
	
		preorder(tree[node][LEFT], node);
		preorder(tree[node][RIGHT], node);
	}
}

void Linked::inorder(int node , int p)
{
	if(visited[node]!=1)
	{
		visited[node]=1;
		
		if(node == null)
			return;

		inorder(tree[node][LEFT], node);

		int lc,rc;
		if(tree[node][LEFT] == null) 
			lc = '\0';
		else
			lc = tree[tree[node][LEFT]][INFO];
		if(tree[node][RIGHT] == null) 
			rc = '\0';
		else
			rc = tree[node][RIGHT];
		cout<<"\nNode : "<<tree[node][INFO];
		if(p==null)
			cout<<"\nParent Node : NULL";
		else
			cout<<"\nParent Node : "<<p;
		cout<<"\nLeft child : "<<lc<<"\tRight child : "<<rc<<endl;
	
		inorder(tree[node][RIGHT], node);
	}
}

void Linked::postorder(int node , int p)
{
	if(visited[node]!=1)
	{
		visited[node]=1;
		
		if(node == null)
			return;

		postorder(tree[node][LEFT], node);
		postorder(tree[node][RIGHT], node);

		int lc,rc;
		if(tree[node][LEFT] == null) 
			lc = '\0';
		else
			lc = tree[tree[node][LEFT]][INFO];
		if(tree[node][RIGHT] == null) 
			rc = '\0';
		else
			rc = tree[node][RIGHT];
		cout<<"\nNode : "<<tree[node][INFO];
		if(p==null)
			cout<<"\nParent Node : NULL";
		else
			cout<<"\nParent Node : "<<p;
		cout<<"\nLeft child : "<<lc<<"\tRight child : "<<rc<<endl;
	}
}

void Linked::Display(int ch)
{
	for(int i=1; i<=MAX; i++)
		visited[i] = null;
	switch(ch)
	{
		case 1:
			cout<<"\n--- Pre-order traversal ---";
			preorder();
			break;
		case 2:
			cout<<"\n--- In-order traversal ---";
			inorder();
			break;
		case 3:
			cout<<"\n--- Post-order traversal ---";
			postorder();
			break;
		default:
			cout<<"\nInvalid choice"<<endl;
	}
}