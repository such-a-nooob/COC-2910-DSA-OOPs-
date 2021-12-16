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
			//cin>>a[i];
	}

	void display();
	void mergeBinTab(int, int, int);
	void mergeBinary(int, int, int);
	void shiftRight(int, int);
	int findLoc(int, int, int);
	void mergeSort();
};

void Array::shiftRight(int lastpos, int y)
{
	for(int i=y; i>lastpos; i--)
		a[i]=a[i-1];
}

int Array::findLoc(int f, int l, int lastpos)
{
	int mid,p=-1;
    do{
    	mid=(f+l)/2;
    	if(a[lastpos]<a[mid])
    		l=mid-1;
    	else if(a[lastpos]>a[mid]) 
    	{
    		f=mid+1;
    		p=mid;
		}
		else
			return p;
    }while(f<=l);
    return p;
}

void Array::mergeBinTab(int s, int mid, int e)
{
	double l1=(mid-s)+1, l2=e-(mid+1)+1, L=l1/l2;
	int l=ceil(L); 
	int flag, ptr=mid+1, lastpos=mid;
	int temp, pos;
	
	//l1 and l2 = lengths of the two groups that are to be merged
	//l = size of a tab
	//ptr = points/marks the beginning of second group
	//lastpos = points/marks the position where the last element is inserted

	//if the largest element is already at the last, nothing to do with the last element		
	if(a[e]>a[mid]) e--;

	for(int i=e; i>=ptr; i--)
	{
		flag=0;
		//if the selected element is the smallest, place it at the very starting of the group
		if(a[i]<a[s])
		{
			temp=a[i];
			shiftRight(s,i);
			//shifting causes a change in the length of the second group
			//i++ because the next element to be sorted in the second group has now shifted right
			i++; ptr++;
			a[s]=temp;
			continue;
		}
		//dividing the groups into tabs 
		for(int j=lastpos, k=j-l+1; j>s; j-=l, k-=l)
		{
			if(k<s) k=s;
			//checking the right tab to insert the selected element 
			if(a[i]<=a[j] && a[i]>=a[k]) 
			{
				temp = a[i];
				//finding the correct position of the selected element in a tab using binary search
				pos = findLoc(k, j, i);
				shiftRight(pos, i);
				i++; ptr++; 
				a[pos+1]=temp;
				lastpos=pos+1;
				flag++;
				break;
			}
		}
		//if flag is zero i.e. the element was not inserted WITHIN any tabs, 
		//so the selected element should be inserted somewhere BETWEEN two tabs
		if(!flag)
		{
			for(int j=lastpos-l, k=j+1; j>s; j-=l, k-=l)
			{
				if(k<s) k=s;
				if(a[i]<=a[k] && a[i]>=a[j]) 
				{
					temp = a[i];
					pos=j;
					shiftRight(pos, i);
					i++; ptr++; 
					a[pos+1]=temp;
					lastpos=pos+1;
					break;
				}
			}
		}
	}
}

void Array::mergeBinary(int s, int mid, int e)
{
	int temp, pos;
	for(int i=e; i>=mid+1; i--)
	{
		//if the largest element is already at the end, do nothing  
		if(a[i]>a[mid]) continue;
		temp = a[mid];
		pos = findLoc(s, mid-1, i);
		//if pos is -1, the current element is smallest of all the elements present in the first group
		// and is to be inserted at the beginning
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

//Two-Way Merge
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

	int lastpos,y;
	for(lastpos=0,y=s; y<=e; lastpos++,y++)
		a[y]=temp[lastpos];
}
*/

int checkL(int n)
{
	for(int i=1; pow(2,i)<=n; i++)
		if(pow(2,i)==n+1) return 1;
	return 0;
}

void Array::mergeSort()
{
	int i, j, k, mid, lprev, jprev, kprev, l;
	for(i=0; pow(2,i)<n; i++)
	{
		for(j=0; j<n; j+=pow(2,i+1))
		{
			k=j+(pow(2,i+1)-1);
			if(k>=n) k=n-1;

			//if a group consists og just one number, it doesn't need to be sorted
			if(j==k) continue;

			jprev = j-pow(2,i+1);
			kprev = jprev+(pow(2,i+1)-1);
			lprev = kprev-jprev;
			l=k-j;

			//in the last pass the mid could be different, so if it's the last pass, calculate the mid as it was calculated in the pass before
			//Otherwise, calculate the mid by simply taking the average of the upper and lower bounds of a group
			if((j==0 && k==n-1))
			{
				mid=(pow(2,i)-1);
				mergeBinary(j,mid,k);
				break;
			}
			
			if(l!=lprev)
			{
				if(checkL(l))
					mid=(j+k)/2;
				else
					mid=j+pow(2,i)-1;
			}
			else
				mid=(j+k)/2;
			
			//if the two groups to be merged are of same size, merge them using the binary method 
			//if the sizes are different, merge using Tabbing (and Binary search)
			if((mid-j) == (k-(mid+1)))
				mergeBinary(j,mid,k);
			else
				mergeBinTab(j,mid,k);
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
