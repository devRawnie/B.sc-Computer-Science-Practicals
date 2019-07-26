import java.util.Scanner;
class Armstrong{

public static void main(String args[])
{
Scanner in = new Scanner(System.in);
int no,t,d, pos;
double sum =0;
System.out.println("Enter a no: ");
no = in.nextInt();
sum =0;
pos = findpos(no);
t = no;
while(t>0)
{
d = t%10;
sum = sum + Math.pow(d,pos);
t = t/10;
}
if(sum==no)
{
System.out.println(no+ " is an Armstrong's no." );
}
else
{
System.out.print(no + " is not an Armstrong's no.");	
}



}

public static int findpos(int n)
{
int temp=n,d=0;
	while(temp>0)
{
temp = temp/10;
d++;
}
return d;
}




}