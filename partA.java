/*

a. Write a program in Java that explains the concept of method overloading by finding the area and perimeter for different polygons. 
   The argument lists of methods must differ in Number of parameters, Data type of parameters and Sequence of Data type of parameters. 
   The program must throw an exception if the length of sides of the polygon are invalid i.e. -2, -3

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

import java.util.*;
import java.text.DecimalFormat;

class AreaPeri
{
	public double calcArea(double s)	//Square
	{
		return (s*s);
	}

	public double calcArea(int a)	//Hexagon
	{
		return (1.5*Math.sqrt(3)*a*a);
	}

	public double calcArea(int l, int b)	//Rectangle
	{
		return (l*b);
	}

	public double calcArea(int a, int b, int c)	//Triangle
	{
		if(a+b>c && b+c>a && c+a>b)
		{
			double s = (a+b+c)/2;
			return (Math.sqrt(s*(s-a)*(s-b)*(s-c)));
		}
		return 0;
	}

	public double calcPeri(double s)	//Square or Rhombus
	{
		return (4*s);
	}

	public double calcPeri(int a)	//Hexagon
	{
		return (6*a);
	}

	public double calcPeri(double l, double b)	//Rectangle
	{
		return (2*(l+b));
	}

	public double calcPeri(double a, double b, double c)	//Triangle
	{
		if(a+b>c && b+c>a && c+a>b)
			return (a+b+c);
		return 0;
	}
}

public class partA
{
	private static final DecimalFormat df = new DecimalFormat("0.00");
	public static void main(String[] args) 
	{
		try{
		System.out.println("\nPART (A) :");
		Scanner sc = new Scanner (System.in);
		AreaPeri ap = new AreaPeri();
		int ch;
		do
		{
			System.out.println("\nSELECT A SHAPE :\n  1. Triangle\n  2. Square\n  3. Rectangle\n  4. Hexagon\nEXIT (Press 0)\n");
			System.out.print("Your choice : ");
			ch = sc.nextInt();
			
			if(ch==0)	//Exit
				break;

			if(ch==1)	//Triangle
			{
				System.out.print("\nEnter the sides of the Triangle : ");
				int a = sc.nextInt();
				int b = sc.nextInt();
				int c = sc.nextInt();

				if(a<=0 || b<=0 || c<=0) 
					throw new ArithmeticException(); 

				if(ap.calcArea(a,b,c)!=0)
				{
					System.out.println("Area : "+df.format(ap.calcArea(a,b,c))+" units");
					System.out.println("Perimeter : "+df.format(ap.calcPeri(a,b,c))+" units");
				}
				else
					System.out.println("This Triangle doesn't exist!"); 
			}
			else if(ch==2)	//Square
			{
				System.out.print("\nEnter the side of the Square : ");
				double a = sc.nextDouble();

				if(a<=0) 
					throw new ArithmeticException();
				
				System.out.println("Area : "+df.format(ap.calcArea(a))+" units");
				System.out.println("Perimeter : "+df.format(ap.calcPeri(a))+" units");
			}	
			else if(ch==3)	//Rectangle
			{
				System.out.print("\nEnter the length and breadth of the Rectangle : ");
				int a = sc.nextInt();
				int b = sc.nextInt();

				if(a<=0 || b<=0) 
					throw new ArithmeticException();
				
				System.out.println("Area : "+df.format(ap.calcArea(a,b))+" units");
				System.out.println("Perimeter : "+df.format(ap.calcPeri(a,b))+" units");
			}
			else if(ch==4)	//Hexagon
			{
				System.out.print("\nEnter the side of the regular Hexagon : ");
				int a = sc.nextInt();

				if(a<=0) 
					throw new ArithmeticException();
				
				System.out.println("Area : "+df.format(ap.calcArea(a))+" units");
				System.out.println("Perimeter : "+df.format(ap.calcPeri(a))+" units");
			}
			else
				System.out.println("\nInvalid Choice!"); 

		}while(ch!=0);
		}
		catch(ArithmeticException e)
		{
			System.out.println("SIDES OF THE POLYGON SHOULD BE GREATER THAN 0!!");
		}
	}
}