#include<iostream>
//#include<conio.h>
using namespace std;
class Path{
			
public: 

int size,len,i,j,ch,Vbeg,Vend;
char beg, end;
int **M,**temp,**product;
Path(int a)
{
	ch = 97;
	size = a;
	M = new int*[size];
	temp = new int*[size];
	product = new int*[size];
	for(i=0;i<size;i++)
		{
			M[i] = new int[size];
			temp[i] = new int[size];
			product[i] = new int[size];
		}
	for(i=0;i<size;i++)
{
				for(j=0;j<size;j++)
				{
						M[i][j] = 0;
						temp[i][j] = 0;
						product[i][j] = 0;
						}
}
}

~Path()
{
	for(i=0;i<size;i++)
{
				delete[] M[i];
				delete[] temp[i];
				delete[] product[i];
	}
	delete[] M;
	delete[] temp;
	delete[] product;
}	
void enter()
{
	cout<<"Enter the Adjacency Matrix elements\n";
	for(i=0;i<size;i++)
		{
		for(j=0;j<size;j++)
		{
			cout<<"A["<<(char)(ch+i)<<"]["<<(char)(ch+j)<<"]: ";
			cin>>M[i][j];
			temp[i][j] = M[i][j];
		}
		
	}
cout<<"\nEnter the length of the path: ";
cin>>len;
cout<<"Enter the initial vertex: ";
cin>>beg;
Vbeg = beg -97;
cout<<"Enter the final vertex: ";
cin>>end;
Vend = end - 97;
}


//void raiseTo()
//{
//
//	Path a(size);
//		for(i=0;i<size;i++)
//		{
//			for(j=0;j<size;j++)
//				{
//					for(int k=0;k<size;k++)
//						{
//							a.M[i][j] += T[size*i + j] * M[k][j];		//multiply algebra for 1d as 2d array
//						}
//				}
//		}
//	a.print();
//	M = a.M;	
//}

void multiply()
{
	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			{
				product[i][j] = 0;
				for(int k=0;k<size;k++)
					{
					product[i][j] += M[i][k] * temp[k][j];				}
			}
			}
	//printP();
	copyMatrix();
}

void print()
{ //cout<<"\nA^"<<len<<endl;
cout<<endl<<endl;
	for(i=0;i<size;i++)
		cout<<"\t"<<(char)(ch+i);
	for(i=0;i<size;i++)
	{
		cout<<endl<<(char)(ch+i);
		for(j=0;j<size;j++)
		{
			cout<<"\t"<<M[i][j];
		}
	}
}
void findPath()
{
	cout<<"\nThe Number of paths of length "<<len<<" between vertex "<<beg<<" and "<<end;
	cout<<" are \nA["<<beg<<"]["<<end<<"]: "<<M[Vbeg][Vend];

}
void calculate()
{
	for(int i=0;i<(len-1);i++)
	{
		multiply();
	}
	
}
void copyMatrix()
{
	for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
				{
					M[i][j] = product[i][j];
				}
		}
//temp = product;
}
};

int main()
{
	int a;
	cout<<"Enter the no of vertices in the Path: ";
	cin>>a;
	Path g1(a);
	g1.enter();
	g1.print();
	//g1.multiply();
	g1.calculate();
	g1.print();
	g1.findPath();
//getch();	
return 0;
}
