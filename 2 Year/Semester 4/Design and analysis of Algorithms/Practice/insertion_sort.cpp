#include<iostream>
#include<stdio.h>
using namespace std;
int comparisons;
int passes;
void insertion_sort(int arr[], int size){
	
	int key, j;
	for(int i = 1 ; i < size ;i++){
		key = arr[i];
		j = i-1;
		while(j >= 0 && arr[j] > key)	
		{
			++comparisons;
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
		++passes;
	}
}
void display(int arr[], int size){
	cout<<"Sorted array: ";
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
	insertion_sort(arr, size);
	display(arr, size);
	return 0;
}

