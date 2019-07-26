#ifndef _SORTING_ALGO_H
#define	_SORTING_ALGO_H
#include<iostream>
#include<vector>
#include "sort_template.h"
using namespace std;
class bubble_sort : public generic_sort{
	private: const char* a_name = "bubbleSortArrays.txt";
			 const char* c_name = "bubbleSortComp.txt";
			 bool hasPassList = true;
	public: 
	bubble_sort(){
		compList.clear();
		sizeList.clear();
		passList.clear();
		list.clear();	}
	
	void init_sort(int list_size){
		bool sorted = false;	
		this->create_list(list_size, this->a_name);
		for(int i=0 ; i<list.size()-1;i++)
			{	sorted = true;
				for(int j=0; j < list.size() - i -1; j++)
					{	incr_comp();
						if(list[j] > list[j+1])
						{	swap_num(list[j], list[j+1]);	
							sorted = false;		}	}
					if(sorted)	break;
					else	this->incr_pass();	}
		compList.push_back(this->get_no_of_comp());	
		passList.push_back(this->get_no_of_passes());	}
	
	void write_to_file()
	{	write_comparisons(c_name, hasPassList);		}
};

class selection_sort: public generic_sort{
	private: const char* a_name = "selectionSortArrays.txt";
			 const char* c_name = "selectionSortComp.txt";
			 bool hasPassList = true;
	public:
		selection_sort(){	
		compList.clear();
		sizeList.clear();
		passList.clear();
		list.clear();	}
		
		void init_sort(int list_size)
		{	int min;
			this->create_list(list_size, a_name);
			for(int i=0;i<list.size()-1;i++)
			{	min = i;
				for(int j=i+1;j<list.size();j++)
					{	if(list[j] < list[min])
							min = j;		
					this->incr_comp();		}

				swap_num(list[i], list[min]);
				this->incr_pass();		}
			compList.push_back(this->get_no_of_comp());
			passList.push_back(this->get_no_of_passes());	}

	void write_to_file()
	{	write_comparisons(c_name, hasPassList);		}	
};

class insertion_sort: public generic_sort{
	private: const char* a_name = "insertionSortArrays.txt";
			 const char* c_name = "insertionSortComp.txt";
			 bool hasPassList = true;	
	public: 
		insertion_sort(){	
		compList.clear();
		sizeList.clear();
		passList.clear();
		list.clear();	}
	
		void init_sort(int list_size)
		{	int key, j;
			this->create_list(list_size, a_name);
			for(int i=1;i<list.size(); i++)
			{	key = list[i];
				j	= i-1;
				while(j>=0 && list[j] > key)
				{	list[j+1] = list[j];
					j = j-1;
					this->incr_comp();	}
				list[j+1] = key;
				this->incr_pass();	}
			compList.push_back(this->get_no_of_comp());
			passList.push_back(this->get_no_of_passes());
		}
	void write_to_file()
	{	write_comparisons(c_name, hasPassList);	}
};

class merge_sort: public generic_sort{
	private: const char* a_name = "mergeSortArrays.txt";
			 const char* c_name = "mergeSortComp.txt";
			 bool hasPassList = false;	
	public:
		merge_sort(){	
		compList.clear();
		sizeList.clear();
		passList.clear();
		list.clear();	}
	
		void sort_driver(vector<int> &arr, int l, int r)		
		{	if( l < r )
			{	int m = (l+r)/2;
				sort_driver(arr, l, m);	
				sort_driver(arr, m+1, r);
				merge(arr, l, m, r);	}
		}
		void merge(vector<int> &arr, int l, int m, int r)
		{	int i, j , k;
			
			int n1 = m - l + 1;
			int n2 = r - m;
			int A[n1], B[n2];	
			for(i=0;i<n1;i++)					
				A[i] = arr[l+i];
			for(j=0;j<n2;j++)
				B[j] = arr[m + j + 1];
			i = j = 0;							
			k = l;
			while( i < n1 && j < n2)
			{	if(A[i] <= B[j])
				{	arr[k] = A[i];		i++;	}
				else
				{	arr[k] = B[j];		j++;	}
				k++;
				incr_comp();				
			}
		
			while(i<n1)				
			{	arr[k] = A[i];
				i++;
				k++;	}				
			
			while(j<n2)
			{	arr[k] = B[j];
				j++;
				k++;	}
		}
		void init_sort(int list_size)
		{
			this->create_list(list_size, a_name);
			this->sort_driver(this->list, 0, list.size() -1 );
			compList.push_back(get_no_of_comp());
		}
	void write_to_file()
	{	write_comparisons(c_name, hasPassList);		}
};

class quick_sort: public generic_sort{
	private: const char* a_name = "quickSortArrays.txt";
			 const char* c_name = "quickSortComp.txt";
			 bool hasPassList = false;
	public:	
		quick_sort()
	{	compList.clear();
		sizeList.clear();
		list.clear();	}
		int partition(vector<int> &arr, int low, int high)
		{	int pivot = arr[high];			
			int i = low - 1;				
			for(int j=low; j <= high - 1; j++)
			{	incr_comp();		
				if(arr[j] <= pivot)
				{	i++;
					swap_num(arr[i], arr[j]);	}
			}	
			swap_num(arr[i+1], arr[high]);
			return i+1;		}
	
		void sort_driver(vector<int> &arr, int low, int high)
		{		if(low < high)
			{
				int pi = partition(arr, low, high);
				sort_driver(arr, low, pi - 1);
				sort_driver(arr, pi, high);				}
		}
		void init_sort(int list_size)
		{	this->create_list(list_size, a_name);
			this->sort_driver(list, 0, list.size() - 1);
			compList.push_back(get_no_of_comp());	}	
	void write_to_file()
	{	write_comparisons(c_name, hasPassList);	}
};

#endif
