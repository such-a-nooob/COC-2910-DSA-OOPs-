/*
Sort an array of integers using standard bubble sort algorithm in JAVA/C++. Make a BubbleSort class with input array as a private member and swap (to swap to values in the input array) and display (to print the input array) methods.

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class BubbleSort {
    int a[1000], n;
    public:
    BubbleSort()
    {
	cout<<"Enter the number of elements in array (n) : "; cin>>n;
	time_t t;
	srand((unsigned) time(&t));
	for(int i=0; i<n; i++)
		a[i]=rand()%1000;
    }
    void swap(int x, int y)
    {
        int t;
        t=a[x], a[x]=a[y]; a[y]=t;
    }
    void display()
    {
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
    }
    void bsort();
};

void BubbleSort::bsort()
{
    for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(a[j]>a[j+1]) swap(j, j+1);
		}
	}
}

int main()
{
    BubbleSort obj;
    cout<<"Initial Array :\n";
    obj.display();
    obj.bsort();
    cout<<"\nSorted Array :\n";
    obj.display();
    return 0;
}
