/*
  Name: 
  Copyright: 
  Author: rohit sharma, rakesh kumar
  Date: 10/04/18 10:43
  Description: 
*/
#include<iostream>
#include<conio.h>
using namespace std;
class Graph{
    private : int size;
        int **M;
    public: 
	int i,j;
	Graph( int a)
    {
    size = a;
    M = new int*[size];
		for( i =0;i<size;i++)
		{
			M[i] = new int[size];
    	}
    	
    	for( i=0;i<size;i++)
	{
		for( j =0;j<size;j++)
		{
			M[i][j] = 0;
		}
	
    }
    }
    ~Graph()
    {
	for(i=0;i<size;i++)
	{
		delete[] M[i];
	}
	delete[] M;
        
		}
    void enter()
    {
        int ch = 97;
        cout<<"Enter the elements of adjacency matrix";
            for( i=0;i<size;i++)
                {
                for( j=0;j<size;j++)
                {
                    cout<<"\nA["<<(char)(ch+i)<<"]["<<(char)(ch+j)<<"]: ";
                    cin>>M[i][j];
                    
                    }
                    }
        }
        void display()
        {
            int ch = 97;
            for( i=0;i<size;i++)
        {
            cout<<"\t"<<char(i+ch);
            }
            cout<<endl;
        for( i=0;i<size;i++)
            {
                cout<<endl<<(char)(ch+i);
                for( j=0;j<size;j++)
                {
                    cout<<"\t"<<M[i][j];
                    }
                }
            }
    bool diagCheck()
    {
        for( i=0;i<size;i++)
            {
                if(M[i][i]!=0)
                    return false;
            }
            return true;
        }
    bool sumCheck()
    {
        const int a = size;
        int sum[a], s = 0;;
        for( i=0;i<size;i++)
        { sum[i] = 0;
            for( j=0;j<size;j++)
            { 
                sum[i] += M[i][j];
                }
           //cout<<endl<<sum[i];
            }
            for( i =0;i<a;i++)
            {
                if(sum[i]!=(size-1))
                    return false;
                }
                
        return true;
        }
        void check()
        {
           // cout<<endl<<"sumcheck: "<<sumCheck();
            //cout<<endl<<"diagCheck: "<<diagCheck();
            if((sumCheck())&&(diagCheck()))
                {
                    cout<<"\nThe given graph is a complete graph";
                    }
            else{
                cout<<"\nThe given graph is not a complete graph";
                }
            }
    };

int main()
{int a ;
    cout<<"Enter the number of vertex in graph: ";
    cin>>a;
    Graph g(a);
    g.enter();
    g.display();
    g.check();
    getch();
    return 0;}
