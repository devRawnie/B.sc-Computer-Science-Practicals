#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
struct student
{
	int rollno;
	char name[20];
	int classname;
	int year;
	float totalmarks;
};
int main()
{
	student s[10];
	ofstream file;
	file.open("data.dat",ios::binary);
	for(int i=0;i<10;i++)
	{
		cout<<"Enter the name of student "<<i+1<<":";
		gets(s[i].name);
		cout<<"Enter the roll no. of student "<<i+1<<":";
		cin>>s[i].rollno;
		cout<<"Enter the class of student "<<i+1<<":";
		cin>>s[i].classname;
		cout<<"Enter the year of student "<<i+1<<":";
		cin>>s[i].year;
		cout<<"Enter the total marks of student "<<i+1<<":";
		cin>>s[i].totalmarks;		
		}	
		for(int j=0;j<10;j++)

{
		file.write((char*)&s[j],sizeof(s[j]));	
}
	file.close();
	return 0;
}
