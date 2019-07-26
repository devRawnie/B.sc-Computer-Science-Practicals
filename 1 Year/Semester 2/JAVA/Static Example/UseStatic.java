class StaticDemo{

static int a = 3;
static int b;
static void meth()
{
System.out.println("Before main A: " + a);
System.out.println("Before main B: " + b);
System.out.println("Before Main()");
b = a*4;
System.out.println("Iniitialized b before main itself. ");

}
static{
System.out.println("Before main B: " + b);
meth();
}




public static void main(String args[])
{
StaticDemo.meth();
System.out.println("Inside Main");
System.out.println("Calling static Method from main");




}

}