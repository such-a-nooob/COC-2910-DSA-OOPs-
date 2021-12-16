/*
Implement a class in C++/Java for 
(a) (plain) two-dimensional matrix having methods for each of the following operations: add, subtract, multiply. 
(b) sparse matrix having methods for each of the following operations: add, subtract, multiply. If most of the elements of the matrix have 0 value, then it is called a sparse matrix. The following representation can be used for the sparse matrix implementation:
A 2D array can be used to represent a sparse matrix in which there are three rows named as Row: Index of row, where non-zero element is located Column: Index of column, where non-zero element is located Value: Value of the non zero element located at index – (row,column)
The number of columns is equal to the number of non-zero elements in the spares matrix 

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 100

//PLAIN MATRIX OPERATIONS
class Matrix
{
	int mat[MAX][MAX], row, col;
public:
	Matrix()
	{
		//time_t t;
		//srand((unsigned) time(&t));
		cout<<"\nEnter number of rows and columns : ";
		cin>>row>>col;
		cout<<"Enter "<<row*col<<" elements in matrix\n";
		for(int i=0; i<row; i++)
			for(int j=0; j<col; j++) 
				//mat[i][j]=rand()%50;
				cin>>mat[i][j];
	}

	void showMatrix();
	void showMatrix(int, int, int[][MAX]);
	void add2D(Matrix);
	void sub2D(Matrix);
	void mul2D(Matrix);	
};

void Matrix::showMatrix()
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout<<mat[i][j]<<" \t ";
		cout<<'\n';
	}
}

void Matrix::showMatrix(int m, int n, int x[][MAX])
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			cout<<x[i][j]<<" \t ";
		cout<<'\n';
	}
}

void Matrix::add2D(Matrix b)
{
	cout<<"\nOn Adding Matrices\n";
	if(!(row==b.row && col==b.col)) cout<<"\nCan't add!\nEntered Matrices are not in same order!\n";
	else
	{
		int res[MAX][MAX];
		for(int i=0; i<row; i++)
			for (int j=0; j<col; j++)
				res[i][j]=mat[i][j]+b.mat[i][j];
	
		showMatrix(row,col,res);	
	}
}

void Matrix::sub2D(Matrix b)
{
	cout<<"\nOn Subtrating Matrices\n";
	if(!(row==b.row && col==b.col)) cout<<"\nCan't subtract!\nEntered Matrices are not in same order!\n";
	else
	{
		int res[MAX][MAX];
		for(int i=0; i<row; i++)
			for (int j=0; j<col; j++)
				res[i][j]=mat[i][j]-b.mat[i][j];
	
		showMatrix(row,col,res);
	}	
}

void Matrix::mul2D(Matrix b)
{
	cout<<"\nOn Multiplying Matrices\n";
	if(col!=b.row) cout<<"\nCan't multiply!\nEntered Matrices are not in correct order!\n";
	else
	{
		int res[MAX][MAX];
		for(int i=0; i<row; i++)
		{
			for (int j=0; j<b.col; j++)
			{
				res[i][j]=0;
				for(int k=0; k<col; k++)
					res[i][j]+=mat[i][k]*b.mat[k][j];
			}
		}
		showMatrix(row,b.col,res);
	}
}

//SPARSE MATRIX OPERATIONS
class sparseMatrix
{
	int smat[MAX][MAX], row, col,n;
public:
	int res[MAX][MAX], tres;
	sparseMatrix()
	{
		cout<<"\nEnter number of rows and columns : ";
		cin>>row>>col;
		cout<<"Enter the number of non-zero elements : ";
		cin>>n;
		cout<<"Enter "<<n<<" triplets (Row, Coulumn, Value) :\n";
		for(int i=0; i<n; i++)
			for(int j=0; j<3; j++)
				cin>>smat[i][j];
	}

	void showSparse();
	void showSparse(int, int[][MAX]);
	int validateSparse();
	void insert(int, int, int);
	void addSparse(sparseMatrix);
	void subSparse(sparseMatrix);
	void mulSparse(sparseMatrix);	
};

void sparseMatrix::showSparse()
{
	cout<<"Row\tCol\tVal\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<3; j++)
			cout<<smat[i][j]<<"\t";
		cout<<'\n';
	}
}

void sparseMatrix::showSparse(int x, int mat[][MAX])
{
	cout<<"Row\tCol\tVal\n";
	for(int i=0; i<x; i++)
	{
		for(int j=0; j<3; j++)
			cout<<mat[i][j]<<"\t";
		cout<<'\n';
	}
}

int sparseMatrix::validateSparse()
{
	for (int i=0; i<n; i++)
	{
		if(smat[i][0]>row || smat[i][1]>col) return 0;
	}
	return 1;
}

void sparseMatrix::insert(int x, int y, int z)
{
	res[tres][0]=x;
	res[tres][1]=y;
	res[tres][2]=z;	
	tres++;
}

void sparseMatrix::addSparse(sparseMatrix sb)
{
	cout<<"\nOn Adding Sparse Matrices\n";
	if(row!=sb.row || col!=sb.col) cout<<"\nCan't add!\nEntered Matrices are not in same order!\n";
	else
	{
		tres=0;
		int ta=0, tb=0;
		while(ta<n && tb<sb.n)
		{
			if((smat[ta][0]==sb.smat[tb][0] && smat[ta][1]<sb.smat[tb][1]) || smat[ta][0]<sb.smat[tb][0])
			{
				insert(smat[ta][0],smat[ta][1],smat[ta][2]);
				ta++;
			}
			else if((smat[ta][0]==sb.smat[tb][0] && smat[ta][1]>sb.smat[tb][1]) || smat[ta][0]>sb.smat[tb][0])
			{
				insert(sb.smat[tb][0],sb.smat[tb][1],sb.smat[tb][2]);
				tb++;
			}
			else if((smat[ta][0]==sb.smat[tb][0] && smat[ta][1]==sb.smat[tb][1]))
			{
				insert(smat[ta][0],smat[ta][1],smat[ta][2]+sb.smat[tb][2]);
				ta++; tb++;
			}
		}

		//for remaining elements in any matrix
		if(ta<n)
		{
			while(ta<=n) 
			{
				insert(smat[ta][0],smat[ta][1],smat[ta][2]);
				ta++;
			}
		}

		if(tb<sb.n)
		{
			while(tb<=sb.n) 
			{
				insert(sb.smat[tb][0],sb.smat[tb][1],sb.smat[tb][2]);
				tb++;
			}
		}
		showSparse(tres-1,res);	
	}
}

void sparseMatrix::subSparse(sparseMatrix sb)
{
	cout<<"\nOn Subtrating Sparse Matrices\n";
	if(row!=sb.row || col!=sb.col) cout<<"\nCan't add!\nEntered Matrices are not in same order!\n";
	else
	{
		tres=0;
		int ta=0, tb=0;
		while(ta<n && tb<sb.n)
		{
			if((smat[ta][0]==sb.smat[tb][0] && smat[ta][1]<sb.smat[tb][1]) || smat[ta][0]<sb.smat[tb][0])
			{
				insert(smat[ta][0],smat[ta][1],smat[ta][2]);
				ta++;
			}
			else if((smat[ta][0]==sb.smat[tb][0] && smat[ta][1]>sb.smat[tb][1]) || smat[ta][0]>sb.smat[tb][0])
			{
				insert(sb.smat[tb][0],sb.smat[tb][1],sb.smat[tb][2]);
				tb++;
			}
			else if((smat[ta][0]==sb.smat[tb][0] && smat[ta][1]==sb.smat[tb][1]))
			{
				insert(smat[ta][0],smat[ta][1],smat[ta][2]-sb.smat[tb][2]);
				ta++; tb++;
			}
		}

		//for remaining elements in any matrix
		if(ta<n)
		{
			while(ta<=n) 
			{
				insert(smat[ta][0],smat[ta][1],smat[ta][2]);
				ta++;
			}
		}

		if(tb<sb.n)
		{
			while(tb<=sb.n) 
			{
				insert(sb.smat[tb][0],sb.smat[tb][1],sb.smat[tb][2]);
				tb++;
			}
		}
		showSparse(tres-1,res);	
	}
}

void sparseMatrix::mulSparse(sparseMatrix sb)
{
	cout<<"\nOn Multiplying Sparse Matrices\n";
	if(col!=sb.row) cout<<"\nCan't multiply!\nEntered Matrices are not in correct order!";
	else
	{
		tres=0;
		for(int i=0; i<n; i++)
			for (int j=0; j<sb.n; j++)
				if(smat[i][1]==sb.smat[j][0])
					insert(smat[i][0],sb.smat[j][1],smat[i][2]*sb.smat[j][2]);

		for(int i=0; i<tres; i++)
		{
			for(int j=i+1; j<tres; j++)
			{
				if((res[i][0]==res[j][0]) && (res[i][1]==res[j][1]))
				{
					res[i][2]+=res[j][2];
					for(int k=j; k<tres; k++)
					{
						res[k][0]=res[k+1][0];
						res[k][1]=res[k+1][1];
						res[k][2]=res[k+1][2];
					}
					tres--;
				}
			}
		}
		showSparse(tres,res);	
	}
}

int main()
{
	cout<<"\n----Plain Matrix----";
	cout<<"\nMatrix 1 : ";
	Matrix a;
	cout<<"\nMatrix 2 : ";
	Matrix b;
	cout<<"\nMatrix 1 :\n";
	a.showMatrix();
	cout<<"\nMatrix 2 :\n";
	b.showMatrix();
	a.add2D(b);
	a.sub2D(b);
	a.mul2D(b);

	cout<<"\n----Sparse Matrix----";
	int check=1;
	cout<<"\nSparse Matrix 1 : ";
	sparseMatrix sa;
	check=sa.validateSparse();
	if(!check) 
	{
		cout<<"\nInvalid input!\nEntered elements exceed the range of the matrix!\n";
		exit(0);
	}
	cout<<"\nSparse Matrix 2 : ";
	sparseMatrix sb;
	check=sb.validateSparse();
	if(!check) 
	{
		cout<<"\nInvalid input!\nEntered elements exceed the range of the matrix!\n";
		exit(0);
	}
	cout<<"\nSparse Matrix 1 :\n";
	sa.showSparse();
	cout<<"\nSparse Matrix 2 :\n";
	sb.showSparse();
	sa.addSparse(sb);
	sa.subSparse(sb);
	sa.mulSparse(sb);
	return 0;
}
