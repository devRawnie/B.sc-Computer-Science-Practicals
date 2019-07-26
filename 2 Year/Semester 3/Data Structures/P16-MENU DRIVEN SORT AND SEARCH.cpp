#include<iostream>
using namespace std;
class ARRAY{
	public:
		int* arr;
		int size, i;
		ARRAY()
		{
			arr = 0;
			size = 0;
		}
		ARRAY(int s)
		{
			size = s;
			arr = new int[size];
		}
		~ARRAY()
		{
			delete[] arr;
		}
		void getInput()
		{
			cout<<"\n\n";
			if(size==0)
			{
				cout<<"\nEnter the size of the ARRAY: ";
				cin>>size;
				arr = new int[size];
			}
			cout<<"\n Enter the elements of the ARRAY: ";
			for(i=0;i<size;i++)
			{
				cout<<"\narr["<<i+1<<"] : ";
				cin>>arr[i];
			}
		}
		void displayARRAY()
		{
			cout<<"\n\n";
			if(size>0)
			{
			
			for(i=0;i<size;i++)
			{
				cout<<arr[i]<<" ";		
			}
		}
		}
};


/********************************************************************************************************************************************/

void linearSearch()
{
	int ele,i, pos=-1;
	ARRAY ob;
	ob.getInput();
	cout<<"\nEnter the element to search for: ";
	cin>>ele;
	for(i=0;i<ob.size;i++)
	{
		if(ob.arr[i] == ele)
			{
				pos = i+1;
				break;
			}
	}
	if(pos>0)
		cout<<"\nElement found at pos: "<<pos;
	else
		cout<<"\nElement not found.";

}


/********************************************************************************************************************************************/

void binarySearch()
{
	int beg, end, mid = 0, ele,i, pos=-1;
	ARRAY ob;
	ob.getInput();
	cout<<"\nEnter the element to search for: ";
	cin>>ele;
	beg = 0;
	end = ob.size-1;
	while(beg<=end)
	{
		mid = (beg + end)/2;
	//	cout<<"\nmid "<<mid;
		if(ob.arr[mid] == ele)
			{
				pos = mid;
				break;
			}
		if( ele < ob.arr[mid] )
			{
			//cout<<"\nob.ob.arr[mid] < ele";
			end = mid - 1;
			}
		if(ele > ob.arr[mid])
			{
			//cout<<"\nob.ob.arr[mid] > ele";
			beg = mid + 1;
			}
	}
	//cout<<"pos "<<pos;

	if(pos>0)
		cout<<"\nElement found at pos: "<<pos+1;
	else
		cout<<"\nElement not found.";

}

/********************************************************************************************************************************************/

void selectionSort()
{
	cout<<"SELECTION SORT";	
	ARRAY ob;
	ob.getInput();
	int i, j, min, size, temp;
	size = ob.size;
	for(i=0;i<size;i++)
	{
		min = i;
		for(j=i+1;j<size;j++)
		{
			if(ob.arr[j] < ob.arr[min])
			{
				//cout<<"\n::";
				min = j;
			}
		}
		temp = ob.arr[min];
		ob.arr[min] = ob.arr[i];
		ob.arr[i] = temp;
	}
	cout<<"\nSORTED ARRAY IS: ";
ob.displayARRAY();
}

/********************************************************************************************************************************************/

void bubbleSort()
{
	cout<<"BUBBLE SORT";
	ARRAY ob;
	ob.getInput();
	int i, j, min, size, temp;
	size = ob.size;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(ob.arr[j] > ob.arr[j+1])
			{
		temp = ob.arr[j];
		ob.arr[j] = ob.arr[j+1];
		ob.arr[j+1] = temp;
			}
			
		}
		
	}
	cout<<"\nSORTED ARRAY IS: ";
ob.displayARRAY();
}

/********************************************************************************************************************************************/

void insertionSort()
{	
	cout<<"INSERTION SORT";
	ARRAY ob;
	ob.getInput();
	int i, j, temp,size;
	size = ob.size;
	for(i=1;i<size;i++)
	{
	temp = ob.arr[i];
	j = i-1;
	while(j>=0 && ob.arr[j] > temp)
	{
		ob.arr[j+1] = ob.arr[j];
		j--;
			}
			ob.arr[j+1] = temp;
	 
	}
		
	cout<<"\nSORTED ARRAY IS: ";	
ob.displayARRAY();
}

/********************************************************************************************************************************************/

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 	

void quickSortDriver()
{
	cout<<"\nQUICKSORT";
ARRAY ob;
ob.getInput();
int size = ob.size;

int array[size];
for(int i=0;i<size;i++)
{
	array[i] = ob.arr[i];
}
quickSort(array,0,size-1);
cout<<" SORTED ARRAY IS: ";
for(int i=0;i<size;i++)
{
	cout<<array[i]<<" ";
	}	
}

/********************************************************************************************************************************************/
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 


void mergeSortDriver()
{
	cout<<"\nMERGE SORT";
	ARRAY ob;
	ob.getInput();
	int size = ob.size;
	int array[size];
	for(int i=0;i<size;i++)
	{
		array[i] = ob.arr[i];
	}
	
	mergeSort(array, 0 , size-1);
	cout<<"\nSORTED ARRAY IS: ";
	for(int i=0;i<size;i++)
		cout<<array[i]<<" ";
}

int main()
{
	int ch;
		beg:
		cout<<"\n\nEnter your choice: ";	
		cout<<"\n1.Linear Search\t2.Binary Search\n3.Bubble Sort";
		cout<<"\t4.Selection Sort\t5.Insertion Sort\t6.Quick Sort";
		cout<<"\t7.Merge Sort\n8.EXIT\n:->";
		cin>>ch;
		switch(ch)
		{
			case 1:	linearSearch();
					break;
			case 2:	binarySearch();
					break;
			case 3:	bubbleSort();
					break;
			case 4:	selectionSort();
					break;
			case 5:	insertionSort();
					break;
			case 6:	quickSortDriver();
					break;
			case 7:	mergeSortDriver();
					break;								
			case 8: return 0;
			default: cout<<"Wrong choice, try again";
		}
		goto beg;
mergeSortDriver();
		return 0;
}
