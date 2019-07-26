import java.io.*;
class copyFile
{
public static void main(String args[]) throws IOException
{

int a;
FileInputStream fin;
FileOutputStream fout;
try{
try{
fin = new FileInputStream(args[0]);
}catch(FileNotFoundException e)
{
System.out.println("File not found");
return;
}
try{
fout = new FileOutputStream(args[1]);
}catch(FileNotFoundException e)
{
System.out.println("File not found");
return;
}

}catch(ArrayIndexOutOfBoundsException e)
{
System.out.println("ShowFile");

return;}
try{
do{
a = fin.read();
if(a!=-1)
fout.write(a);
}while(a != -1);
}catch(IOException e)
{
System.out.println("File Error");
}
fin.close();
fout.close();
}
}


