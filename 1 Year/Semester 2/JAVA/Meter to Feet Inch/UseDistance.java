import java.util.Scanner;
class Distance{
Scanner in = new Scanner(System.in);
private int feet , inch;
private float meter;
public Distance(int a , int b)
{
feet = a;
inch = b;
}
public void getDistance()
{
System.out.println("Enter the distance in meter");
meter = in.nextFloat();
}
public int getFeet()
{

 
return ((int)(meter/3.28));

}
public int getInch()
{
return ((int)(feet/12));
}
public void calculate()
{
feet = getFeet();
inch = getInch();
System.out.println(meter + " meter= " + feet + " feet " + inch + " inch");
}
}
class UseDistance{

public static void main(String args[])
{
Distance d = new Distance(0,0);
d.getDistance();
d.calculate();
}
}