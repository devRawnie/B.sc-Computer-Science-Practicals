import java.util.Scanner;
class Palindrome{
Scanner in = new Scanner(System.in);
private String str;
void input()
{
System.out.println("Enter a string ");
str = in.nextLine();
}
String reverseString(){
int i = str.length(),j=0;
char[] revC = str.toCharArray();
char[] temp = new char[i];
while(i>0)
{
i--;
temp[j] = revC[i];
j++;
}
String rev = new String(temp);
return rev;
}
void check()
{
if(str.equals(reverseString()))
	{
System.out.println("The entered string is a Palindrome");

	}
else
	{
System.out.println("The entered string is not a Palindrome");

}
}

}
class CheckPalindrome{
public static void main(String args[])
{

Palindrome p = new Palindrome();
p.input();
p.check();


}

}