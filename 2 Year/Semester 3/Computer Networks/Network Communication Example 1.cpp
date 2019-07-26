#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
using namespace std;
struct Packet{
	string message;
};
struct Frame{
	Packet pkt;
	int frame_no;
};
struct ACK{
	int ack;
};
ACK Ack;


//void delay(int t)
//	{
//		for(int i=0;i<t;i++)
//			Sleep(1000);
//	}
int generateRandom()
{
	srand(time(0));
	int rbit = rand()%(2-1+1);
	return rbit;
}

void set_ack(bool var)
	{
		if(var)
			Ack.ack = 1;
		else
			Ack.ack = 0;
	}
	void dataToNetwork(Packet r_packet)
	{	sleep(1);
		cout<<"\n\nRecieved Packet";
		cout<<"\nWith message - "<<r_packet.message;
	}
	void physicalToData(Frame r_frame)
	{
		
//		for(int i = 0;i<3;i++)
//		{
//			cout<<"\n\nRetreiving Message: ";
//			sleep(1);
//		}
sleep(1);
	cout<<"\n\nRecieved Frame"<<r_frame.pkt.message<<"-"<<r_frame.frame_no;
	Packet r_packet = r_frame.pkt;
	dataToNetwork(r_packet);
	}
 bool toRecieversPhysical(Frame r_frame)
{
int bit = generateRandom();
	
	if(bit==1)
		{
		set_ack(true);
		return true;	
}
else
{
	set_ack(false);
	return false;
}
}

void dataToPhysical(Packet s_packet)
	{
	//	cout<<"\n\nRecieved in Data Layer";
		bool flag = false;
		Frame s_frame;
		s_frame.pkt = s_packet;
		s_frame.frame_no = 0;
		cout<<"Sending "<<s_frame.pkt.message<<"-"<<s_frame.frame_no;
		sleep(1);
		for(int i=0;i<3;i++)
		{
		cout<<"\n\nSending to Reciever";
		sleep(1);	
		}
		cout<<"\nFrame sent";

		for(int i=0;i<5;i++)
		{
			sleep(1);
			cout<<"\nWaiting for acknowldgement:  ";
			if(toRecieversPhysical(s_frame))
			{
				cout<<"\nAcknowldgement Recieved ";
				flag = true;
				break;
			}
		}

		if(flag)
			physicalToData(s_frame);
		else{
			cout<<"\n\nAcknowledgment not recieved\nSending Frame Again\n";
			dataToPhysical(s_frame.pkt);
		}
		}

void networkToData(string msg)
	{
		Packet s_packet;
		s_packet.message = msg;		
//		for(int i=0;i<3;i++)
//		{
//			cout<<"\n\nSending Frame to Data Layer";
//			sleep(1);
//		}
		dataToPhysical(s_packet);
	}
	
void getMessage()
{
cout<<"\nEnter Message: ";
string msg;
getline(cin, msg);
networkToData(msg);
}

int main()
{
	getMessage();
	return 0;
}
