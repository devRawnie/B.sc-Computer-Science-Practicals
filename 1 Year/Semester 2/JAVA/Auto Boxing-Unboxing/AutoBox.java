class AutoBox{

public static void main(String args[])
{
Integer iob,iob2;
int i;
iob = 100;
System.out.println("Value of Integer object: " + iob);
++iob; //Auto Unboxing and Auto boxing
System.out.println("After ++iob (Auto Unboxing and Auto Boxing) value of iob: " + iob);
iob2 = iob + (iob/4);
System.out.println("value of object after expression evaluation: " + iob2);

}

}