import java.util.Scanner;
class SumAv{

public static void main(String args[])
{

Scanner in = new Scanner(System.in);
int no,i,sum=0;
System.out.println("Enter a no upto which you want to find the Average: ");
no = in.nextInt();
for(i=1;i<=no;i++)
{

sum = sum + i;
}
System.out.println("The sum of " + no + " Natural no's is " +sum);
System.out.println("The average of " + no + " Natural no's is " + (sum/no));

}


}