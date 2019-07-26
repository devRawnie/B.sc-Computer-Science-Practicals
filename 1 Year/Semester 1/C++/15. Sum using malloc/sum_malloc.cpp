#include <iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int num, i, *ptr, sum = 0;

    cout<<"Enter number of elements: ";
    cin>>num;

    ptr = (int*) malloc(num * sizeof(int));  //memory allocated using malloc
    if(ptr == NULL)                     
    {
        cout<<"Error! memory not allocated.";
        exit(0);
    }

    cout<<"Enter elements of array: ";
    for(i = 0; i < num; ++i)
    {
        cin>> *(ptr + i);
        sum =sum + *(ptr + i);
    }

    cout<<"Sum of the elements of the array is: "<<sum;
    delete ptr;
    return 0;
}
