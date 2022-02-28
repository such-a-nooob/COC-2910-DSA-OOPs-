/*

b. Write a program in Java to create an abstract class named Shape that contains an empty method named numberOfSides(). 
   Provide three classes named Trapezoid, Triangle and Hexagon such that each one of the classes extends the class Shape. 
   Each one of the class contains  the method numberOfSides() that shows the number of sides in the given geometrical figures. 
   Using the sides, find the perimeter of geometric figures.

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

import java.util.*;
import java.text.DecimalFormat;

abstract class Shape
{
	public abstract void numberOfSides();
}

class Trapezoid extends Shape
{
	double a, b, c, d;
	private static final DecimalFormat df = new DecimalFormat("0.00");

	Trapezoid()
	{
		System.out.println("\n-------TRAPEZOID-------");
	}

	public void numberOfSides()
	{
		System.out.println("Number of sides in Trapezoid : 4");
	}

	public void findPeri()
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the sides : ");
		a = sc.nextDouble();
		b = sc.nextDouble();
		c = sc.nextDouble();
		d = sc.nextDouble();
		System.out.println("\nPerimeter of Trapezoid : "+df.format(a+b+c+d)+" units");
	}
}

class Triangle extends Shape
{
	double a, b, c;
	private static final DecimalFormat df = new DecimalFormat("0.00");

	Triangle()
	{
		System.out.println("\n-------TRIANGLE-------");
	}

	public void numberOfSides()
	{
		System.out.println("Number of sides in Triangle : 3");
	}

	public void findPeri()
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the sides : ");
		a = sc.nextDouble();
		b = sc.nextDouble();
		c = sc.nextDouble();
		System.out.println("\nPerimeter of Triangle : "+df.format(a+b+c)+" units");
	}
}

class Hexagon extends Shape
{
	int a;
	private static final DecimalFormat df = new DecimalFormat("0.00");

	Hexagon()
	{
		System.out.println("\n-------HEXAGON-------");
	}

	public void numberOfSides()
	{
		System.out.println("Number of sides in Hexagon : 6");
	}

	public void findPeri()
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the side (for a regular Hexagon) : ");
		a = sc.nextInt();
		System.out.println("\nPerimeter of a regular Hexagon : "+df.format(6*a)+" units");
	}
}

public class partB
{
	public static void main(String[] args) 
	{
		System.out.println("\nPART (B) :");

		Trapezoid trap = new Trapezoid();
		trap.numberOfSides();
		trap.findPeri();		

		Triangle tri = new Triangle();
		tri.numberOfSides();
		tri.findPeri();

		Hexagon hex = new Hexagon();
		hex.numberOfSides();
		hex.findPeri();
	}
}