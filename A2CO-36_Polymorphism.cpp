/*

Write a C++ program to demonstrate polymorphism by using virtual function. Create a base class shape which is inherited by the class circle, class rectangle, class square and class triangle. 
Calculate area and perimeter in the derived class. Include appropriate virtual function in the base class shape. 
Also include appropriate constructor and data members in the class.

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;

class Shape
{
protected:
	float area, perimeter;
public:
	Shape()
	{
		area = 0.0;
		perimeter = 0.0;
	}

   	void display()
    {
    	cout<<"\nArea : "<<area<<" sq. units\nPerimeter : "<<perimeter<<" units"<<endl;
    }

    virtual void calcArea(){}
    virtual void calcPerimeter(){}
};

class Circle : public Shape
{
protected:
	float r;
public:
	Circle()
	{
		cout<<"\nEnter the radius of the Circle : ";
		cin>>r;
	}

	void calcArea()
	{
		area = PI * r * r;
	}

	void calcPerimeter()
	{
		perimeter = 2 * PI * r;
	}
};

class Rectangle : public Shape
{
protected:
	float l, b;
public:
	Rectangle()
	{
		cout<<"\nEnter the length and breadth of the Rectangle : "; 
    	cin>>l>>b;
	}

	void calcArea()
	{
		area = l * b;
	}

	void calcPerimeter()
	{
		perimeter = 2 * (l + b);
	}
};

class Square : public Shape
{
protected:
	float s;
public:
	Square()
	{
		cout<<"\nEnter the side of the Square : "; 
    	cin>>s;
	}

	void calcArea()
	{
		area = s * s;
	}

	void calcPerimeter()
	{
		perimeter = 4 * s;
	}
};

class Triangle : public Shape
{
protected:
	float a, b, c, s;
public:
	Triangle()
	{
		cout<<"\nEnter the sides of the Triangle\nA : "; cin>>a;
		cout<<"B : "; cin>>b;
		cout<<"C : "; cin>>c;
	}

	void calcArea()
	{
		if(a+b>c && b+c>a && c+a>b)
		{
			s = (a+b+c)/2;
			area = sqrt(s*(s-a)*(s-b)*(s-c));
		}
		else
			printf("\nTriangle can't be formed with the given sides!!\n");
	}

	void calcPerimeter()
	{
		if(a+b>c && b+c>a && c+a>b)
			perimeter = a + b + c;
	}
};

int main()
{
	Shape *shape[5];
	int ch;
	
	cout<<"\n1. Circle\n2. Rectangle\n3. Square\n4. Triangle\nYour choice? ";
	cin>>ch;
	
	if(ch == 1)  
	{
    		cout<<"\n---Circle---";
    		Circle C;
    		shape[ch] = &C;
    	}
    	else if(ch == 2)
    	{
   		cout<<"\n---Rectangle---";
   		Rectangle R;
   		shape[ch] = &R;
   	}
   	else if(ch == 3)
   	{
   		cout<<"\n---Square---";
   		Square S;
   		shape[ch] = &S;
   	}
   	else if(ch == 4)
   	{
   		cout<<"\n---Triangle---";
   		Triangle T;
   		shape[ch] = &T;
  	}
	else 
		cout<<"\nInvalid choice!\n";
	
	shape[ch]->calcArea();
	shape[ch]->calcPerimeter();
	shape[ch]->display();

    cout<<endl;
    return 0;
}
