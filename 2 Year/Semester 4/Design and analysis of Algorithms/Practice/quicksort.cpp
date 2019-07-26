#include<iostream>
#include<stdio.h>
using namespace std;
int comparisons = 0;
//quick sort does not pass through a list. it instead breaks the list into two parts, to the left and right of partition and recursively sorts both parts
//int passes;
int q_partition(int arr[], int l , int r){
	int i = l-1;
	int pivot = arr[r];
	for(int j = l; j < r; j++){
		//if an element is smaller than pivot then 
		if(arr[j] <= pivot){
			i++;
			swap(arr[i], arr[j]);
		}
		++comparisons;
	}
	//after all the elements uptil i are smaller than pivot and after i are larger than pivot. place pivot at its correct position
	swap(arr[i+1], arr[r]);
	return i+1;
}
void quicksort(int arr[], int l , int r){
	if(l < r){
	
		int p = q_partition(arr, l, r);
		quicksort(arr, l , p-1);
		quicksort(arr, p+1, r);
	}

}
void display(int arr[], int size){
	cout<<"Sorted array: ";
	for(int i = 0 ; i < size ;i++)
		cout<<arr[i]<<" ";
	
	printf("\nSize of array: %d\nNo of comparisons: %d", size, comparisons);
}
int main(){
	int size;
	cout<<"Enter the size of array: ";
	cin>>size;
	int arr[size];
	cout<<"Enter the elements of array:\n";
	for(int i = 0 ; i < size; i++)
		cin>>arr[i];
	quicksort(arr, 0, size-1);
	display(arr, size);
	return 0;
}

