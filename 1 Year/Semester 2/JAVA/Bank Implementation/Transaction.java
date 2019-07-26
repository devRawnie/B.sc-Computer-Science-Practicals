import java.util.Scanner;
class InsufficientBalance extends Exception{
private float lowBal;
InsufficientBalance(float lb)
{lowBal = lb;}
public String toString()
{
return "Insufficient Balance in your account. " + lowBal + "$ less.";
}

}
class Bank{
Scanner in = new Scanner(System.in);
private String name;
private int acno;
private float balance;
static int members;
public Bank()
{
balance = 0;
members++;
}

public Bank(String s,int n, float b)
{
name = s;
acno = n;
balance = b;
members++;
}
public void menu()
{
int ch;

System.out.println("CHOOSE OUT OF THE FOLLOWING");
System.out.println("1.CURRENT STATEMENT");
System.out.println("2.WITHDRAW MONEY");
System.out.println("3.ADD MONEY");
System.out.println("4. QUIT");
ch = in.nextInt();
switch(ch)
{
case 1:	display();
	break;
case 2: try{withdraw();}catch(InsufficientBalance e){
		System.out.println(e);
		menu();
		}
	break;
case 3: add();
	break;
case 4: 
	break;
default: System.out.println("Wrong Choice!!");
}
}
public void enter()
{
System.out.print("ENTER YOUR NAME: ");
name = in.nextLine();
System.out.print("ENTER YOUR A/C NO: ");
acno = in.nextInt();
}
public void display()
{
System.out.print(" Hi!! " + name);
System.out.println("     A/C NO:     " + acno);
System.out.println(" AVAILABLE BALANCE " + balance + "$");
menu();
}
public void withdraw() throws InsufficientBalance
{
float amt;
System.out.println(" AVAILABLE BALANCE: "+balance + "$");
System.out.print(" Enter the amount to withdraw: ");
amt = in.nextFloat();
if(amt>balance)
	throw new InsufficientBalance(amt-balance);
balance -= amt;
display();
}
public void add()
{
float amt;
System.out.println("AVAILABLE BALANCE: "+balance + "$");
System.out.print("Enter the amount to add: ");
amt = in.nextFloat();
balance += amt;
display();
}
public String toString()
{return ("********************************************  WELCOME TO YOUR DIGITAL BANK  ********************************************");
}
}
class Transaction{
public static void main(String args[])
{
Bank ob = new Bank();
System.out.println(ob);
ob.enter();
ob.display();
}
}