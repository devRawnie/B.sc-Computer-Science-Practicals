package TakeMessage;
import java.util.Scanner;
public class ReadText{
Scanner in = new Scanner(System.in);
private String str;
public String getString()
{
System.out.println("Enter some text");
str = in.nextLine();
return str;
}
}
