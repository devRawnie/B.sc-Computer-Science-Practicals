import java.util.Scanner;
class Prime{

public static void main(String args[])
{
Scanner in = new Scanner(System.in);
int no,i,flag = 0;
System.out.println("Enter a no: ");
no = in.nextInt();
for(i=2;i<no/2;i++)
{
if(no%i==0)
{
flag = 1;
System.out.print(no + " is not prime.");
break;
}

}

if(flag!=1)
{
System.out.print(no + " is prime.");

}
}


}