#include<iostream>
#include<conio.h>
using namespace std;
class diagmat
{
	   int *a;
	   int size;
	   public:
	   	diagmat(int b)
	   	{
	   	          size=b;
				  a=new int[size];	
				  for(int i=0;i<size;i++)
				  a[i]=0;
		}
		void set(int i,int j,int x)
		{
			     if((i<0 || j<0) || (i>size || j>size))
			     cout<<"out of bounds"<<endl;
			     else if(i!=j && x!=0)
			     cout<<"it is not a diagonal element"<<endl;
			     else if(i==j)
			     a[i-1]=x;
		}
		int get(int i,int j)
		{
			 if((i<0 && j<0) || (i>size && j>size))
			          return -1;
			 else if(i!=j)
			     return 0;
			     else if(i==j)
			     return a[i-1];
		}
		void display()
		{
			 for(int i=0;i<size;i++)
	    	{ 
	  	   		cout<<a[i]<<" ";
	   		} 
		}
};

 
class lowertri_m
  {
  	int* a;
  	int n;
  	 public:
  	 	lowertri_m(int num)
  	 	 {
  	 	 	a=new int[(num*(num+1))/2];
  	 	 	n=((num+1)*num)/2;
			}
		
		void set(int i,int j,int elem)
		 {
		 	if(i<1 || j<1 || i>n || j>n)
		 		cout<<"matrix index out of bound";
		 	else if(i<j && elem!=0)
		 	 	cout<<"the matrix is a lower triangular matrix";
		 	else 
		 		a[((i-1)*i)/2+(j-1)]=elem;
		 }
		 int get(int i,int j)
		  {
		  	if(i<1 || j<1 || i>n || j>n)
		 		cout<<"matrix index out of bound";
		  	else if(i<j)
		 	 	return(0);
			else 
				return(a[((i-1)*i)/2+(j-1)]);
		  }
  };
  
  class uppertri_m
  {
  	int* a;
  	int n;
  	 public:
  	 	uppertri_m(int num)
  	 	 {
  	 	 	a=new int[(num*(num+1))/2];
  	 	 	n=((num+1)*num)/2;
			}
		
		void set(int i,int j,int elem)
		 {
		 	if(i<1 || j<1 || i>n || j>n)
		 		cout<<"matrix index out of bound";
		 	else if(i>j && elem!=0)
		 	 	cout<<"the matrix is a upper triangular matrix";
		 	else 
		 		a[(n * i) + j - ((i * (i+1)) / 2)]=elem;
		 }
		 int get(int i,int j)
		  {
		  	if(i<1 || j<1 || i>n || j>n)
		 		cout<<"matrix index out of bound";
		  	else if(i>j)
		 	 	return(0);
			else 
				return(a[(n * i) + j - ((i * (i+1)) / 2)]);
		  }
  };
  
  class sym_m
  {
  	int* a;
  	int n;
  	 public:
  	 	sym_m(int num)
  	 	 {
  	 	 	a=new int[(num*(num+1))/2];
  	 	 	n=((num+1)*num)/2;
			}
		
		void set(int i,int j,int elem)
		 {
		 	if(i<1 || j<1 || i>n || j>n)
		 		cout<<"matrix index out of bound";
		 	else if(i>=j )
		 		a[((i-1)*i)/2+(j-1)]=elem;
		 }
		 int get(int i,int j)
		  {
		  	if(i<1 || j<1 || i>n || j>n)
		 		cout<<"matrix index out of bound";
		  	else if(i<j)
		 	 	return(get(j,i));
			else 
				return(	a[((i-1)*i)/2+(j-1)]);
		  }
  };
 int main()
  {
  	int n,i,j,c,o,d;
  	char ch;
	  start:  	
		cout<<"\nChoose from the following: ";
  	 	cout<<"\n1.Diagonal matrix";
  	 	cout<<"\n2.Lower triangular matrix";
  	 	cout<<"\n3.Upper triangular matrix";
  	 	cout<<"\n4.Symmetric matix ";
  	 	cout<<"\n5. Quit\n:: ";
  	 	cin>>d;
  		
  	 if(d==1)
  	  {
		
  	 	  	cout<<"\nEnter the order of the diagonal matrix:";
  	 	 	cin>>o;
  	 	 	diagmat diamat(o);
	do
  	 {
  	 	cout<<"\n Choose from the following: ";
  	 	cout<<"\n1.Enter the elements of the matrix";
  	 	cout<<"\n2.Get a particular element from the matrix";
  	 	cout<<"\n3.Display the matrix";
  	 	cout<<"\nEnter your choice:";
  	 	cin>>c;
  	 	switch(c)
  	 	 {

  	 	 	case 1:
  	 	 		for(int h=1;h<=o;h++)
  	 	 		 {
  	 	 		 	for(int g=1;g<=o;g++)
  	 	 		 	 {
  	 	 		 	 	cout<<"Enter the ("<<h<<","<<g<<") element:";
  	 	 		 	 	cin>>n;
  	 	 		 	 	diamat.set(h,g,n);
						  }
					 }
				break;
			case 2:
				cout<<"Enter the position of the element to be printed: ";
				cout<<"\ni=";
				cin>>i;
				cout<<"j=";
				cin>>j;
				n=diamat.get(i,j);
				cout<<"The element at ("<<i<<","<<j<<") is "<<n;
				break;
			case 3:
				cout<<"The matrix is\n";
				for(int h=1;h<=o;h++)
				 {
				 	for(int g=1;g<=o;g++)
				 	  cout<<diamat.get(h,g)<<"	";
				 	  cout<<endl;
				 }
			}
			cout<<"Do you want to continue(y/n)";
			cin>>ch;
	   }while(ch=='y');
}
	   
	if(d==3)
	 {
	 
  	cout<<"\nEnter the order of the  matrix:";
  	cin>>o;
 	uppertri_m diamat1(o);
	do
  	 {
  	 	cout<<"\nChoose from the following: ";
  	 	cout<<"\n1.Enter the elements of the matrix";
  	 	cout<<"\n2.Get a particular element from the matrix";
  	 	cout<<"\n3.Display the matrix";
  	 	cout<<"\nEnter your choice: ";
  	 	cin>>c;
  	 	switch(c)
  	 	 {

  	 	 	case 1:
  	 	 		for(int h=1;h<=o;h++)
  	 	 		 {
  	 	 		 	for(int g=1;g<=o;g++)
  	 	 		 	 {
  	 	 		 	 	cout<<"Enter the ("<<h<<","<<g<<") element:";
  	 	 		 	 	cin>>n;
  	 	 		 	 	diamat1.set(h,g,n);
						  }
					 }
				break;
			case 2:
				cout<<"Enter the position of the element to be printed: ";
				cout<<"\ni=";
				cin>>i;
				cout<<"j=";
				cin>>j;
				n=diamat1.get(i,j);
				cout<<"The element at ("<<i<<","<<j<<") is "<<n;
				break;
			case 3:
				cout<<"The matrix is\n";
				for(int h=1;h<=o;h++)
				 {
				 	for(int g=1;g<=o;g++)
				 	  cout<<diamat1.get(h,g)<<"	";
				 	  cout<<endl;
				 }
			}
			cout<<"do you want to continue(y/n)";
			cin>>ch;
	   }while(ch=='y');
}

	if(d==2)
	 {
	 
  	cout<<"\nEnter the order of the  matrix:";
  	cin>>o;
 	lowertri_m diamat1(o);
	do
  	 {
  	 	cout<<"\nChoose from the following: ";
  	 	cout<<"\n1.Enter the elements of the matrix";
  	 	cout<<"\n2.Get a particular element from the matrix";
  	 	cout<<"\n3.Display the matrix";
  	 	cout<<"\nenter your choice:";
  	 	cin>>c;
  	 	switch(c)
  	 	 {

  	 	 	case 1:
  	 	 		for(int h=1;h<=o;h++)
  	 	 		 {
  	 	 		 	for(int g=1;g<=o;g++)
  	 	 		 	 {
  	 	 		 	 	cout<<"Enter the ("<<h<<","<<g<<") element:";
  	 	 		 	 	cin>>n;
  	 	 		 	 	diamat1.set(h,g,n);
						  }
					 }
				break;
			case 2:
				cout<<"Enter the position of the element to be printed: ";
				cout<<"\ni=";
				cin>>i;
				cout<<"j=";
				cin>>j;
				n=diamat1.get(i,j);
				cout<<"The element at ("<<i<<","<<j<<") is "<<n;
				break;
			case 3:
				cout<<"The matrix is\n";
				for(int h=1;h<=o;h++)
				 {
				 	for(int g=1;g<=o;g++)
				 	  cout<<diamat1.get(h,g)<<"	";
				 	  cout<<endl;
				 }
			}
			cout<<"Do you want to continue(y/n)";
			cin>>ch;
	   }while(ch=='y');
}

	if(d==4)
	 {
	 
  	cout<<"\nEnter the order of the  matrix:";
  	cin>>o;
 	sym_m diamat1(o);
	do
  	 {
  	 	cout<<"\nChoose from the following: ";
  	 	cout<<"\n1.Enter the elements of the matrix";
  	 	cout<<"\n2.Get a particular element from the matrix";
  	 	cout<<"\n3.Display the matrix";
  	 	cout<<"\nenter your choice:";
  	 	cin>>c;
  	 	switch(c)
  	 	 {

  	 	 	case 1:
  	 	 		for(int h=1;h<=o;h++)
  	 	 		 {
  	 	 		 	for(int g=1;g<=o;g++)
  	 	 		 	 {
  	 
	   	 		 	 	cout<<"enter the ("<<h<<","<<g<<") element:";
  	 	 		 	 	cin>>n;
  	 	 		 	 	diamat1.set(h,g,n);
						  }
					 }
				break;
			case 2:
				cout<<"Enter the cordinates of the element to be print";
				cout<<"\ni=";
				cin>>i;
				cout<<"j=";
				cin>>j;
				n=diamat1.get(i,j);
				cout<<"The element at ("<<i<<","<<j<<") is "<<n;
				break;
			case 3:
				cout<<"The matrix is\n";
				for(int h=1;h<=o;h++)
				 {
				 	for(int g=1;g<=o;g++)
				 	  cout<<diamat1.get(h,g)<<"	";
				 	  cout<<endl;
				 }
			}
			cout<<"do you want to continue(y/n)";
			cin>>ch;
	   }while(ch=='y');
}
if(d==5)
	return 0;
	
goto start;
	
	

return 0;
}

