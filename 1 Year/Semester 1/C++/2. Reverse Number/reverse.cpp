#include<iostream>
#include<math.h>
using namespace std;
void rev(int);
int main()
{
	int no;
	cout<<"enter any no: ";
	cin>>no;
	rev(no);
	return 0;
}
void rev(int x)
{
	int no=0,i,ar[10],count=0;
	for(i=0;x%10!=0;i++,x=x/10)
	{
		ar[i] = x%10;
	count++;
	}
i=0;	
while(count>0)
{
	no += ar[i]*pow(10,count-1);
	count--;
	i++;
		}	
cout<<"the reversed no is: ";
cout<<no;

}
