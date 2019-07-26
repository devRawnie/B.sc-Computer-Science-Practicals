#include<iostream>
#include<math.h>
using namespace std;
class Segment
{
	int size,i,j,dec;
	public:
	int seg[8];
		Segment()
		{
			i = j =0;
			dec = 0;
			size = 8;
			for(i=0;i<size;i++)
				seg[i] = 0;
		}
		void displaySegment()
		{
			cout<<endl;
			for(i=0;i<size;i++)
				cout<<" "<<seg[i];
		}
void B_to_D()
{
for(i=size-1,j=0;i>=0;i--,j++)
{
	if(seg[i] == 1)
	{
		dec = dec + pow(2,j);
	}
	}
}
int getDec()
{
	return dec;
}
int getSegSize()
	{
		return size;
	}
};
class IP{
	int size,i,j,segSize, segN;
	int ipB[32];
	Segment segments[4];
public:
	IP()
	{
		i = j = 0;
		size = 32;
		for(i=0;i<size;i++)
			ipB[i] = 0;
			segSize = segments[0].getSegSize();
			segN = size/segSize;
	}


	void getIPB()
	{
		cout<<"\nEnter the binary stream of IP address\n";
		for(i=0;i<size;i++)
		{
			cout<<i+1<<" : ";
			cin>>ipB[i];
			
		}
	}
void displayIPB()
{
	cout<<endl;
	for(i=0;i<size;i++)
	{
		cout<<" "<<ipB[i];
	}
}
void formSegment()
{
	
//	cout<<":: "<<segN;
	for(i=0;i<segN;i++)
			{
				for(j=0;j<segSize;j++)
				{
					segments[i].seg[j] = ipB[j+i*8];
				}
			}
}
void convertSegments()
{
	for(i=0;i<segN;i++)
		segments[i].B_to_D();
}
void displaySegments()
{
	for(i=0;i<segN;i++)
{	
	segments[i].displaySegment();
	cout<<"   ";
	cout<<segments[i].getDec();
}
}
void formatIP()
{
	cout<<"\n\n IP: ";
	for(i=0;i<segN;i++)
	{
		cout<<segments[i].getDec();
		if(i!=(segN-1))
			cout<<".";
	}
	
cout<<"\n "<<"IP is of class "<<(checkIPClass())<<" network ";
	
}
char checkIPClass()
{
	int temp = segments[0].getDec();
	cout<<":: "<<temp;
	if(temp>=0 && temp<=127)
		return 'A';
	else if(temp>=128 && temp<=191)
		return  'B';
	else if(temp>=192 && temp<=223)
		return  'C';	
	else if(temp>=224 && temp<=239)
		return  'D';
	else if(temp>=240 && temp<=255)
		return  'E';
}
};
int main()
{
	IP obj;
	obj.getIPB();
	obj.displayIPB();
	obj.formSegment();
	obj.convertSegments();
	obj.displaySegments();
	obj.formatIP();
	return 0;
}
