#include<iostream>
#include<string.h>
using namespace std;
char temp;
void reverseString(string &s, int l, int u)
{
	if(l<u)
	{
		temp = s[l];
		s[l] = s[u];
		s[u] = temp;
		reverseString(s, l+1, u-1);
	}
}
int main()
{
	string s;
	cout<<"\nEnter any string: ";
	getline(cin, s);
	reverseString(s, 0 , s.length()-1);
	cout<<"\nReversed string is : "<<s;
	return 0;
}
