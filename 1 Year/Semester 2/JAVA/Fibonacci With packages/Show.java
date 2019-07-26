import M.PrintFib.FibonacciSeries;
import java.util.Scanner;
class Show{
public static void main(String args[])

{
int terms;
Scanner in = new Scanner(System.in);
System.out.print("Enter the number of terms of fibonacci series: ");
terms = in.nextInt();
FibonacciSeries fb = new FibonacciSeries(terms);
fb.PrintSeries();
}
}