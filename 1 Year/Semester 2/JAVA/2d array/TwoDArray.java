class TwoDArray{

public static void main(String args[])
{

int A[][] = new int[3][4];
int row = 3, col =4,i,j;
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
A[i][j]=i*j;

}
}

for(i=0;i<row;i++)
{for(j=0;j<col;j++)
{
System.out.print(A[i][j] + " ");
}
System.out.println();
}

}
}