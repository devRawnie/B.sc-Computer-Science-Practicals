class Variable{

private static int sum ;
private static int arg;
static void calculate(int ... x)
{ 
arg = 0;
sum = 0;
for(int a: x)
{
arg++;
sum += a;
}
System.out.println("Sum of " + arg + " arguments is  " + sum);
}

}
class UseVariable{
public static void main(String args[])
{
Variable v1 = new Variable();
v1.calculate(1,2,3,4,5);
v1.calculate(2,4,6,8,12,14,16,18);
v1.calculate(1,3,5);

}
}