#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;

char str1[50],str2[50];
int i,j;

void show_add(); 
void conc_with();
void conc_without();
void compare();
void cal_length();
void convert_ltou();
void convert_utol();
void cal_vowel();
void reverse();
int main()
{
	int ch;
	cout<<"Choose from the following: \n";
cout<<"1. Show address of each character in string.\n";
cout<<"2. Concatenate two strings without using strcat function.\n";
cout<<"3. Concatenate two strings using strcat function.\n";
cout<<"4. Compare two strings\n";
cout<<"5. Calculate length of the string (use pointers)\n";
cout<<"6. Convert all lowercase characters to uppercase\n";
cout<<"7. Convert all uppercase characters to lowercase\n";
cout<<"8. Calculate number of vowels\n";
cout<<"9. Reverse the string\n";
cin>>ch;
	
switch(ch)
{
	case 1:	show_add();
		break;
	case 2: conc_without();
		break;
	case 3: conc_with();
		break;
	case 4: compare();
		break;
	case 5: cal_length();
		break;
case 6: convert_ltou();
		break;
case 7: convert_utol();
		break;
case 8: cal_vowel();
		break;
case 9: reverse();
		break;
	
default: cout<<"wrong choice";
	}	
	return 0;
}
void show_add()
{cin.ignore(256,'\n');
	
cout<<"Enter a string: ";
	gets(str1);	
	
	for(i=0;str1[i]!='\0';i++)
	{
		cout<<"\nAddress of "<<i+1<<" character : "<<&str1+i*sizeof(char);
	}
}
void conc_with(){
	cin.ignore(256,'\n');

cout<<"Enter first string: ";
	gets(str1);	
	cout<<"Enter second string: ";
	gets(str2);	
	strcat(str1,str2);
	cout<<"\nConcatenated string is "<<str1;
}
void conc_without(){
cout<<"Enter first string: ";
	gets(str1);	
	cout<<"Enter second string: ";
	gets(str2);	
while(str1[i]!='\0')
  i++;
  while(str2[j]!='\0')
  {
    str1[i]=str2[j];
    j++;
    i++;
  }
  str1[i]='\0';
}
void compare(){
	int val;
cout<<"Enter first string: ";
	gets(str1);	
	cout<<"Enter second string: ";
	gets(str2);	
val = strcmp(str1,str2);
if(val==0)
{
	cout<<"Both strings are equal";
	}	
else if(val>0)
{
	cout<<"First string "<<str1<<" is greater than the second string "<<str2<<"  \" ";
	}	
else
{	cout<<"First string";
puts(str1);
cout<<" is smaller than the second string";
puts(str2);
cout<<" \" ";
}
}
void cal_length(){
int len;
cout<<"Enter a string: ";
gets(str1);
len = strlen(str1);
cout<<"\nThe length of given string is: "<<len;
}
void convert_ltou(){
cout<<"Enter a string: ";
gets(str1);
for(i=0;str1[i]!='\0';i++)
{
	if(islower(str1[i]))
	{
		toupper(str1[i]);
	}
	}	
cout<<"\nThe modified string is :";
puts(str1);
}
void convert_utol(){
cout<<"Enter a string: ";
gets(str1);
for(i=0;str1[i]!='\0';i++)
{
	if(isupper(str1[i]))
	{
		tolower(str1[i]);
	}
	}	
cout<<"\nThe modified string is :";
puts(str1);

}
void cal_vowel(){
int vowel[5];
cout<<"\nEnter a string";
gets(str1);
for(i=0;str1[i]!='\0';i++)
{
tolower(str1[i]);
}
for(i=0;str1[i]!='\0';i++)
{
	switch(str1[i])
	{
		case 'a': vowel[0]++;
		case 'e': vowel[1]++;
		case 'i': vowel[2]++;
		case 'o': vowel[3]++;
		case 'u': vowel[4]++;
		default: break;
	}
}
cout<<"No of vowels in the string are: "<<endl;
cout<<"a: "<<vowel[0]<<endl;
cout<<"e: "<<vowel[1]<<endl;
cout<<"i: "<<vowel[2]<<endl;
cout<<"o: "<<vowel[3]<<endl;
cout<<"u: "<<vowel[4]<<endl;

}

void reverse(){
cout<<"Enter a string: ";
gets(str1);
 int len=  strlen(str1);
 for (int i=0; i<len/2; i++)
       swap(str1[i], str1[len-i-1]);
}

