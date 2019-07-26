/*
	Name: sjf pre-emptive
	Copyright: 
	Author: 
	Date: 24/09/18 13:38
	Description: 
*/
#include<iostream>
using namespace std;
 class node{
 	public:
	 int mpid,mat,mbt,mwt, btcopy;
 	node *next, *prev; 
 
 	node()
 	{
 		mpid = mat = mbt = mwt = btcopy =  0;
 		prev = next = 0;
	 }
 	node(int pid, int at, int bt,int wt=0)
 	{ 	mpid = pid;
 		mat = at;
 		mbt = bt;
 		btcopy = mbt;
 		mwt = wt;
 		prev = 0;
 		next = 0;
	 }
 };
 class SJF{
 	float atat,awt, n;
 	public:
	node *head, *tail;
 	SJF()
 	{
 		n = 0;
 		head = tail = 0;
	 }
	 void getNProcess()
	 {
	 	cout<<"Enter no of processes: ";
	 	cin>>n;
	 }
 	void insertBeg(node *p)
 	{
 		if(head==0)
 			head = tail = p;
 		else
 		{ 
   		  head->prev = p;
 		  p->next = head;
 		  head = p;
		 }
	 }
 	void insertEnd(node *p)
 	{
 		if(head == 0)
 			head = tail = p;
 		else
 		{
		 tail->next = p;
		 p->prev = tail;
		 tail = p;
		 }
	 }

 	void insertBefore(node *p, node *before)
 	{
		before->prev->next = p;
	    p->prev = before->prev;
		p->next = before;
		before->prev = p; 
	 }
	 
	void display()
	{
		node *q;
		q = head;
		cout<<"\nPID\tBurst Time.\tArrival Time\tWaiting Time\n";
		while(q!=0)
	{
		cout<<q->mpid<<"\t\t"<<q->mbt<<"\t\t"<<q->mat<<"\t\t"<<q->mwt<<"\t\t\n";
		q=q->next;
	}
	cout<<endl;
	 } 

void insertOrder(node *insert)
{
	if(head==0)
		head = tail = insert;
	else if(insert->mat <= head->mat)
		this->insertBeg(insert);
	else if(insert->mat >= tail->mat)
		this->insertEnd(insert);
	else{
		node *q = head;
		while(q->mat <= insert->mat)
		{
			q = q->next;
		}
		this->insertBefore(insert, q);
	}
}
void swap(node *p)
{
	int temp;
	temp = head->mpid;
	head->mpid = p->mpid;
	p->mpid = temp;
	
		temp = head->mat;
	head->mat = p->mat;
	p->mat = temp;
	
		temp = head->mbt;
	head->mbt = p->mbt;
	p->mbt = temp;
	
		temp = head->mwt;
	head->mwt = p->mwt;
	p->mwt = temp;
}
void delete_at_start()
{
	node *p=head;
	if(head==tail)
	head=tail=0;
	else
	head=p->next;
	delete(p);
	
}
void calculateATAT()
{
	atat = awt = 0;
	int btsum =0, wtsum = 0;
	node *q = head;
	while(q!=0)
	{
		btsum += q->btcopy;
		wtsum += q->mwt;
		q = q->next;
	}
	atat = (btsum + wtsum) / n;
	awt = wtsum / n;
	
}
void runp()
{
	SJF obj;
	node *q = head->next;
	node *p=head, *r=0;
	int t=0,minbt=head->mbt;
										//root loop
	while(tail->mbt!=0)
	{
		q=head->next,p=head,r=0;
		if(t - head->mat >= 0) 			//checks if head has arrived
      {	
								      	//cout<<"\ninside if";
			
			while(q!=0 && t-q->mat>=0)	//checks how many nodes have arrived
			{ 
									    //cout<<"\ninside node arr"<<t;
			    q=q->next;
			  							//  cout<<"\n q bhad mai ja";
			}
										//cout<<"\n AA GYA TU BAHAR ";
			while(p!=q)					//determines which nodes out of arrived notes has the minimum burst time
			{
										//	cout<<"\nInside while";
				if(minbt>p->mbt)
				{
						minbt=p->mbt;
						r=p;
				}
										//	cout<<"\n minbt"<<minbt;
				p=p->next;
			}
			
			if(r!=0) 					// if no  node has arrived
			
			{							//swaps head node with the node having minimum burst time
			swap(r);
										//cout<<"\nSwapping ho gyi";
			
			   p = head->next;
		    while(p!=r->next)			//increases the waiting time for nodes after head till the node having minimum burst time
			 {
									 	//cout<<"\nwaiting time";
				    p->mwt++;
			    	p = p->next;
			 }
			 
		    }
		    
		    head->mbt--;
			if(head->mbt==0& head!=tail)
			{
			   node*p= new node(head->mpid,head->mat,head->mbt,head->mwt);	
			   obj.insertEnd(p);
			  delete_at_start();
			  minbt=head->mbt;
			}

			cout<<"\n::t  "<<t;
			display();
	}
		t++;
	}
	head->mwt++;
        
		obj.insertEnd(head);
		obj.sort_list();
		obj.display();
		cout<<"\nAverage Turn Around Time : "<<atat;
		cout<<"\nAverage Waiting Time : "<<awt;
}
								//sorts the completed processes according to their pid
void sort_list()
{ 
node *q = head;
node *t;
int temp;
while(q->next!=0)
{
	t=q->next;
	while(t!=0)
	{
	if( q->mpid > t->mpid )
	{
			temp = q->mpid;
	q->mpid = t->mpid;
	t->mpid = temp;
	
		temp = q->mat;
	q->mat = t->mat;
	t->mat = temp;
	
		temp = q->mbt;
	q->mbt = t->mbt;
	t->mbt = temp;
	
		temp = q->mwt;
	q->mwt = t->mwt;
	t->mwt = temp;
	}
	t = t->next;
}
q = q->next;
}
}
 };
 int main()
 {
 	SJF ob;
 	ob.getNProcess();
ob.insertOrder(new node(1,1,3));
ob.insertOrder(new node(2,2,1));
ob.insertOrder(new node(3,3,2));
ob.insertOrder(new node(4,4,4));
ob.insertOrder(new node(5,8,3));
ob.display();
ob.runp();
//ob.display();
	 return 0;
 	
 }
