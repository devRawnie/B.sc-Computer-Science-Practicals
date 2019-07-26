class Box{
int length;
int breadth;
int height;
Box(int l, int b, int h)
{
length = l;
breadth = b;
height = h;
} 
public float volume(){
float vol = 1;
vol = length*breadth*height;
return vol;
}
public void showbox(){
System.out.println("Length: " + length);
System.out.println("Breadth: " + breadth);
System.out.println("Height: " + height);

}

}
class UseBox{
public static void main(String args[])
{
Box ob1 = new Box(3,4,5);
ob1.showbox();
float v = ob1.volume();
System.out.print("Volume of Box is: " + v);
}
}