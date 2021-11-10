/*
a) Search for a given number in a sorted array using (i) linear search and (ii) binary search algorithms. The input to the program are: size of array and elements in the array. Generate the elements in the array using random number generator. The program should print the index of given number in the array if found.


b) Search for a given number in a two-dimensional array using only binary search. The elements in all the rows are sorted. The rows in the array are arranged such that last element of a row is smaller than first element of the next row. The input to the program are: number of rows and columns in the array and elements in the array. Generate the elements in the array using random number generator. The program should print the index of the given number in the array if found.

For each part of the program, print the number of comparisons also.

Name : Muniba Rahman
Faculty Number : 20COB275
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int a[100], b[100][100], m, n, num, p, c;
/*
m, n = to store the size of the arrays
num = number to be searched
p = to store the index of the given number in array (if found)
c = to count number of comparisons
*/

void printa(int[],int);	//for printing 1D Array
void printb();	//for printing 2D Array
void asort(int[],int);	//for sorting the 1D Array
void bsort();	//for sorting the 2D Array
void linear();	//for performing linear search in 1D Array
void abinary();	//for performing binary search in 1D Array
int bbinary();	//for performing binary search in 2D Array

int main()
{
    int i,j;
    time_t t;
    int flag=0;
    srand((unsigned) time(&t));
printf("\n__________PART A__________\n");
    printf("\nEnter size of array : "); scanf("%d",&n);
    for(i=0;i<n;i++)
        a[i]=rand()%1000;
    asort(a,n);
    printa(a,n);
    printf("\nElement to be searched? "); scanf("%d",&num);
    printf("\nLinear Search :\n");
    linear();
    printf("\n\nBinary Search :\n");
    abinary();
printf("\n\n__________PART B__________\n");        
    printf("\nEnter size of 2D array (rows and columns) : "); scanf("%d%d",&m,&n);
    srand((unsigned)time(&t));
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            b[i][j]=rand()%1000;

    bsort();
    printb();
    printf("\nElement to be searched? "); scanf("%d",&num); 
    c=0;
    for(i=0;i<m;i++)
    {      
        c+=2;
    	if(num == b[i][0])
    	{
    		flag=1; c-=1;
    		printf("\nElement %d found in row %d position 1",num,i+1);
    		break;
    	}
    	else if(num == b[i][n-1])
    	{
    		flag=1; 
    		printf("\nElement %d found in row %d position %d",num,i+1,n);
    		break;
    	}
        else if(num > b[i][0] && num < b[i][n-1])
        {
            flag=bbinary(i);
            break;
        }
                
    }
    if(flag==0) printf("\nElement %d not found!",num);
    printf("\nNumber of comparisons : %d",c);   
    return 0;
}
void asort(int array[],int N)
{
    int i,j,t;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;
            }
        }
    }
}

void printa(int array[],int N)
{
    int i;
    printf("\n");
    for(i=0;i<N;i++) printf("%d\t",array[i]);
    printf("\n");
}

void linear()
{
    int i,flag=0;
    c=0;
    for(i=0;i<n;i++) 
    {
        c++;
        if(a[i]==num) 
        {
            p=i;
            flag++;
            break;
        }
    }
    if(flag==0)
    printf("\nElement %d not found!",num);
    else
    printf("\nElement %d found at position %d",num,p+1);
    printf("\nNumber of comparisons : %d",c);
}


void abinary()
{
    int f=0,l=n-1,mid,flag=0;
    c=0;
    do{
      c++;
      mid=(f+l)/2;
      if(num>a[mid]) l=mid-1;
      else if(num<a[mid]) f=mid+1;
      else if(num==a[mid]) 
      {
        p=mid;
        flag++;
        break;
      }
    }while(f<=l);
    if(flag==0)
    printf("\nElement %d not found!",num);
    else
    printf("\nElement %d found at position %d",num,p+1);
    printf("\nNumber of comparisons : %d",c);
}
void bsort()
{
    int i,j,temp[1000],index=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            temp[index++]=b[i][j];
        }
    }
    asort(temp,index);
    index=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=temp[index++];
        }
    }
}
int bbinary(int x)
{
    int f=0,l=n-1,mid,flag=0;
    do{
      c++;
      mid=(f+l)/2;
      if(num>b[x][mid]) l=mid-1;
      else if(num<b[x][mid]) f=mid+1;
      else if(num==b[x][mid]) 
      {
        p=mid; 
        flag++;
        break;
      }
    }while(f<=l);
    
    if(flag!=0)
    printf("\nElement %d found in row %d position %d",num,x+1,p+1);

    return flag;
}
void printb()
{
    int i,j;
    printf("\n");
    for(i=0;i<m;i++) 
    {
        for(j=0;j<n;j++)
            printf("%d\t",b[i][j]);
        printf("\n");
    }
}


