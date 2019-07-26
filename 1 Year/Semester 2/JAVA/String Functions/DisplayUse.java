import java.util.Scanner;
class StringFunctions{
private String input;
public StringFunctions(){
input = "ROHIT SHARMA";
}

public void setCh()
{
StringBuffer sb = new StringBuffer(input);
System.out.println("Original String: " + sb);
sb.setCharAt(2, 'N');
sb.setLength(5);
System.out.println("String after Setting length and character: " + sb);
}
public void appendString()
{
String s;
int a = 42;
StringBuffer sb = new StringBuffer(40);
s = sb.append("a = ").append(a).append("!").toString();
System.out.println("APPENDING STRING AND INTEGER "  + s);
}
public void insertString()
{
StringBuffer sb = new StringBuffer(input);

System.out.println("String before insert(): "  + sb);
sb.insert(12, " is ");
System.out.println("String after insert(): ");
System.out.println(sb);
}
public void concatString()
{
System.out.println("CONCATENATION WITH STRING");
StringBuffer sb = new StringBuffer(input);
String s2  = input.concat(" is 18 isn't he?");
System.out.println(s2);

}
public void equalsDemo()
{
StringBuffer sb = new StringBuffer(input);

String s = "ROHIT SHARMA";
if(s.equals(input))
{
System.out.println(s + " and " + input + "are equal");
}

}
}
class DisplayUse{
public static void main(String args[])
{
StringFunctions ob = new StringFunctions();
ob.setCh();
ob.appendString();
ob.insertString();
ob.concatString();
ob.equalsDemo();
}

}