#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	char str[20];
	void check(char[]);
	cout<<"enter any string: ";
	gets(str);
	check(str);
	return 0;
}
void check(char word[])
{
	int i,j,len,flag=1;
	len = strlen(word);
	for(i=0,j=len-1;i<=len/2;i++,j--)
	{
		if(word[i]!=word[j])
		{flag = 0;
		break;
		}
		
	}
	if(flag)
	{cout<<"\nThe given string is a palindrome";
	}
	else
	{
		cout<<"The given string is not a palindrome";
	}
}
