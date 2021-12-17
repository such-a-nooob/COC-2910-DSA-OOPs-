#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50 
#define LP 1	//Linear Probing
#define QP 2	//Quadratic Probing
#define DH 3	//Double Hashing
#define SC 4	//Seperate Chaining
#define null -1
#define deleted -2

int hash_table[MAX];
//for seperate chaining
typedef struct 
{
	int bucket[5];
	int f;
}ht;
/*f = number of occupied buckets at a particular hash location
  or in simple words it stores how many numbers are chained at a particular location of the hashtable 

  For instance a hashtable of size 3 is shown below, value of f will be as follows :
  0) --> 34 --> 45		f = 2
  1) --> \0				f = 0
  2) --> 66				f = 1
*/

ht hashtable[MAX];
ht* ptr = NULL;	//to access the hashtable

int n,flag;
/*n = number of probes
  flag = 1 Number is present in hash table
  flag = 0 Number is not present in hash table */

void printHash();
void printHashSC();
void randomInput(int[],int);
int hashFunc(int);
int IIhashFunc(int);
void insertKey(int,int);
int insertLP(int);
int insertQP(int);
int insertDH(int);
void insertSC(int);
void delKey(int,int);
void searchKey(int,int);
int searchLP(int);
int searchQP(int);
int searchDH(int);
int searchSC(int);
void shiftRight(int[]);
void shiftLeft(ht*,int);


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

		ptr = hashtable;
		for(int i=0; i<MAX; i++) 
		{
			for(int j=0; j<5; j++)
				ptr->bucket[j] = null;
			ptr->f = 0;
			ptr++;
		}
	
		printf("\n\nA) SELECT A COLLISION RESOLUTION TECHNIQUE\n  1. Linear Probbing\n  2. Quadratic Probbing\n  3. Double Hashing\n  4. Seperate Chaining\nB) EXIT (press 0)\n\nEnter your choice : ");
		scanf("%d",&c1);
		switch(c1)
		{
			case 0: break;
			case 1:
			do
			{
				printf("\n\n--LINEAR PROBBING--\nA) SELECT THE OPERATION TO BE PERFORMED\n  1. Insertion\n  2. Deletion\n  3. Searching\nB) SELECT ANOTHER COLLISION RESOLUTION TECHNIQUE (Press 0)\n\nEnter your choice : ");
				scanf("%d",&c2);
				switch(c2)
				{
					case 0: break;
					case 1: 
						for (int i=0; i<40; i++)
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
				printf("\n\n--QUADRATIC PROBBING--\nA) SELECT THE OPERATION TO BE PERFORMED\n  1. Insertion\n  2. Deletion\n  3. Searching\nB) SELECT ANOTHER COLLISION RESOLUTION TECHNIQUE (Press 0)\n\nEnter your choice : ");
				scanf("%d",&c2);
				switch(c2)
				{
					case 0: break;
					case 1: 
						for (int i=0; i<40; i++)
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
						for (int i=0; i<40; i++)
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
				printf("\n\n--SEPERATE CHAINING--\nA) SELECT THE OPERATION TO BE PERFORMED\n  1. Insertion\n  2. Deletion\n  3. Searching\nB) SELECT ANOTHER COLLISION RESOLUTION TECHNIQUE (Press 0)\n\nEnter your choice : ");
				scanf("%d",&c2);
				switch(c2)
				{
					case 0: break;
					case 1: 
						for (int i=0; i<40; i++)
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
						p = searchSC(num);
						ptr = hashtable+pos;
						printf("--Key %d ",num);
						if(p==null) 
							printf("Not found!");
						else 
						{
							shiftLeft(ptr,p);
							(ptr->f)--;
							printf("Deleted!");
						}
						//printHashSC();
						break;
					case 3:
						printf("\nEnter the number to be searched : ");
						scanf("%d",&num);
						pos = hashFunc(num);
						p = searchSC(num);
						
						printf("--Key %d ",num);
						if(p==null) 
							printf("Not found!");
						else 
							printf("is found at LOCATION : %d",pos);
						break;
					default: printf("Invalid choice!");
				}
			}while(c2!=0);
			break;

			default: printf("Invalid choice!");
		}
	}while(c1!=0);
}

void printHash()
{
	printf("\n");
	for (int i=0; i<MAX; ++i)
		printf("%d  ->  %d\n",i,hash_table[i]);
}

void printHashSC()
{
	int i,j;
	ptr = hashtable;
	printf("\n");
	for (i=0; i<MAX; ++i)
	{
		printf("%d",i);
		for(j=0; j<5; j++)
			printf("\t->\t%d",(ptr+i)->bucket[j]);
		printf("\n");
		printf("Numbers in chain : %d\n",(ptr+i)->f);
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
	printf("\nLocation : %d\tProbes : %d",pos,n);
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
	//n--;
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
	//n--;
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

void shiftRight(int b[])
{
	for(int i=4; i>0; --i)
		b[i]=b[i-1];
}

void insertSC(int key)
{
	int pos;
	pos = hashFunc(key);
	ptr = hashtable+pos;
	int f= ptr->f;
	n++;
	if(f>=5) printf("\nOverflow! Can't insert %d!",key);
	else if(ptr->bucket[f]==null)
	{
		if(f)
		shiftRight(ptr->bucket);
		ptr->bucket[0]=key;
		(ptr->f)++;
	}
	else 
	{
		for(int i=0; i<(f); i++)
			if(ptr->bucket[i]==key)	return;
	}

	printf("\n--Key %d",key);
	printf("\nLocation : %d\tProbes : %d",pos,n);
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

void shiftLeft(ht* x, int y)
{
	for(int i=y; i<(x->f); i++)
		x->bucket[i]=x->bucket[i+1];
}

int searchSC(int key)
{
	int pos, i;
	pos = hashFunc(key);
	ptr = hashtable+pos;
	flag=0;

	for(i=0; i<(ptr->f); i++)
	{
		if(ptr->bucket[i]==key)
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
