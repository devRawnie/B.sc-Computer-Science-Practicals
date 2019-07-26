#include<iostream>
#include<stdio.h>
using namespace std;

int comparisons;
int passes;
void selection_sort(int arr[], int size){
	int minpos;
	for(int i = 0 ; i < size - 1 ;i++){
		minpos = i;
		for(int j = i+1 ; j < size; j++ )
		{
			++comparisons;
			if(arr[minpos] > arr[j])
				minpos = j;
		}
		swap(arr[i], arr[minpos]);
		++passes;
	}
}
void display(int arr[], int size){
	for(int i = 0 ; i < size ;i++)
		cout<<arr[i]<<" ";

	printf("\nSize of array: %d\nNo of passes: %d\nNo of comparisons: %d", size, passes, comparisons);
}
int main(){
	int size;
	cout<<"Enter the size of array: ";
	cin>>size;
	int arr[size];
	cout<<"Enter the elements of array:\n";
	for(int i = 0 ; i < size; i++)
		cin>>arr[i];
	selection_sort(arr, size);
	display(arr, size);
	return 0;
}

