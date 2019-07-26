#include<iostream>
#include<stdio.h>
using namespace std;
int comparisons;
//merge sort does not pass through a list. it instead breaks the list into two and recursively sorts both parts
//int passes;
void merge(int arr[], int l , int m , int r){
	int n1 = m - l + 1;
	int n2 = r-m;
	int a1[n1], a2[n2];
	for(int i = 0 ; i < n1; i++)
		a1[i] = arr[l+i];
	for(int i = 0 ; i < n2; i++)
		a2[i] = m + i + 1;
	int i=0, j = 0;
	int k = l;
	while(i < n1 && j < n2){
		if(a1[i] < a2[j])
		{
			arr[k] = a1[i];
			k++;
			i++;
		}else{
			arr[k] = a2[j];
			k++; 
			j++;
		}
		++comparisons;
	}
	while(i < n1){
		arr[k++] = a1[i++];
	}
	while( j < n2){
		arr[k++] = a2[j++];
	}
}
void merge_sort(int arr[], int l , int r){
	if(l < r){
		int mid = (l+r)/2;
		merge_sort(arr, l , mid);
		merge_sort(arr, mid+1, r);
		merge(arr, l , mid, r);
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
	merge_sort(arr, 0, size-1);
	display(arr, size);
	return 0;
}

