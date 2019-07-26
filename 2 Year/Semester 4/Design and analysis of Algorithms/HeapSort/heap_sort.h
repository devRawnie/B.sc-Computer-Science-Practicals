#ifndef _HEAP_SORT_H
#define _HEAP_SORT_H
#include<iostream>
#include<vector>
#include "sort_template.h"
using namespace std;
class heap_sort : public generic_sort{	
		private: const char* a_name = "heapSortArrays.txt";
			 const char* c_name = "heapSortComp.txt";
			 bool hasPassList = false;
		public: 
		heap_sort()
		{	compList.clear();
			sizeList.clear();
			passList.clear();
			list.clear();	}
		void heapify(vector<int> &arr, int n, int i)
		{
			int largest = i;
			int l = 2*i + 1;
			int r = 2*i + 2;
			incr_comp();
			// If left child is larger than root 
    		if (l < n && arr[l] > arr[largest])
			      largest = l; 	 
  			incr_comp();
		    // If right child is larger than largest so far 
    		if (r < n && arr[r] > arr[largest]) 
        		largest = r; 
		    // If largest is not root 
    		if (largest != i) 
		    {   swap(arr[i], arr[largest]); 
		        // Recursively heapify the affected sub-tree 
        		heapify(arr, n, largest); 	}		 
		}
		void sort_driver(vector<int> &arr, int n)
		{
			for(int i = n/2 - 1; i >=0 ; i--)
				heapify(arr, n, i);
			
			for (int i=n-1; i>=0; i--) 
		    { 
        		// Move current root to end 
        		swap(arr[0], arr[i]); 
		        // call max heapify on the reduced heap 
        		heapify(arr, i, 0); 
    		} 
		}
	
		void init_sort(int list_size)
		{
			this->create_list(list_size, a_name);
			this->sort_driver(this->list, this->list.size());
			compList.push_back(this->get_no_of_comp());		
		}
		
		void write_to_file()
		{	write_comparisons(c_name, hasPassList);		}
};
#endif
