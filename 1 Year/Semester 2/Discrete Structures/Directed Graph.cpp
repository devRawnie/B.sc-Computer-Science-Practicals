#include<iostream>
#include<conio.h>
using namespace std;
class DGraph{
    private :int size;
        int **M;
    public: 
	int i,j,ch;
	DGraph(int a)
    {
    	ch =97;
    size = a;
    M = new int*[size];
		for(i =0;i<size;i++)
		{
			M[i] = new int[size];
    	}
    	
    	for(i=0;i<size;i++)
	{
		for(j =0;j<size;j++)
		{
			M[i][j] = 0;
		}
	
    }
    }
    
    ~DGraph()
    {
        for(i=0;i<size;i++)
	{
		delete[] M[i];
	}
	delete[] M;
    }
    void enter()
    {
        
        cout<<"Enter the elements of adjacency matrix (FOR DIRECTED GRAPH)";
            for(i=0;i<size;i++)
                {
                for(j=0;j<size;j++)
                {
                    cout<<"\nA["<<(char)(ch+i)<<"]["<<(char)(ch+j)<<"]: ";
                    cin>>M[i][j];
                    
                    }
                    }
        }
        void display()
        {
            
            for(i=0;i<size;i++)
        {
            cout<<"\t"<<char(i+ch);
            }
            cout<<endl;
        for(i=0;i<size;i++)
            {
                cout<<endl<<(char)(ch+i);
                for(j=0;j<size;j++)
                {
                    cout<<"\t"<<M[i][j];
                    }
                }
            }
    void indegree()
    {
        const int a = size;
        int sum[size];
        for(i=0;i<size;i++)
        {
            sum[i] = 0;
            for(j=0;j<size;j++)
            {
                sum[i]+= M[i][j];
                }       
            }
            cout<<"\nSum of indegrees:\n";
        for(i=0;i<size;i++)    
        {
        	cout<<"indeg("<<(char)(ch+i)<<"): "<<sum[i]<<endl;
		}
		}
    void outdegree()
    {
        const int a = size;
        int sum[size];
        for(i=0;i<size;i++)
        {
            sum[i] = 0;
            for(j=0;j<size;j++)
            {
                sum[i]+= M[j][i];
                }       
            }
            cout<<"Sum of outdegrees:\n";
        for(i=0;i<size;i++)    
        {
        	cout<<"outdeg("<<(char)(ch+i)<<"): "<<sum[i]<<endl;
		}
		}
    };

int main()
{int a ;
    cout<<"Enter the number of vertex in graph: ";
    cin>>a;
    DGraph dg(a);
    dg.enter();
    dg.display();
    dg.indegree();
    dg.outdegree();
    getch();
    return 0;}
