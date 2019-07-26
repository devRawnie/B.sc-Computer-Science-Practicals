class NestedTry{

public static void main(String args[])
{
int var = 20,i;
int ar[] = {1,2};
try{
try{

System.out.println("Dividing " + var + " by zero");
var = var/(var-var);
}catch(ArithmeticException e){
System.out.println("Inside inner catch, Caught Exception: " + e);}
try{
System.out.println("Printing array inside inner try");
for(i=0;i<5;i++)
	{System.out.println(ar[i]);}
}catch(ArithmeticException e)
{
System.out.println("Inside inner catch, caught Exception: " + e);
}}
catch(ArrayIndexOutOfBoundsException e){
System.out.println("Inside Outer catch, Caught Exception: " + e);
}

}
}