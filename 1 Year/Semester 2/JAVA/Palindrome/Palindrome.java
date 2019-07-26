import java.util.Scanner;
class Palindrome{

public static void main(String args[])
{

Scanner in = new Scanner(System.in);
int org , no,rno=0,digit ;
System.out.println("Enter a no: ");
org = in.nextInt();
no = org;
while(no>0)
{
digit = no%10;
rno = rno*10 + digit;
no = no/10;	
}

if(rno==org)
{
System.out.print(org + " is a palindrome.");
}
else
{
System.out.print(org + " is not a palindrome.");

}
}




}