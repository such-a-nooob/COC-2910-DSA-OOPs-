/*

Write a program in C to implement hashing. Use a hash table of size 50. Use the following collision resolution methods: linear probing, quadratic probing, double hashing and separate chaining. For each of the collision resolution method, implement the following
functions:
ü a function insert (n) that adds the number n to the table, if it is not already there. If a number is already found in the hash table, it is not inserted for the second time.  
ü a function delete (n) that removes the number n from the table, if it's there.
ü a function search(n) that returns location of number n in the table if it is present, otherwise returns ‘-1’.

Generate 40 numbers randomly in the range from 0 to 999 and insert them into the hash table. For each number to be inserted, print the location where the number is inserted and number of probes required to insert it into the hash table for all collision resolution methods. Use hash function “k mod 47”. Use “7-(k mod 7)” as the second hash function in double hashing.
For Separate Chaining, use an array of size 5 at each location in the hash table, instead of a linked list. (Such arrays are called buckets. This approach is not as efficient as the linked list approach, however, because of the problem of choosing the size of the buckets. If they’re too small they might overflow, and if they’re too large they waste memory. Linked lists, which allocate memory dynamically, don’t have this problem.)

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50 
#define SIZE 40
#define LP 1	//Linear Probing
#define QP 2	//Quadratic Probing
#define DH 3	//Double Hashing
#define SC 4	//Separate Chaining
#define null -1
#define deleted -2

int hash_table[MAX];

//for separate chaining
int hashtable[MAX][5];
int f[MAX];

int n,flag;
/*n = number of probes
  flag = 1 Number is present in hash table
  flag = 0 Number is not present in hash table */

void printHash()
{
	printf("\n");
	for (int i=0; i<MAX; ++i)
		printf("%d  ->  %d\n",i,hash_table[i]);
}

void printHashSC()
{
	int i,j;
	printf("\n");
	for (i=0; i<MAX; ++i)
	{
		printf("%d",i);
		for(j=0; j<5; j++)
			printf("\t->\t%d",hashtable[i][j]);
		printf("\n");
		printf("Numbers in chain : %d\n",f[i]);
	}

}

void randomInput(int a[], int n)
{
	time_t t;
	srand((unsigned) time(&t));
	for(int i=0; i<n; i++)
		a[i]=rand()%1000;
}

int hashFunc(int key)
{
	return (key%47);
}

int insertLP(int key)
{
	int h = hashFunc(key), pos = h;
	while(1)
	{
		if(hash_table[pos]==null||hash_table[pos]==deleted||hash_table[pos]==key) break;
		pos = h+n;
		n++;
		if(pos>=MAX) pos-=MAX;
	}
	return pos;
}

int insertQP(int key)
{
	int h = hashFunc(key), pos = h;
	while(1)
	{
		if(hash_table[pos]==null||hash_table[pos]==deleted||hash_table[pos]==key) break;
		pos = h+(n*n);
		n++;
		if(pos>=MAX) pos-=MAX;
	}
	return pos;
}

int IIhashFunc(int key)
{
	return (7-(key%7));
}

int insertDH(int key)
{
	int h1 = hashFunc(key), h2 = IIhashFunc(key), h, pos=h1;
	while(1)
	{
		if(hash_table[pos]==null||hash_table[pos]==deleted||hash_table[pos]==key) break;
		pos = (h1+(n*h2))%47;
		n++;
		if(pos>=MAX) pos-=MAX;
	}
	//n--;
	return pos;
}

void insertKey(int key, int ch)
{
	int pos;
	pos = hashFunc(key);
	n++;
	if(hash_table[pos]==null||hash_table[pos]==deleted)
		hash_table[pos]=key;
	else if(hash_table[pos]==key)
		return;
	else
	{
		switch (ch)
		{
			case 1: 
				pos = insertLP(key);
				break;
			case 2: 
				pos = insertQP(key);
				break;
			case 3: 
				pos = insertDH(key);
				break;
		}
		hash_table[pos]=key;
	}
	printf("\n--Key %d",key);
	printf("\t\tLocation : %d\tProbes : %d",pos,n);
}

