import java.util.*;
/**
 * 
 */


class Babylonian
{
public static void main(String args[])
{
Scanner input= new Scanner(System.in);
System.out.println("Enter an integer n");
int n = input.nextInt();
System.out.println("Square root of entered number is "+squareRootOfNumber(n));

}

public static float squareRootOfNumber(float n)
{
double c = 0.000001;
float a = n;
float b = 1;
  
while(a-b > c){
	a = (a + b)/2;
   System.out.println("Next Approximationalue value of a "+a);
  	b = n/a;
   System.out.println("New guess value is "+b);
}
return a;
}
}