/*

Write a program in C/C++ to implement quicksort when pivot element is
a) The first element of the sub-array.
b) Median of first, last and middle element of the sub-array.
c) Randomly chosen as any element in sub-array.
d) The middle element of the sub-array (if size of sub-array is even, then any of the middle two elements can be taken as pivot).
For a given input array, print the intermediate results after each pass in each case. Also print the number of comparisons in each case.

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

#include <iostream>
#include <stdlib.h>

#define MEDIAN 1
#define RANDOM 2
#define MIDDLE 3

using namespace std;

class Array
{
	int *a, n; 
public:
	int comp=0, pass=0;
	//constructor to create an array of the desired size with random elements 
	Array(int x)
	{
		n = x;
		a= new int(n);
		srand(time(NULL));
		for(int i=0; i<n; i++)
			a[i]=rand()%100;
			//cin>>a[i];
	}

	void display();
	void swap(int*, int*);
	void quickSort(int, int, int);
	void setPivot(int, int, int);
	int partition(int, int);
};

//to display the array
void Array::display()
{
	for(int i=0; i<n; ++i)
		cout<<a[i]<<"  ";
	cout<<endl;
}

//to swap two elements
void Array::swap(int *a, int *b)
{
	int t;
	t = *a;		*a = *b;	*b = t;
}

//to set some other element than the first element of the sub-array as the pivot
void Array::setPivot(int beg, int end, int ch=0)
{
	//if the user chooses the first element as a pivot, do nothing
	if(ch==0) return;
	int median, big, small;
	int mid;
	int any;
	switch(ch)
	{
		case MEDIAN: 
			mid = (beg+end)/2;
			//BIG contains the largest of the three (beg, mid, end)
			big = a[beg]>a[mid] ? (a[beg]>a[end] ? beg : end) : (a[mid]>a[end] ? mid : end);
			//SMALL contains the smallest of the three
			small = a[beg]<a[mid] ? (a[beg]<a[end] ? beg : end) : (a[mid]<a[end] ? mid : end);

			//hence MEDIAN could be determined 
			if((beg == big && end == small) || (beg == small && end == big)) 
				median = mid;
			else if((mid == big && end == small) ||  (mid == small && end == big)) 
				median = beg;
			else 
				median = end;

			//swap the desired pivot with the FIRST element of the sub-array
			swap(&a[beg], &a[median]);
		break;

		case RANDOM:
			srand(time(NULL));
			//ANY contains a random index between the BEG and END of the sub-array
			any = beg + (rand() % (end-beg));
			//swap the desired pivot with the FIRST element of the sub-array
			swap(&a[beg], &a[any]);
		break;

		case MIDDLE:
			//MID stores the index of middle element of the given sub-array
			mid = (beg+end)/2;
			//swap the desired pivot with the FIRST element of the sub-array
			swap(&a[beg], &a[mid]);
		break;
	}
}

/*
int Array::partition(int beg, int end)
{
	int pivot = a[beg];
	int i = beg+1, j = end;
	while(i<=end)
	{
		if(a[i]<pivot) 
		{
			++i;
			++comp;
		}

		if(j<=beg) break;

		if(a[j]<=pivot)
		{
			if(j<=i)
			{
				swap(&a[j], &a[beg]);
				++comp;
				return j;
			}
			else
			{
				swap(&a[i], &a[j]);
				++comp;
				++i;
			}
		}
		else
		{
			--j;
			++comp;
		}
	}
	return beg;
}
*/

//to bring the first element of the sub-array at it's appropiate place
int Array::partition(int beg, int end)
{
	//set the FIRST element of the sub-array as pivot
	int pivot = a[beg];
	int i = beg+1, j = end;
	while(i<=end)
	{
		//set pointer I to the first element from the BEG which is found bigger than the PIVOT
		while(a[i]<=pivot)
		{
			++i;
			++comp;
		}

		//set pointer J to the first element from the END which is found smallest than the PIVOT
		while(a[j]>pivot)
		{
			--j;
			++comp;
		}

		//if pointer I and J have crossed each other
		if(j<=i)
		{
			//swap the PIVOT with the element at J
			swap(&a[j], &a[beg]);
			return j;
		}
		else
		{
			swap(&a[i], &a[j]);
			++i;	--j;
		}

		//break if pointer J reaches left end of the sub-array
		if(j<=beg) break;
	}
	return beg;
}

void Array::quickSort(int p, int q, int ch=0)
{
	if(p<=q)
		cout<<"\n  -> Accessing sub-array from index "<<p<<" - "<<q<<endl;

	if(p<q)
	{
		cout<<"\n---Pass "<<++pass<<"---"<<endl;
		comp=0;

		//bring the desired pivot to the beginning of the sub-array
		switch(ch)
		{
			case 1:	setPivot(p,q);			break;
			case 2:	setPivot(p,q,MEDIAN);	break;
			case 3: setPivot(p,q,RANDOM);	break;
			case 4: setPivot(p,q,MIDDLE);	break;
		}
		//bring the first element of the sub-array at it's appropiate place
		int r = partition(p,q);
		cout<<"\nPIVOT : "<<a[r]<<endl;
		display();
		cout<<"COMPARISONS : "<<comp<<endl;
		//repeat the same procedures for another pair of sub-arrays
		quickSort(p, r-1, ch);
		quickSort(r+1, q, ch);
	}
}

int main()
{
	int len,ch;
	cout<<"Enter the number of elements in array : ";
	cin>>len;
	//declaring an object of class ARRAY with LEN as argument for the parameterized constructor
	Array A(len);
	//ask user for the choice of pivot
	cout<<"\nWHICH ELEMENT IS TO TAKEN AS PIVOT?\n  1. FIRST element of the sub-array\n  2. MEDIAN of first, last and middle element of the sub-array\n  3. RANDOMLY chosen as any element in sub-array\n  4. The MIDDLE element of the sub-array\nYour choice : ";
	cin>>ch;
	if(!(ch>=1 && ch<=4)) 
	{
		cout<<"\nInvalid choice!\n";
		exit(0);
	}
	cout<<"\nInitial Array :\n";
	A.display();
	A.quickSort(0,len-1,ch);
	cout<<"\nSorted Array :\n";
	A.display();
	return 0;
}