int searchLP(int key)
{
	int h = hashFunc(key), pos = h;
	while(hash_table[pos]!=null)
	{
		if(hash_table[pos]==key) 
		{
			flag=1;
			break;
		}
		pos = h+n;
		n++;
		if(pos>=MAX) pos-=MAX;
	}
	//n--;
	if(flag)
		return pos;
	else
		return null;
}

int searchQP(int key)
{
	int h = hashFunc(key), pos = h;
	while(hash_table[pos]!=null)
	{
		if(hash_table[pos]==key) 
		{
			flag=1;
			break;
		}
		pos = h+(n*n);
		n++;
		if(pos>=MAX) pos-=MAX;
	}
	//n--;
	if(flag)
		return pos;
	else
		return null;
}

int searchDH(int key)
{
	int h1 = hashFunc(key), h2 = IIhashFunc(key), h, pos=h1;
	while(hash_table[pos]!=null)
	{
		if(hash_table[pos]==key) 
		{
			flag=1;
			break;
		}
		pos = (h1+(n*h2))%47;
		n++;
		if(pos>=MAX) pos-=MAX;
	}
	//n--;
	if(flag)
		return pos;
	else
		return null;
}

void delKey(int key, int ch)
{
	int pos;
	pos = hashFunc(key);
	if(hash_table[pos]==key)
		hash_table[pos]=deleted;
	else
	{
		switch (ch)
		{
			case 1: 
				pos = searchLP(key);
				break;
			case 2: 
				pos = searchQP(key);
				break;
			case 3: 
				pos = searchDH(key);
				break;
		}
	}
	printf("--Key %d ",key);
	if(pos==null) 
		printf("Not found!");
	else 
	{
		hash_table[pos]=deleted;
		printf("Deleted!");
	}
}

void searchKey(int key, int ch)
{
	flag=0;
	int pos;
	pos = hashFunc(key);

	if(hash_table[pos]==key)
		hash_table[pos]=0;
	else
	{
		switch (ch)
		{
			case 1: 
				pos = searchLP(key);
				break;
			case 2: 
				pos = searchQP(key);
				break;
			case 3: 
				pos = searchDH(key);
				break;
		}
	}
	printf("--Key %d ",key);
	if(pos==null) 
		printf("Not found!");
	else 
		printf("is found at LOCATION : %d",pos);
}

void insertSC(int key)
{
	int pos = hashFunc(key);
	
	//check if key is already present
	for(int i=0; i<f[pos]; i++)
		if(hashtable[pos][i]==key)	return;

	//check if bucket (array) is already filled
	if(f[pos]>=5) 
		printf("\nOverflow! Can't insert %d!",key);
	else if(hashtable[pos][f[pos]]==null)
	{
		if(f[pos])
		{
			for(int i=4; i>0; --i)
				hashtable[pos][i]=hashtable[pos][i-1];
		}
		hashtable[pos][0]=key;
		f[pos]++;
	}

	printf("\n--Key %d",key);
	printf("\t\tLocation %d\tProbes : 1",pos);
}

int searchSC(int key, int pos)
{
	int i;
	flag=0;

	for(i=0; i<5; i++)
	{
		if(hashtable[pos][i]==key)
		{
			flag++;
			break;
		}
	}

	if(flag)
		return i;
	else
		return null;
}

