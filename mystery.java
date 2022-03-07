package Recursion;

//This code gives the user a mystery number based off several different functions

public class mystery
{
	public static void main(String args[])
	{
		mystery6(6, 13);
	}

	public static void mystery1(int n) 
	{
	    if (n <= 1) 
	    {
	        System.out.print(n);
	    } 
	    else 
	    {
	        mystery1(n / 2);
	        System.out.print(", " + n);
	    }
	}
	
	public static void mystery2(int n) 
	{
	    if (n > 100) 
	    {
	        System.out.print(n);
	    } else 
	    {
	        mystery2(2 * n);
	        System.out.print(", " + n);
	    }
	}
	
	public static void mystery3(int n) 
	{
	    if (n <= 0) {
	        System.out.print("*");
	    } else if (n % 2 == 0) 
	    {
	        System.out.print("(");
	        mystery3(n - 1);
	        System.out.print(")");
	    } else 
	    {
	        System.out.print("[");
	        mystery3(n - 1);
	        System.out.print("]");
	    }
	}
	
	public static void mysteryXY(int x, int y) 
	{
	    if (y == 1) 
	    {
	        System.out.print(x);
	    } else 
	    {
	        System.out.print(x * y + ", ");
	        mysteryXY(x, y - 1);
	        System.out.print(", " + x * y);
	    }
	}
	
	public static int mystery6(int x, int y)
	{
		if(x<y)
		{
			return x;
		}
		else
		{
			return mystery6(x-y, y);
		}
	}
}