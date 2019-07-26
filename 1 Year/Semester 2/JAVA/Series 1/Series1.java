import java.util.Scanner;
class Series1{

public static void main(String args[]){
Scanner in = new Scanner(System.in);
int n,i;
System.out.print("Enter the value of n: ");
n = in.nextInt();
float sum=0;
for(i=1;i<=n;i++)
{
sum = sum + (float)1/i;
}
System.out.print(" Sum upto " + n + " terms is " + sum);
}
}