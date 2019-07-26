
#include<iostream>
#include<conio.h>
using namespace std;
class TruthTable{
int    logic[4][2],result[4];
    int i,j;
    public:
    TruthTable()
    {
    logic[0][0] = 0;        
    logic[0][1] = 0;        
    logic[1][0] = 0;        
    logic[1][1] = 1;        
    logic[2][0] = 1;        
    logic[2][1] = 0;        
    logic[3][0] = 1;        
    logic[3][1] = 1;        
    
	for(i=0;i<4;i++)
		result[i] = 0;
        }
        void display()
        {
        	int temp =0;
        	
        	cout<<"P\tQ\tResult\n";
        	
        	for(i=0;i<=1;i++)
        	{
        		for(j=0;j<=1;j++)
        		{
        			if(i==0)
        				cout<<"FALSE\t";
        			else
        				cout<<"TRUE\t";
					if(j==0)
						cout<<"FALSE\t";
					else
						cout<<"TRUE\t";
					if(temp!=4)
						if(result[temp++]==0)
							cout<<"FALSE"<<endl;
						else
							cout<<"TRUE"<<endl;
					else 
						break;		
				}
				
			}
        	
		}
       
void negation()
{
	int p;
	
		cout<<"p\t~p\n";
	for(i=0;i<=1;i++)
	{
		p = !i;
		if(i==0)
			cout<<"FALSE\t";
		else
			cout<<"TRUE\t";
		if(p==0)
			cout<<"FALSE\n";
		else
			cout<<"TRUE\n";
	}
}
            
            
            
  void conjunction()
 {
        for(i=0;i<4;i++){
        
            
                result[i] = logic[i][0]&logic[i][1];
            
        }
        display();
        }
void disjunction()
{
     for(i=0;i<4;i++){
        
            
                result[i] = logic[i][0]|logic[i][1];
            
        }
        display();
    }
void Xor()
{
             for(i=0;i<4;i++){
        
            
                 result[i] = logic[i][0] ^ logic[i][1];;
            
        }
        display();
}
void Xnor()
{
             for(i=0;i<4;i++){
        
            
                 result[i] = (!(logic[i][0] ^ logic[i][1]));
            
        }
        display();
}
            
void nand()
{
 
        for(i=0;i<4;i++){
        
            
                result[i] = !(logic[i][0]&logic[i][1]);
            
        }
        display();
        
	
}
void nor()
 {
        for(i=0;i<4;i++){
        
            
                result[i] = (!(logic[i][0] | logic[i][1]));
            
        }
        display();
        }
void conditional()
 {
        for(i=0;i<4;i++){
        
            
                result[i] = ((!logic[i][0]) | logic[i][1]);
            
        }
        display();
        }
    void biconditional()
 {
        for(i=0;i<4;i++){
        
            
                result[i] = ((!logic[i][0]) | logic[i][1]) & (logic[i][0] | (!logic[i][1]));
        }
        display();
        }
          };

int main()
{
	
    TruthTable tb;
int ch;
    do{
    	system("cls");
	cout<<"\nEnter your choice:\n ";
    cout<<"1.Conjunction (p & q)\n";
    cout<<"2.Disjunction (p | q)\n";
    cout<<"3.Exclusive OR \n";
    cout<<"4.Conditional (p -> q)\n";
    cout<<"5.Biconditional (p <-> q)\n";
    cout<<"6.Exclusive NOR \n";
    cout<<"7.Negation (~p)\n";
    cout<<"8.NAND ~(p & q)\n";
    cout<<"9. NOR ~(p v q)\n";
    cin>>ch;
    switch(ch)
    {
        case 1: tb.conjunction();
                break;
        case 2: tb.disjunction();
                break;
        case 3: tb.Xor();
                break;
        case 4: tb.conditional();
                break;
        case 5: tb.biconditional();
                break;
        case 6: tb.Xnor();
                break;
        case 7: tb.negation();
                break;
        case 8: tb.nand();
                break;
        case 9: tb.nor();
                break;
        default: cout<<"Wrong choice";
                break;        
        
        }
		cout<<"\nPress 1. to repeat\nPress 2 to exit";
		cin>>ch;
		if(ch==2)
			exit(0);
		}while(ch==1);
    getch();    
    return 0;
  }
