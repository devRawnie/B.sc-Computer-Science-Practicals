/*
	Name: 
	Copyright: 
	Author: rohit sharma, rakesh kumar
	Date: 12-04-18 17:04
	Description: 
*/
#include<iostream>
#include<conio.h>
using namespace std;
class Graph{
    private :int size;
        int **M;
    public: 
	int i,j,ch;
	Graph(int a)
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
        
        cout<<"Enter the elements of adjacency matrix (FOR DIRECTED/UNDIRECTED GRAPH)";
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
	bool EulerCircuitUndirected()
	{
        const int a = size;
        int sum[a];
        for( i=0;i<size;i++)
        { sum[i] = 0;
            for( j=0;j<size;j++)
            { 
                sum[i] += M[i][j];
                }
            }
            for( i =0;i<a;i++)
            { 
                if((sum[i]%2)!=0)
                    return false;
                }
                
        return true;
    
		} 
	bool EulerCircuitDirected()
	{
        const int a = size;
        int sumR[a],sumC[a], s = 0;
        for( i=0;i<size;i++)
        { sumR[i] = sumC[i] = 0;
            for( j=0;j<size;j++)
            { 
                sumR[i] += M[i][j];
                sumC[i] += M[j][i];
				}
            }
            for( i =0;i<a;i++)
            { 
                if(sumR[i]!=sumC[i])
                    return false;
                }
                
        return true;
    
		}
	bool EulerPath()
	{
        const int a = size;
        int sum[a], s = 0;
        for( i=0;i<size;i++)
        { sum[i] = 0;
            for( j=0;j<size;j++)
            { 
                sum[i] += M[i][j];
                }
            }
            int test = 0;
            for( i =0;i<a;i++)
            {
                if(sum[i]%2==1)
                	test++;
                }
            
        if(test==2)
			return true;
		else 
			return false;    
		}    
	void check()
	{
		int ch;
		cout<<"Enter your choice\n";
		cout<<"1.Euler Circuit (Undirected Graph)\n";
		cout<<"2.Euler Circuit (Directed Graph)\n";
		cout<<"3.Euler Path (Directed Graph)\n";
		cin>>ch;
		switch(ch)
		{
			case 1: if(EulerCircuitUndirected())
						cout<<"\nThe given UnDirected graph has a EULER CIRCUIT";
					else
						cout<<"\nThe given UnDirected graph does not have a EULER CIRCUIT";
					break;
			case 2: if(EulerCircuitDirected())
						cout<<"\nThe given Directed graph has a EULER CIRCUIT";
					else
						cout<<"\nThe given Directed graph does not have a EULER CIRCUIT";
					break;
			case 3: if(EulerPath())
						cout<<"\n The given graph has a Euler Path";
					else
						cout<<"\n The given graph does not have a Euler Path";					
			default: cout<<"Wrong Choice";
				}
			}
};

int main()
{int a ;
    cout<<"Enter the number of vertex in graph: ";
    cin>>a;
    Graph g(a);
    g.enter();
    //g.display();
    g.check();
    getch();
    return 0;}
