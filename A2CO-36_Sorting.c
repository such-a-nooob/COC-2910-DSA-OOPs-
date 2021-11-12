/*

Write a program in C to
a) Sort an array of integers using standard bubble sort algorithm. Also implement a variation of bubble sort that use both   “early termination” and “alternate passes in opposite direction”.
b) Sort an array of integers using standard insertion sort algorithm. Also implement a variation of insertion sort that use binary search to find the proper location to insert the next element instead of linear search.

Input to the program is the size of array. Generate numbers using random number generator. For each part of the program, show the intermediate output and total number of comparisons after each pass. For 2(b), also print the number of elements required to move in order to free the proper location of next element after each pass.

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomInput(int[], int);
void printArray(int[], int);
int swap(int*, int*);
void stdBubbleSort(int[], int);
void cocktailShakerSort(int[], int);
int linearSearch(int[], int);
int binarySearch(int[], int);
void shiftRight(int[], int, int);
void stdInsertionSort(int[], int);
void binaryInsertionSort(int[], int);

int cmp;
int line;

int main()
{
	int a[1000], n, f, i, j;
	
	printf("\n_________Part 1(a)_________\n");
	
	printf("\nEnter the size of the array : ");		scanf("%d",&n);
	randomInput(a,n);
	printArray(a,n);
	printf("\nStandard Bubble Sort :");
	stdBubbleSort(a,n);

	printf("\n\n_________Part 1(b)_________\n");
	
	printf("\nEnter the size of the array : ");		scanf("%d",&n);
	randomInput(a,n);
	printArray(a,n);
	printf("\nBidirectional Bubble Sort (a variation of bubble sort that use both   \"early termination\" and \"alternate passes in opposite direction\" ) :");
	cocktailShakerSort(a,n);

	printf("\n\n_________Part 2(a)_________\n");
	
	printf("\nEnter the size of the array : ");		scanf("%d",&n);
	randomInput(a,n);
	printArray(a,n);
	printf("\nStandard Insertion Sort :");
	stdInsertionSort(a,n);

	printf("\n\n_________Part 2(b)_________\n");
	
	printf("\nEnter the size of the array : ");		scanf("%d",&n);
	randomInput(a,n);
	printArray(a,n);
	printf("\nBinary Insertion Sort ( a variation of insertion sort that use binary search to find the proper location to insert the next element instead of linear search ) :");
	binaryInsertionSort(a,n);

	return 0;
}

void randomInput(int a[], int n)
{
	time_t t;
	srand((unsigned) time(&t));
	for(int i=0; i<n; i++)
		a[i]=rand()%1000;
}

void printArray(int a[], int n)
{
	printf("\n");
	for (int i=0; i<n; i++)
	{
		printf("%d\t",a[i]);
		if(line) if(i==line /* && i!=n-1 */) printf("|\t");
	}
	printf("\n");
}

int swap(int *x, int *y)
{
	int t;
	t=*x;	*x=*y;	*y=t;
	return 1;
}

void stdBubbleSort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		cmp=0;
		printf("\n--> PASS %d",i+1);
		for(int j=0; j<n-i-1; j++)
		{
			cmp++;
			if(a[j]>a[j+1]) swap(&a[j],&a[j+1]);
			printArray(a,n);
		}
		printf("Comparisons : %d\n",cmp);
	}
	printf("\nFINAL OUTPUT : ");
	printArray(a,n);	
}

void cocktailShakerSort(int a[], int n)
{
	int i, j, swaped=1;
	for(i=0; ; i++)
	{
		if(!swaped) break; 
		cmp=0; swaped=0;
		printf("\n--> PASS %d",i+1);
		printf("\n--Forward Pass--");
		for(j=i; j<n-i-1; j++)
		{
			cmp++;
			if(a[j]>a[j+1]) swaped=swap(&a[j],&a[j+1]);
			printArray(a,n);
		}
		printf("Comparisons : %d\n",cmp);	
		if(!swaped) break;
		cmp=0; --j; swaped=0;
		printf("\n--Backward Pass--");
		for (;j>i; j--)
		{
			cmp++;
			if(a[j]<a[j-1]) swaped=swap(&a[j],&a[j-1]);
			printArray(a,n);
		}
		printf("Comparisons : %d\n",cmp);			
	}
	printf("\nFINAL OUTPUT : ");
	printArray(a,n);
}

void shiftRight(int a[], int n, int p)
{
	for(int i=n; i>=p; i--)
		a[i]=a[i-1];
}

int linearSearch(int a[], int n)
{
	int p=n;
	for(int i=n-1; i>=0; i--)
	{
		if(a[n]<a[i]) p=i;
		cmp++;
	}
	return p;
}

void stdInsertionSort(int a[], int n)
{
	int temp, pos;
	for(int i=1; i<n; i++)
	{
		cmp=0; 
		pos=linearSearch(a,i);
		if(pos!=i)
		{
			temp=a[i];
			shiftRight(a,i,pos);
			a[pos]=temp;
		}	
		printf("\n--> PASS %d\n",i);
		printf("Comparisons : %d",cmp);
		printf("\nElements moved : %d",i-pos);
		line=i;
		printArray(a,n);
		line=0;
	}
	printf("\nFINAL OUTPUT : ");
	printArray(a,n);
}

int binarySearch(int a[], int n)
{
	int f=0,l=n-1,mid,p=n;
    cmp=0;
    do{
      cmp++;
      mid=(f+l)/2;
      if(a[n]<=a[mid])
      {
      	l=mid-1;
      	p=mid;
      }
      else if(a[n]>a[mid]) 
      	f=mid+1;
    }while(f<=l);
    return p;
}

void binaryInsertionSort(int a[], int n)
{
	int temp, pos;
	for(int i=1; i<n; i++)
	{
		cmp=0; 
		pos=binarySearch(a,i);
		if(pos!=i)
		{
			temp=a[i];
			shiftRight(a,i,pos);
			a[pos]=temp;
		}	
		printf("\n--> PASS %d\n",i);
		printf("Comparisons : %d",cmp);
		printf("\nElements moved : %d",i-pos);
		line=i;
		printArray(a,n); 
		line=0;
	}
	printf("\nFINAL OUTPUT : ");
	printArray(a,n);
}


