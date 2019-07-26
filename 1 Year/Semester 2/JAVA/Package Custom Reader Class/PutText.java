package PutMessage;
import TakeMessage.ReadText;
public class PutText{
public void putString(){
ReadText tempOb = new ReadText();
String text = tempOb.getString();
System.out.println("You Entered: " + text);

}
}