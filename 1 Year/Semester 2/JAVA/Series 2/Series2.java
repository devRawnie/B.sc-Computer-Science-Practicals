import java.util.Scanner;
class Series2{

public static void main(String args[]){

Scanner in = new Scanner(System.in);
int n,i;
System.out.print("Enter the value of n: ");
n = in.nextInt();
float sum=0;
for(i=1;i<=n;i++)
{
sum = sum + (float)Math.pow(i,2);
}
System.out.print("Sum upto " + n+ " terms is " + sum);
}
}