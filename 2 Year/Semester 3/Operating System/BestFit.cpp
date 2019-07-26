#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
class Block{
	int size;
	int b_no;
	bool occupied;
	string status;
	public:
		Block(int b = 0, int s=0)
		{
			b_no = b;
			size = s;
			occupied = false;
		}
	bool isOccupied()
	{
		if(occupied)
			return true;
		else
			return false;
	}
	void setStatus(bool s)
	{
		if(s)
		{
			occupied = true;
			status = "YES";
		}
		else
		{
			occupied = false;
			status  = "NO";
		}
	}
	string getStatus()
	{
		return status;
	}
		
		void setSize(int s)
		{
			size = s;
		}
		int getSize()
		{
			return size;
	}
	void setNo(int b)
	{
		b_no = b;
	}
	int getNo()
	{
		return b_no;
	}
};
class Process{
	int pid;
	int req;
	int blockNo;
	string status;
	bool allocated;
	public:
		Process(int p = 0, int r=0, int b = 0)
		{
			pid = p;
			req = r;
			blockNo = 0;
			allocated = false;
		}
	bool isallocated()
	{
		if(allocated)
			return true;
		else
			return false;
	}
	void setAllocation(bool s)
	{
		if(s)
		{
			allocated = true;
			status = "ALLOCATED";
		}
		else
		{
			allocated = false;
			status = "NOT ALLOCATED";
		}
	}
	string getAllocation()
	{
		return status;
	}
		
		void setReq(int r)
		{
			req = r;
		}
		int getReq()
		{
			return req;
		}
		void setBlock(int b)
		{
			blockNo = b;
		}
		int getBlock()
		{
			return blockNo;
				}
		void setPID(int p)
		{
			pid = p;
		}
		int getPID()
		{
			return pid;
		}
};
class BestFit{
	Block *block;
	Process *process;
	int n_blocks;
	int n_process;
	int i,j;
	public:
		BestFit()
		{
			block = 0;
			process = 0;
			n_blocks = 0;
			n_process  = 0;
			i = j = 0;
		}
		~BestFit()
		{
			delete[] block;
			delete[] process;
		}
		void getBlocks()
		{
			int temp_size = 0;
			cout<<"\nEnter the no of memory blocks: \n";
			cin>>n_blocks;
			block = new Block[n_blocks];
			cout<<"Enter the size of block : ";
			for(i = 0;i<n_blocks;i++)
			{
				block[i].setNo(i+1);
				cout<<"B-"<<i+1<<": ";
				cin>>temp_size;
				block[i].setSize(temp_size);
				block[i].setStatus(false);
			}
		}
		void getProcess()
		{
			int temp_req;
			cout<<"\nEnter the no of processes: ";
			cin>>n_process;
			process = new Process[n_process];
			cout<<"\nEnter the memory requirement of process : \n";
			for(i = 0;i<n_process;i++)
			{
				process[i].setPID(i+1);
				cout<<"P-"<<i+1<<": ";
				cin>>temp_req;
				process[i].setReq(temp_req);
				process[i].setAllocation(false);
			}
		}
		void displayBlocks()
		{
			string stat;
			cout<<"\n\n";
			cout<<"\tBLOCK NO\tBLOCK SIZE\tALLOCATED\n";
			for(i = 0;i<n_blocks;i++)
			{
				cout<<"\n::";
				cout<<"\t";
				cout<<block[i].getNo();
				cout<<"\t\t";
				cout<<block[i].getSize();
				cout<<"\t\t";
				cout<<block[i].getStatus();
				
			}
			
		}
		void displayProcess()
		{
			cout<<"\n\n";
			cout<<"\tPROCESS NO\tREQUIREMENT(BYTES)\tSTATUS\n";
			for(i = 0;i<n_process;i++)
			{
				cout<<"\n::";				
				cout<<"\t";
				cout<<process[i].getPID();
				cout<<"\t\t";
				cout<<process[i].getReq();
				cout<<"\t\t\t";
				cout<<process[i].getAllocation();
				cout<<" ";
				if(process[i].getBlock() > 0)
				{
					cout<<" BLOCK "<<process[i].getBlock();
				}
				
			}
		}
void getInput()
{	
getBlocks();
getProcess();
assignMemory();
}

void assignMemory()
{
	int t_req = 0, t_size = 0, min = 0, comp = 0, pos;
	for(i=0;i<n_process;i++)
	{
		
		t_req = process[i].getReq();
		min = -1;
		pos = -1;
		for(j=0;j<n_blocks;j++)	//this loop finds the block no with minimum wastage after allocating process i
		{
			if(!block[j].isOccupied())	
			{
			comp = block[j].getSize() - t_req;
			if(comp>0)		//checks whether the block has enough memory or not
			{
			if(min == -1)		
				min = comp;

			if(comp==0 || min>=comp)		//if the block size is equal to memory req
			{
				min = comp;
				pos = j;
			}

			}
}		}
	//	cout<<"\ni: "<<i<<" pos: "<<pos;
		if(!block[pos].isOccupied())		//allocates the process i to block at position pos
		{
			process[i].setBlock(block[pos].getNo());
			process[i].setAllocation(true);
			block[pos].setStatus(true);
		}

t_req = t_size = 0;	
	}
	}


};
int main()
{
BestFit obj;
obj.getInput();
obj.displayBlocks();
obj.displayProcess();
return 0;	
}
