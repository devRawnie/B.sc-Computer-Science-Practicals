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
	 int mpid,mat,mbt,mwt,  btcopy;
 	node *next, *prev; 
 
 	node()
 	{
 		mpid = mat = mbt = mwt = btcopy = 0;
 		prev = next = 0;
	 }
 	node(int pid, int at, int bt,int wt=0)
 	{ 	mpid = pid;
 		mat = at;
 		mbt = btcopy = bt; 		 		
		//cout<<"\nbtcopy "<<btcopy;
		mwt = wt;
 		prev = 0;
 		next = 0;
	 }
 };
 int *arr;
 class SJF{
 	float atat,awt;
 	int n;
 	public:
	node *head, *tail;
 	SJF(int num)
 	{
 		n = num;
 		cout<<"array done";
 		head = tail = 0;
	 }
	 SJF()
	 {
	 	head = tail = 0;
	 }
	 ~SJF()
	 {
	 	delete[] arr;
	 }
//	 void getNProcess(int num)
//	 {
//	 	n=num;
//	 }
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
		int i = 0;
		cout<<"\nPID\tBurst Time.\tArrival Time\tWaiting Time\n";
		while(q!=0)
	{
		cout<<q->mpid<<"\t\t"<<arr[i]<<"\t\t"<<q->mat<<"\t\t"<<q->mwt<<"\t\t\n";
		i++;
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
void calculate_time(SJF temp)
{
	atat = awt = 0;
	int btsum =0, wtsum = 0, i=0;
	node *q = temp.head;
	while(q!=0)				//btcopy is not displaying the correct value
	{
		cout<<endl<<q->mpid<<"  btcopy "<<arr[i];
		btsum += arr[i] + q->mwt;
		wtsum += q->mwt;
		q = q->next;
		i++;
	}
	atat =(float) btsum / n;
	awt = (float) wtsum / n;
	cout<<"exit";
}
void runp()
{
	SJF obj;
	node *q = head->next;
	node *p=head, *r=0;
	int flag;
	int t=0,minbt=head->mbt;
	while(tail->mbt!=0)
	{
		
		q=head->next,p=head,r=0;
		if(t - head->mat >= 0) 			//checks if head has arrived
      {		                            //cout<<"\ninside if";
			
			while(q!=0 && t-q->mat>=0)	//checks how many nodes have arrived
			{ 
									    //cout<<"\ninside node arr"<<t;
			    q=q->next;
			  							//  cout<<"\n q bhad mai ja";
			}
			flag=0;							//cout<<"\n AA GYA TU BAHAR ";
			while(p!=q)					//determines which nodes out of arrived notes has the minimum burst time
			{
										//	cout<<"\nInside while";
				if(minbt>=p->mbt)
				{
					    if(p!=head|head==tail)
					    flag=1;
						minbt=p->mbt;
						r=p;
				}
										//	cout<<"\n minbt"<<minbt;
				p=p->next;
			}
			if(r!=0&flag==1) 					// if no  node has arrived
			{	
									//swaps head node with the node having minimum burst time
		       //cout<<"\nSwapping ho gyi";
			     swap(r);
			     p = head->next;
		         while(p!=r->next)			//increases the waiting time for nodes after head till the node having minimum burst time
			     {				        	//cout<<"\nwaiting time";
				        p->mwt++;
			        	p = p->next;
			     }
		    }
		    else if(flag==0)
			   {
			    p = head->next;
		         while(p!=q)			//increases the waiting time for nodes after head till the node having minimum burst time
			     {				        	//cout<<"\nwaiting time";
				        p->mwt++;
			        	p = p->next;
			     }
			   }
			 
		    
		    head->mbt--;
			if(head->mbt==0& head!=tail)
			{
			   node*p= new node(head->mpid,head->mat,head->mbt,head->mwt);	
			   obj.insertOrder(p);
				delete_at_start();
			   minbt=head->mbt;
			}

		
	}
		t++;
}
		obj.insertOrder(head);
		calculate_time(obj);
	//	obj.display();
		cout<<"\nAverage Turn Around Time : "<<atat;
		cout<<"\nAverage Waiting Time : "<<awt;
		cout<<"\nexit runp";
}
void formArray()
{
node *q = head;
int i = 0;
while(q!=0)
{
	arr[i] = q->mbt;
	cout<<"\nfirst while";
	q = q->next;
	i++; 
	}	
	q = head;
	i = 0;
	while(q!=0)
	{
		cout<<"\nbt arr: "<<arr[i];
		i++;
		q = q->next;
	}
}
 };
 int main()
 {
 	int n,pid,burst_time,arrival_time;
 	cout<<"\nEnter the number of processes :: ";
 	cin>>n;
 	SJF ob(n);
 	arr = new int[n];
 	for(int i=0;i<n;i++)
 	{
 		cout<<"\nEnter process Pid for P"<<i+1<<" :: ";
		cin>>pid;
		cout<<"\nEnter process Arrival time for P"<<i+1<<" :: ";
		cin>>arrival_time;	
		cout<<"\nEnter process Burst time for P"<<i+1<<" :: ";
 	    cin>>burst_time;
 	    ob.insertOrder(new node(pid,arrival_time,burst_time));
	}
	cout<<"here";
	ob.formArray();
//    ob.insertOrder(new node(1,3,1));
//    ob.insertOrder(new node(2,1,5));
//    ob.insertOrder(new node(3,3,2));
//    ob.insertOrder(new node(4,4,4));
//    ob.insertOrder(new node(5,8,3));
    ob.display();
    ob.runp();
	//ob.display();
	delete [] arr;
	cout<<"last statement";
	 return 0;
 	
 }
