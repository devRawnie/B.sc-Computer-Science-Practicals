package M.PrintFib;
import M.Fib.FibSeries;
public class FibonacciSeries extends FibSeries{
private int n;
public FibonacciSeries(int a)
{n=a;}
public void PrintSeries(){
int i;
for(i=0;i<n;i++)
{
System.out.print(Fib(i) + " ");
}

}


}