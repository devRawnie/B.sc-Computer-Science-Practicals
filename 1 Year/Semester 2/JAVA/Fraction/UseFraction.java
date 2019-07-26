import java.util.Scanner;
class Fraction{
Scanner in = new Scanner(System.in);
int num, den;
Fraction()
{
num = 0;
den = 1;
}
Fraction(int n, int d)
{
num = n;
den = d;
}
void enter()
{
System.out.print("Enter the numerator: ");
num = in.nextInt();
System.out.println();
System.out.print("Enter the denominator: ");
den = in.nextInt();
if(den==0)
	{
	System.out.print("The Denominator can not be zero. Enter again");
	enter();
}
display();
}
void display()
{
if(num==0)
{
System.out.println("0"); 
}
else if(den==1)
{System.out.println(num);}
else if((num%den)==0)
{System.out.println((num/den) + "/q");}
else{
System.out.println(num + " / " + den); 
}
}
int lcm(int a,int b)
{

int m,n;
m=a;
n=b;
while(m!=n)
{
if(m<n)
{m=m+a;}
else
{
n=n+b;
}

}
return m;
}
Fraction add(Fraction ob)
{
Fraction tmp = new Fraction();
if(den==ob.den)
{
tmp.num = num + ob.num;
tmp.den = den;
return tmp;
}
else
{
tmp.den= lcm(den, ob.den);
tmp.num = (((num)*(tmp.den/den)) + ((ob.num)*(tmp.den/ob.den)));
return tmp;
}
}
Fraction subtract(Fraction ob)
{
Fraction tmp = new Fraction();
if(den==ob.den)
{
tmp.num = num - ob.num;
tmp.den = den;
return tmp;
}

else
{
tmp.den= lcm(den, ob.den);
tmp.num = (((num)*(tmp.den/den)) - ((ob.num)*(tmp.den/ob.den)));
return tmp;
}
}


}
class UseFraction{

public static void main(String args[])
{
Scanner in = new Scanner(System.in);

Fraction ob1 = new Fraction();
ob1.enter();
Fraction ob2 = new Fraction();
ob2.enter();
Fraction temp = new Fraction();
int ch;
System.out.println("Choose from the following: ");
System.out.println("1.Add ");
System.out.println("2.Subtract ");
ch = in.nextInt();
switch(ch)
{
case 1: temp = ob1.add(ob2);
	temp.display();
	break;
case 2: temp = ob1.subtract(ob2);
	temp.display();
	break;
default: System.out.println("Wrong choice!!");
}


}
}