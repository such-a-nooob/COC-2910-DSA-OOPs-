/*

Write a C++ program to demonstrate polymorphism by using virtual function. Create a base class shape which is inherited by the class circle, class rectangle, class square and class triangle. 
Calculate area and perimeter in the derived class. Include appropriate virtual function in the base class shape. 
Also include appropriate constructor and data members in the class.

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

#include <iostream>
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
	float a, b, c, h;
public:
	Triangle()
	{
		cout<<"\nEnter the sides of the Triangle\nA : "; cin>>a;
		cout<<"B : "; cin>>b;
		cout<<"C : "; cin>>c;
		cout<<"Enter the height of the Triangle : "; cin>>h;    	
	}

	void calcArea()
	{
		area = 0.5 * b * h;
	}

	void calcPerimeter()
	{
		perimeter = a + b + c;
	}
};

int main()
{
	Shape *shape[4];

    for(int i=0; i<4; i++)
    {
    	if(i == 0) 
    	{
    		cout<<"\n---Circle---";
    		Circle C;
    		shape[i] = &C;
    	}
    	else if(i == 1)
    	{
   			cout<<"\n---Rectangle---";
   			Rectangle R;
   			shape[i] = &R;
   		}
   		else if(i == 2)
   		{
   			cout<<"\n---Square---";
   			Square S;
   			shape[i] = &S;
   		}
   		else
   		{
   			cout<<"\n---Triangle---";
   			Triangle T;
   			shape[i] = &T;
  		}

    	shape[i]->calcArea();
	    shape[i]->calcPerimeter();
	    shape[i]->display();
	}

    cout<<endl;
    return 0;
}
