#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std; 
class Segments{

	int segSize;
	public: 
	int decN,i,carry;
	int seg[8];
	Segments()
	{
		segSize = 8;
		for(i=0;i<8;i++)
			seg[i] = 0;
		decN = 0;
		carry  = 0;
	}
	void displaySeg()
	{
		cout<<endl;
		for(i=0;i<segSize;i++)
			cout<<seg[i]<<" ";
	}
	void getDecimal()
	{
		decN = 0;
		int j;
		for(i=segSize-1,j=0;i>=0;i--,j++)
		{
			if( seg[i]==1 )
				decN = decN + pow(2,j);
		}
	}
	void getBin(int x)
	{
		int temp = x;
		for(i=segSize-1;i>=0;i--)
		{
			seg[i] = temp%2;
			temp = temp/2;
		}
	}
	void getBin()
	{
		int temp = decN;
		for(i=segSize-1;i>=0;i--)
		{
			seg[i] = temp%2;
			temp = temp/2;
		}
if(temp==1)
			{
				
				this->getDecimal();
				decN++;
				getBin(decN);
			}
	}
	void copySeg(int *tmp)
	{
		for(i=0;i<segSize;i++)
			seg[i] = tmp[i];
	}
	void invert()
	{
		for(i=0;i<segSize;i++)
			seg[i] = !(seg[i]);
		
	}
};
Segments result;
class CheckSum{
	int *data;
	int size,i,j,segN;
	Segments *sgmnt;
	
	int getSegN()
	{
		int temp = size;
		int k = 0;
		while(temp>0)
		{
			
			k++;
			temp = temp - 8;
		}
		return k;
	}
	
	public:
		CheckSum(int s)
		{
			size = s;
			data = new int[size];
			for(i=0;i<size;i++)
				data[i] = 0;
			segN =  0;
			sgmnt = 0;
		i = j = 0;
		}
		
		~CheckSum()
		{
				delete[] data;
			delete[] sgmnt;
		}
	
		void getData()
		{
			cout<<"\nEnter the data bitwise: \n";
			for(i=0;i<size;i++)
			{
				cout<<": ";
				cin>>data[i];
			}
			cout<<"\nENTERED DATA IS: ";
			displayData();
					}
		void displayData()
		{
			cout<<endl;
			for(i=0;i<size;i++)
				cout<<data[i]<<" ";
		}
	
		void formSegments()
		{
			segN  =  getSegN();
			
			sgmnt = new Segments[segN];
			for(i=0;i<segN;i++)
			{
				for(j=0;j<8;j++)
				{
					sgmnt[i].seg[j] = data[j+i*8];
				}
			}
			cout<<"\n SEGMENTS FORMED: ";
			displaySegments();
		
		for(i=0;i<segN;i++)
			sgmnt[i].getDecimal();
		}
		void findSum()			
		{
			result.decN = sgmnt[0].decN;
			for(i=1;i<segN;i++)
			{
				result.decN += sgmnt[i].decN;
				result.getBin();
				result.getDecimal();
			}
			result.getBin();
			result.invert();
			cout<<"\nCHECK SUM BITS: ";
			result.displaySeg();
		
		}
		void displaySegments()
		{
			for(i=0;i<segN;i++)
				{
				sgmnt[i].displaySeg();
			}
		}
	void copyFromData(int *&x)
	{
		for(i=0;i<size;i++)
			x[i] = data[i];
	}
		void copyInData(int *&x, int s)
	{
		for(i=0;i<s;i++)
			data[i] = x[i];
			
		int tmpsize = s+8;
		for(i=s;i<tmpsize;i++)
			data[i] = result.seg[i-s];
	}
void changeBits()
{
		int pos = randomBit(size);
		cout<<"\n\n Changing bits at position: "<<pos+1;
		data[pos] = !(data[pos]);
		
		displayData();
}
void compute()
{
	formSegments();
	findSum();
		}		
int randomBit(int size)
{
	srand(time(0));
	int bit = rand()%(size + 1 );
	return bit;
}
void finalCheck()
{
	result.getDecimal();
	if(result.decN==0)
		cout<<"\nMESSAGE RECIEVED SUCCESFULLY";
	else
		cout<<"\nTHERE HAS BEEN AN ERROR IN TRANSMISSION";
		
}
};
int main()
{
	int s;
	int* temp = new int[s];
	for(int i=0;i<s;i++)
		temp[i]  = 0;
	cout<<"Enter the size of the Data Word: ";
	cin>>s;
	CheckSum Sender(s);
	Sender.getData();
	cout<<"\n\nSENDER IMPLEMENTING CHECKSUM\n";
	Sender.compute();
	Sender.copyFromData(temp);
	CheckSum rcv(s+8);
	rcv.copyInData(temp,s);
	cout<<"\n\nMESSAGE TRANSMITTED: ";
	rcv.displayData();
	rcv.changeBits();
	cout<<"\n\nRECIEVER IMPLEMENTING CHECKSUM\n";	
	rcv.compute();
	rcv.finalCheck();
delete[] temp;
return 0;
}
