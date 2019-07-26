/*
	Name: relations	
	Copyright: none
	Author: Rohit sharma,Rakesh kumar
	Date: 20-01-18 12:39
	Description: 
*/
#include<iostream>
#include<conio.h>
#include<process.h>
#include<math.h>
int i,j;
using namespace std;
class Relations{
	
private:	int **Mr;
	 int *arr,size;
	 public:
~Relations()
{
    delete Mr;
    delete arr;
    }
void entersize()
{
    cout<<"\nEnter the size of the Set: ";
    cin>>size;
    arr  = new int[size];
    
    	Mr = new int*[size];
		for( i =0;i<size;i++)
		{
			Mr[i] = new int[size];
		}
	for(i=0;i<size;i++)
	{
		for( j =0;j<size;j++)
		{
			Mr[i][j] = 0;
		}
	}
    }
    void enterset()
    {
        cout<<"\nEnter unique elements of the set: \n";
        for( i =0;i<size;i++)
        {cout<<"->";
            cin>>arr[i];
        }
    }
void display()
{
	cout<<"\n";
	for(i =0 ;i<size;i++)
	{
		for( j=0;j<size;j++)
		{
			cout<<Mr[i][j]<<" ";
		}
	cout<<"\n";
	}
}
int findpos(int n)
{
	for(j=0;j<size;j++)
	{
		if(arr[j]==n)
		{
			return j;
		}
	}
return -1;
}
void enterRelation()	{	
	int a,x,y,k=0;		
	cout<<"\nEnter the no of ordered pairs in the relation:\n-> ";
	cin>>i;
	cout<<"\nEnter ordered pairs of the relation in the form a b";
    while(k<i)
	{
	cout<<"\nPair "<<k+1<<":\n";	
	cout<<"->";
	cin>>a;
	x = findpos(a);
	cout<<"->";
	cin>>a;
	y = findpos(a);
	if(x== -1 || y == -1)
	{
		cout<<" The given pair cannot be formed.Try Again";
		continue;
	}
	else
		Mr[x][y]++;
		k++;}
}
bool Reflexive()
{
	for(i=0;i<size;i++)
	{
		if(Mr[i][i]==0)
		{
			return false;
		}

	}
	return true;
	
}
bool Antisymmetric()
{
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(Mr[i][j])
			{
				if(Mr[j][i])
					{
						return false;
					}
			}
		
		}
	}
return true;
}

bool Symmetric()
{
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(Mr[i][j]!=Mr[j][i])
			{
				return false;
			}
		}
	}
return true;
}
bool Transitive()
{
    int k;
    for(i=0;i<size;i++)
    {
    for(j=0;j<size;j++)
    {
        if(Mr[i][j]==1)
        {
            for(k=0;k<size;k++)
            {
                if(Mr[j][k]==1)
                {
                    if(Mr[i][k]==1)    
                        return true;
                    else
                         return false;
                    }
                }
            }
        }
    }
    
    
    }
bool equivalence()
{
 if(Reflexive() && Symmetric() && Transitive())
    return true;                   
else
	return false;               
}
bool partial()
{
 if(Reflexive() && Antisymmetric() && Transitive())
    return true;                   
else
	return false;               
}    
};
int main()
{
    int ch;
    do{
	system("cls");
	Relations R1;
	R1.entersize();
	R1.enterset();
	prevset:
    R1.enterRelation();
    system("cls");
	R1.display();
    cout<<"Select one of the property: ";
	cout<<"\n1.Equivalence Relation.";
    cout<<"\n2.Partial Order Relation.\n->";
    cin>>ch;
	switch(ch)
	{
    case 1: if(R1.equivalence())
    		{
    			cout<<"\nRelation is an Equivalence Relation. "; 
			}
			else{
			 cout<<"\nRelation is not an Equivalence Relation. ";	
			}
            break;
    case 2: if(R1.partial())
                cout<<"\nRelation is a Partial Order Relation. ";        
            else
                cout<<"\nRelation is not a Partial Order Relation";
            break;
    default: cout<<"Wrong choice\n";
        }
        
    cout<<"\nPress 1 to repeat with same set.\n";
    cout<<"\nPress 2 to repeat with different set.\n";
    cout<<"\nPress 3 to exit.\n->";
    cin>>ch;
    if(ch==1)
    {
        goto prevset;
        
        }
    if(ch==3)
    {
        exit(0);
        }
    }while(ch==2);
	getch();
	return 0;
}

