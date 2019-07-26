abstract class Figure{

double dim1;
double dim2;

Figure(double a, double b)
{
dim1 = a;
dim2 = b;
}

abstract double area();

}

class Rectangle extends Figure{

Rectangle(double a, double b)
{
super(a,b);
}
double area()
{
return dim1*dim2;
}

}
class Triangle extends Figure{

Triangle(double a, double b)
{
super(a,b);
}
double area()
{
return ((double)(dim1*dim2)/2);
}
}
class Abstract{

public static void main(String args[])
{
Rectangle r = new Rectangle(8,10);
Triangle t = new Triangle(3,4);
System.out.println("Area of Rectangle is " + r.area());
System.out.println("Area of Triangle is " + t.area() ); 

}

}