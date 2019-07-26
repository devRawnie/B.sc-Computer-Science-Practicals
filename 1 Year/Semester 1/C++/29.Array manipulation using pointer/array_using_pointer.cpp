#include <iostream>
using namespace std;
int main()
{
   int *a,i,j,tmp,n;
 	cout<<"\n Sort an array using pointer :\n";
 	cout<<"Enter the number of elements in the array\n";
 	cin>>n;
	cout<<"Enter the elements of array\n \n";   
   for(i=0;i<n;i++)
      {
	  
	  cin>>*(a+i);
	  }   
   for(i=0;i<n;i++)
   {
    for(j=i+1;j<n;j++)
    {
       if( *(a+i) > *(a+j))
       {
      tmp = *(a+i);
      *(a+i) = *(a+j);
      *(a+j) = tmp;
       }
    }
   }
   cout<<"\nThe array in ascending order is: ";
   for(i=0;i<n;i++)
      {
	  cout<<*(a+i)<<" ";
	  }         
	cout<<"\nThe array in descending order is: ";
   for(i=n-1;i>=0;i--)
      {
	  cout<<*(a+i)<<" ";
	  }         
	  
return 0;
}

