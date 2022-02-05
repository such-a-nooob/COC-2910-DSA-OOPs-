/*

Write a C++ program to demonstrate multiple inheritance by creating a class cuboid which extends class rectangle, class shape. 
It calculates area and volume. Use appropriate constructors and member variables.

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

#include <iostream>
using namespace std;

class Shape
{
protected:
	float area, volume;
public:
    Shape()
    {
    	area = volume = 0.0;
    }

    void display()
    {
    	cout<<"\nArea : "<<area<<"\nVolume : "<<volume<<endl;
    }
};

class Rectangle
{
protected:
	float l, b;
public:
	Rectangle()
	{
		cout<<"\nEnter the length and breadth : "; 
    	cin>>l>>b;
	}

	float calcArea()
	{
		return (l*b);
	}
};

class Cuboid :public Shape, public Rectangle
{
protected:
	float h;
public:
	Cuboid()
	{
		cout<<"Enter the height : "; 
    	cin>>h;
	}

	void calcArea()
	{
		area = 2*((l*b) + (b*h) + (l*h));
	}

	void calcVolume()
	{
		volume = Rectangle::calcArea() * h;
		//volume = l * b * h;
	}
	
};

int main()
{

	cout<<"\n---Rectangle---";
    Rectangle R;
    cout<<"\nArea : "<<R.calcArea()<<endl;

	cout<<"\n---Cuboid---";
    Cuboid C;
    C.calcArea();
    C.calcVolume();
    C.display();

    cout<<endl;
    return 0;
}
