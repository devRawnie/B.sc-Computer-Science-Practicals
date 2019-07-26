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
	file.open("data.txt",ios::binary);
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
	ifstream myfile;
	myfile.open("data.txt",ios::binary);
	while(!myfile.eof()) 
	{
		for(int j=0;j<10;j++)

{
		myfile.read((char*)&s[j],sizeof(s[j]));	
		puts(s[j].name);
		cout<<endl<<s[j].rollno<<endl;
		cout<<s[j].classname<<endl;
		cout<<s[j].totalmarks<<endl;
		cout<<s[j].year<<endl;
			
}
		
	}
	return 0;
}
