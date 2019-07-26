import java.util.Scanner;
class Factorial{
int no, fact;
Scanner in = new Scanner(System.in);
int findFac(int n)
{
if(n==1)
return 1;
else
return  n*findFac(n-1);
}
void calc()
{
System.out.print("Enter a no to find its factorial: ");
no = in.nextInt();
fact = findFac(no);
System.out.println();
System.out.println("The factorial of  " + no + " is: " + fact);

}

}
class UseFactorial{
public static void main(String args[])
{
Factorial ob = new Factorial();
ob.calc();
}

}