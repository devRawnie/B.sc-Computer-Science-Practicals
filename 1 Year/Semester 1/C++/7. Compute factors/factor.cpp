#include<iostream>
using namespace std;
int main()
{
	int no;
	void find_factor(int);
	cout<<"Enter any no: ";
	cin>>no;
	find_factor(no);
	return 0;
}
void find_factor(int n)
{int ar[10],i=0,count=0,a=1;
	while(a<n+1)
	{
		if(n%a==0)
		{
			ar[i]=a;
			i++;
			count++;
		}
	a++;

	}
i=0;
while(i<count)
{
	cout<<"Factor "<<i<<": "<<ar[i]<<endl;
	i++;
}

}

