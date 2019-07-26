package M.Fib;
public class FibSeries{
public int Fib(int x){
if(x==1||x==0)
	return x;
else
	return (Fib(x-1)+Fib(x-2));

}
}