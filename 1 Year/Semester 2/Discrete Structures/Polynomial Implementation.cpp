/*
  Name: p15
  Copyright: 
  Author: rohit sharma, rakesh kumar
  Date: 10/04/18 09:43
  Description: 
*/
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class Polynomial{
    private: int order,size,n;
    public: 
        int* array;
        Polynomial(int a)
    {
        order = a;
        size = a+1;
        array = new int[size];
        
        }
        ~Polynomial()
        {
            delete[] array;}
        
        void enter()
        {
            cout<<"Enter the value of n: ";
            cin>>n;       
            }
    void formP()
    {
        
        for(int i=0;i<=order;i++)
        {cout<<"Enter the coeffecient of n^"<<i<<": ";
        cin>>array[i];}
        }
        void evaluate()
        {
            float sum =0;
            for(int i=0;i<=order;i++)
            {
                sum= sum+(pow(n,i)*array[i]);
                
                }
            cout<<"f(n): ";
            for(int i=order;i>=0;i--)
            { if(i!=0)
                { if(array[i]!=0)
                    cout<<array[i]<<"n^"<<i<<"+";
                  else
                    continue;
            }
              else
                cout<<array[i];                
                }
            cout<<endl<<"f("<<n<<") = "<<sum;
            }
    };
int main()
{ int n;
    cout<<"Enter the order of the polynomial: ";
    cin>>n;
    Polynomial p(n);
    p.enter();
    p.formP();
    p.evaluate();
    getch();
    return 0;}
