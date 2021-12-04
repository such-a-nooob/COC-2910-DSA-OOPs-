/*

Write a program in C++/Java to implement Merge Sort. 
Implementation must be non-recursive as explained in the lecture. 
Use tabbing with binary search in the merging process. Show the intermediate output after each pass

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

#include <iostream>
#include <cmath>
using namespace std;

class Array
{
	int *a, n;
public:
	Array()
	{
		cout<<"Enter the number of elements in array : ";
		cin>>n;
		a= new int(n);
		time_t t;
		srand((unsigned) time(&t));
		for(int i=0; i<n; i++)
			a[i]=rand()%1000;
	}

	void display();
	void merge(int, int, int);
	void shiftRight(int, int);
	int findLoc(int, int, int);
	void mergeSort();
};

void Array::shiftRight(int x, int y)
{
	for(int i=y; i>x; i--)
		a[i]=a[i-1];
}

int Array::findLoc(int f, int l, int x)
{
	int mid,p=-1;
    do{
    	mid=(f+l)/2;
    	if(a[x]<a[mid])
    		l=mid-1;
    	else if(a[x]>a[mid]) 
    	{
    		f=mid+1;
    		p=mid;
		}
		else
			return p;
    }while(f<=l);
    return p;
}


void Array::merge(int s, int mid, int e)
{
	int temp, pos;
	for(int i=e; i>=mid+1; i--)
	{
		if(a[i]>a[mid]) continue;
		temp = a[mid];
		pos = findLoc(s, mid-1, i);
		if(pos==-1)
		{
			shiftRight(s,mid);
			a[s]=a[i];
		}
		else
		{
			shiftRight(pos, mid);
			a[pos+1]=a[i];
		}
		a[i]=temp;
	}
}

/*
void Array::merge(int s, int mid, int e)
{
	int t1=s, t2=mid+1, t3=0;
	int temp[100];
	while(t1<=mid && t2<=e)
	{
		if(a[t1]<a[t2])
		{
			temp[t3]=a[t1];
			t1++; t3++;
		}
		else
		{
			temp[t3]=a[t2];
			t2++; t3++;		
		}
	}

	if(t1>mid)
	{
		while(t2<=e) 
		{
			temp[t3]=a[t2];
			t2++; t3++;
		}
	}

	else
	{
		while(t1<=mid) 
		{
			temp[t3]=a[t1];
			t1++; t3++;
		}
	}

	int x,y;
	for(x=0,y=s; y<=e; x++,y++)
		a[y]=temp[x];
}
*/

void Array::mergeSort()
{
	int i, j, k, mid;
	for(i=0; pow(2,i)<n; i++)
	{
		for(j=0; j<n; j+=pow(2,i+1))
		{
			k=j+(pow(2,i+1)-1);
			if(k>=n) k=n-1;
			if(j==0 && k==n-1)
				mid=(pow(2,i)-1);
			else
				mid=(j+k)/2;
			merge(j,mid,k);
		}
		cout<<"\nPass "<<i+1<<" : ";
		display();
	}
}

void Array::display()
{
	printf("\n");
	for (int i=0; i<n; i++)
		printf("%d\t",a[i]);
	printf("\n");
}


int main()
{
	Array a1;
	cout<<"\nInitial Array :\n";
	a1.display();
	a1.mergeSort();
	cout<<"\nArray after Merge Sort :";
	a1.display();

	return 0;
}