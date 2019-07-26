#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char word[50];
	void count(char []);
	cout<<"Enter any string: ";
	gets(word);
	count(word);
	return 0;
}
void count(char x[])
{
	int ar[26],temp,len,j;
	len = strlen(x);
	char t;
	int i=0,pos;
	while(i<26)
	{
		ar[i] = 0;
		i++;
	}
	i=0;
	while(i<len)
	{
		t = x[i];
		j=0;
		while(j<len)
		{
			if(x[j]==t)
			{ 
				ar[i]++;	
			}
		
		j++;
		}	
	i++;
	}
	for(i=0;i<len;i++)
	{
		cout<<x[i]<<" = ";
		cout<<". "<<ar[i]<<endl;
	}
}
