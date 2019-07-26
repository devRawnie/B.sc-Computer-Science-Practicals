import java.io.*;
class printFile
{
public static void main(String args[]) throws IOException
{

int a;
FileInputStream fin;

try{
fin = new FileInputStream(args[0]);
}catch(FileNotFoundException e)
{
System.out.println("File not found");
return;
}
catch(ArrayIndexOutOfBoundsException e)
{
System.out.println("ShowFile");

return;}

do{
a = fin.read();
if(a!=-1)
	System.out.print((char) a);
}while(a != -1);
fin.close();
}
}