int main()
{
	int a[40];
	//int a[5]={47, 96, 189, 94, 470};
	int c1,c2;
	int num;
				
	do
	{
		randomInput(a, 40);
		for(int i=0; i<MAX; i++) 
			hash_table[i]=null;

		for(int i=0; i<MAX; i++) 
		{
			for(int j=0; j<5; j++)
				hashtable[i][j] = null;
			f[i] = 0;
		}
	
		printf("\n\nA) SELECT A COLLISION RESOLUTION TECHNIQUE\n  1. Linear Probing\n  2. Quadratic Probing\n  3. Double Hashing\n  4. Separate Chaining\nB) EXIT (press 0)\n\nEnter your choice : ");
		scanf("%d",&c1);
		switch(c1)
		{
			case 0: break;
			case 1:
			do
			{
				printf("\n\n--LINEAR PROBING--\nA) SELECT THE OPERATION TO BE PERFORMED\n  1. Insertion\n  2. Deletion\n  3. Searching\nB) SELECT ANOTHER COLLISION RESOLUTION TECHNIQUE (Press 0)\n\nEnter your choice : ");
				scanf("%d",&c2);
				switch(c2)
				{
					case 0: break;
					case 1: 
						for (int i=0; i<SIZE; i++)
						{
							n=0;
							insertKey(a[i],LP);
						}
						break;
					case 2:
						n=0;
						printf("\nEnter the number to be deleted : ");
						scanf("%d",&num);
						delKey(num,LP);
						//printHash();
						break;
					case 3:
						n=0;
						printf("\nEnter the number to be searched : ");
						scanf("%d",&num);
						searchKey(num,LP);
						break;
					default: printf("Invalid choice!");
				}
			}while(c2!=0);
			break;
			
			case 2:
			do
			{
				printf("\n\n--QUADRATIC PROBING--\nA) SELECT THE OPERATION TO BE PERFORMED\n  1. Insertion\n  2. Deletion\n  3. Searching\nB) SELECT ANOTHER COLLISION RESOLUTION TECHNIQUE (Press 0)\n\nEnter your choice : ");
				scanf("%d",&c2);
				switch(c2)
				{
					case 0: break;
					case 1: 
						for (int i=0; i<SIZE; i++)
						{
							n=0;
							insertKey(a[i],QP);
						}
						break;
					case 2:
						n=0;
						printf("\nEnter the number to be deleted : ");
						scanf("%d",&num);
						delKey(num,QP);
						//printHash();
						break;
					case 3:
						n=0;
						printf("\nEnter the number to be searched : ");
						scanf("%d",&num);
						searchKey(num,QP);
						break;
					default: printf("Invalid choice!");
				}
			}while(c2!=0);
			break;

			case 3:
			do
			{
				printf("\n\n--DOUBLE HASHING--\nA) SELECT THE OPERATION TO BE PERFORMED\n  1. Insertion\n  2. Deletion\n  3. Searching\nB) SELECT ANOTHER COLLISION RESOLUTION TECHNIQUE (Press 0)\n\nEnter your choice : ");
				scanf("%d",&c2);
				switch(c2)
				{
					case 0: break;
					case 1: 
						for (int i=0; i<SIZE; i++)
						{
							n=0;
							insertKey(a[i],DH);
						}
						break;
					case 2:
						n=0;
						printf("\nEnter the number to be deleted : ");
						scanf("%d",&num);
						delKey(num,DH);
						break;
					case 3:
						n=0;
						printf("\nEnter the number to be searched : ");
						scanf("%d",&num);
						searchKey(num,DH);
						break;
					default: printf("Invalid choice!");
				}
			}while(c2!=0);
			break;

			case 4:
			do
			{
				int pos,p;
				printf("\n\n--SEPARATE CHAINING--\nA) SELECT THE OPERATION TO BE PERFORMED\n  1. Insertion\n  2. Deletion\n  3. Searching\nB) SELECT ANOTHER COLLISION RESOLUTION TECHNIQUE (Press 0)\n\nEnter your choice : ");
				scanf("%d",&c2);
				switch(c2)
				{
					case 0: break;
					case 1: 
						for (int i=0; i<SIZE; i++)
						{
							n=0;
							insertSC(a[i]);
						}
						//printHashSC();
						break;
					case 2:
						printf("\nEnter the number to be deleted : ");
						scanf("%d",&num);
						pos = hashFunc(num);
						p = searchSC(num, pos);
						
						printf("--Key %d ",num);
						if(p==null) 
							printf("Not found!");
						else 
						{
							for(int i=p; i<f[pos]; i++)
								hashtable[pos][i]=hashtable[pos][i+1];
							f[pos]--;
							printf("Deleted!");
						}
						//printHashSC();
						break;
					case 3:
						printf("\nEnter the number to be searched : ");
						scanf("%d",&num);
						pos = hashFunc(num);
						p = searchSC(num,pos);
		
						printf("--Key %d ",num);
						if(p==null) 
							printf("Not found!");
						else 
							printf("is found at LOCATION %d BUCKET %d",pos,p+1);
						break;
					default: printf("Invalid choice!");
				}
			}while(c2!=0);
			break;

			default: printf("Invalid choice!");
		}
	}while(c1!=0);
}