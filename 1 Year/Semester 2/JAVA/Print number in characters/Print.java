import java.io.IOException;
class Print{

public static void main(String args[])
{
int a;
try{
System.out.print("Enter a no: ");
a = System.in.read();
switch(a-48)
{
case 0: System.out.println("ZERO");
	break;
case 1: System.out.println("ONE");
	break;
case 2: System.out.println("TWO");
	break;
case 3: System.out.println("THREE");
	break;
case 4: System.out.println("FOUR");
	break;
case 5: System.out.println("FIVE");
	break;
case 6: System.out.println("SIX");
	break;
case 7: System.out.println("SEVEN");
	break;
case 8: System.out.println("EIGHT");
	break;
case 9: System.out.println("NINE");
	break;


}
}
catch(IOException e){
System.out.println("Error caught: " + e);
}
}


}