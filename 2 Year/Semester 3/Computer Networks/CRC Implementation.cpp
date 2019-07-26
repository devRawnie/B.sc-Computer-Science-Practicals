#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
class Crc{
	int i, j, dataSize, deg, streamSize, codeWordSize, bits;
	int *dataWord, *stream, *codeWord, *div, *message;
	public:
		Crc(int degree)
		{
			deg = degree;
			dataSize = -1;
			streamSize = deg+1;
			stream = new int[streamSize];
			dataWord = NULL;
			codeWord = NULL;
			message = NULL;
		}
		~Crc()
		{
			delete [] stream;
			delete [] codeWord;
			delete [] dataWord;
			delete [] div;
			delete [] message;
		}
		
		void enterPolynomial()
		{
			for(i=0;i<streamSize;i++)
			{
				cout<<"Enter the coefficient of x^"<<deg-i<<": ";
				cin>>stream[i];
			}
	formPolynomial();
	}
		void formPolynomial()
		{
		cout<<"\nThe entered polynomial is: ";
			for(i=0;i<streamSize;i++)
			{
				if(stream[i]>0)
				{
					if((deg-i)==0)	
						cout<<" 1 ";
					else if(stream[i]==1)
						cout<<" x^ "<<deg-i<<" + ";
					else
						cout<<stream[i]<<" x^ "<<deg-i<<" + ";
				}
				
			}
		}	
	int getCodeSize()
	{
		return (dataSize + deg);
	}
void enterData()
{
	long dataStream;
	cout<<"\nEnter the size of the data: ";
	cin>>dataSize;
	dataWord = new int[dataSize];
	cout<<"\n Enter the data as continuos stream of bits (Ex. 1011010110): ";
	cin>>dataStream;
	getData(dataStream);
}
void getData(long tempData)   // retrieves data in array from the continuos LONG stream
{
i  = dataSize - 1 ;
int flag=0;
while(tempData>0)
{
	if(i<0)
		{
		flag = 1;
		break;
		}
dataWord[i] = tempData%10;
tempData = tempData/10;
i--;
}
if(flag == 1)
	{
		
	cout<<"\n OVERLOAD!! Try again\n";
	enterData();
	}
	
}
void displayData()
{
	cout<<endl;
	for(i=0;i<dataSize;i++)
		cout<<dataWord[i]<<" ";
}
void formDiv()
{
	if(dataSize==-1)
		enterData();
	codeWordSize = getCodeSize();
	//cout<<"\nCodeWordSize: "<<codeWordSize;
	div = new int[codeWordSize];
	for(i=0;i<dataSize;i++)
		div[i] = dataWord[i];
	while(i<codeWordSize)
		{
		div[i] = 0;
		i++;}
}
void displayDiv()
{
cout<<endl;
	for(i=0;i<codeWordSize;i++)
		cout<<div[i]<<" ";
}
void shift(int *x)
{
	for(i=1;i<codeWordSize;i++)
	{
		x[i-1] = x[i];
	}
	codeWordSize--;
}
void performXor(int *x)
{
	for(i=0;i<streamSize;i++)
	{
		x[i] = x[i] ^ stream[i];
	}
shift(x);
} 
void CRCGenerator(){

	while(codeWordSize>=streamSize)	
	{
		//displayDiv();
		//cout<<"\nOutside if: div[i]"<<div[0]<<" ";
		if(div[0]==1)
		{
			//cout<<"\nInside if: ";
			performXor(div);
			
			}
	else
			shift(div);
	}
	//displayDiv();
	bits = codeWordSize;
	cout<<"\nCRC BITS AT SENDER SIDE: ";
	for(i=0;i<bits;i++)
	{
		cout<<div[i]<<" ";
	}
	codeWordSize = getCodeSize();
	formCodeWord();
}
void displayCode()
{
	for(i=0;i<codeWordSize;i++)
		cout<<codeWord[i]<<" ";
}
void formCodeWord()
{
	codeWord = new int[codeWordSize];
	for(i=0;i<dataSize;i++)
		codeWord[i] = dataWord[i];
	
	for(i=0;i<bits;i++)
		codeWord[dataSize+i] = div[i];
cout<<"\nMESSAGE TRANSMITTED: ";
	displayCode();
}

void formMsg()
{
	int msgSize = getCodeSize();
	message = new int[msgSize];
	for(i=0;i<msgSize;i++)
	{
		message[i] = codeWord[i];
	}
	int pos = randomBit(msgSize);
	//cout<<"\npos: "<<pos<<"msg[pos]: "<<message[pos]<<endl;
	cout<<"\nInverting bit at pos: "<<pos<<" ";
	message[pos] = !(message[pos]);
	cout<<endl<<"\nMESSAGE RECIEVED:    ";	
	for(i=0;i<msgSize;i++)
	{
		cout<<message[i]<<" ";
	}
}
void CRCChecker()
{

	while(codeWordSize>=streamSize)	
	{
		//displayDiv();
		//cout<<"\nOutside if: div[i]"<<div[0]<<" ";
		if(message[0]==1)
		{
			//cout<<"\nInside if: ";
			performXor(message);
			
			}
	else
			shift(message);
	}
	bits = codeWordSize;
	cout<<endl;
	cout<<"\nCRC_BITS AT RECIEVER END: ";
	for(i=0;i<bits;i++)
	{
		
		cout<<message[i]<<" ";
	}
	for(i=0;i<bits;i++)
	{
		if(message[i]==1)
			{
				cout<<"\nThere has been an error in transmission.";
				break;
			}
	}
	if(i==bits)
		cout<<"\nThere is no error in the recieved message.";
	codeWordSize = getCodeSize();
	
}	

int randomBit(int size)
{
	srand(time(0));
	int bit = rand()%(size + 1 );
	return bit;
}
};

int main()
{
	int dg;
	cout<<"Enter the degree of the polynomial: ";
	cin>>dg;
	Crc ob(dg);
	ob.enterPolynomial();
	ob.enterData();
	ob.formDiv();
    ob.CRCGenerator();
	ob.formMsg();
	ob.CRCChecker();
	return 0;

}
