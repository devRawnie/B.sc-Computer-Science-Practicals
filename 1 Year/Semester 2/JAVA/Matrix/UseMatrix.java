import java.util.Scanner;
class Matrix{
Scanner in = new Scanner(System.in);

int row;
int col;
int[][] M;
Matrix(int a, int b)
{
row=a;
col=b;
M = new int[row][col];
}


void enter()
{
int i,j;
System.out.println("Enter the elements of the matrix: ");
for(i=0;i<row;i++)
{
for( j=0;j<col;j++)
{

System.out.print("M[" + (i+1) +"][" + (j+1) + "]: ");
M[i][j] = in.nextInt();
 
}
}

display();	
}

void display()
{

int i,j;
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
System.out.print(M[i][j]);
System.out.print(" ");
}
System.out.println();
}

}
void add(Matrix ob1,Matrix ob2)
{

int i,j;
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{

M[i][j] = ob1.M[i][j] + ob2.M[i][j];

}
}
display();
}
void product(Matrix ob1,Matrix ob2)
{

int i,j;

for(i=0;i<ob1.row;i++)
{
for(j=0;j<ob2.col;j++)
{

M[i][j] = ob1.M[i][j]*ob2.M[j][i];

}
}
display();
}


}

class UseMatrix{

public static void main(String args[])
{
Scanner in = new Scanner(System.in);
int r1,c1,r2,c2,ch;
System.out.print("Enter row of matrix 1: ");
r1 = in.nextInt();
System.out.print("Enter column of matrix 1: ");
c1 = in.nextInt();
Matrix Mob1 = new Matrix(r1,c1);
Mob1.enter();
System.out.print("Enter row of matrix 2: ");
r2 = in.nextInt();
System.out.print("Enter column of matrix 2:");
c2 = in.nextInt();
Matrix Mob2 = new Matrix(r2,c2);
Mob2.enter();
System.out.println("Choose from the following: ");
System.out.println("1.Sum of two matrices ");
System.out.println("2.Product of two matrices ");
ch = in.nextInt();
switch(ch)
{
case 1: if(r1==r2 && c1==c2)
	{
	
	Matrix Mob = new Matrix(r1,c1);
	Mob.add(Mob1,Mob2);
	}
	else
		System.out.print("The two matrices are not compatible");
	break;
case 2: if(c1==r2)
	{
	Matrix Mob = new Matrix(r1,c2);
	Mob.product(Mob1,Mob2);
	}
	else
		System.out.print("The two matrices are not compatible");
	break;
default: System.out.print("The Matrices are not compatible ");
}

}

}