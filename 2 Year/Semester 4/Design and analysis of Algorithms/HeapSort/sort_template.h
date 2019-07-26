#ifndef _SORT_TEMPLATE_H
#define _SORT_TEMPLATE_H

#include<iostream>
#include<conio.h>
#include<vector>
#include "file_io.h"
#include<stdlib.h>
#include<time.h>
#include<string.h>
using namespace std;
/*
//The generic_sort class is an abstract class that defines the basic functions for creation and displaying the list of integers which in this case is handled
//using a vector. 
// *no_of_comp* describes the no of comparisons for every sort that occurs
//the variable gets reset everytime a list is generated'
*/
#define RANDOM_NO_RANGE 10000;
class generic_sort{
	private: int no_of_comp;
			int no_of_passes;
			int input_size;
			int list_count;
	public: 
		vector<int> list;
		vector<int> compList;
		vector<int> passList;
		vector<int> sizeList;
		
		
		generic_sort()					//CONSTRUCTOR
		{
			input_size = no_of_comp = list_count = 0;
		}
		
		virtual void init_sort(int list_size) = 0;		//Pure Virtual function
		virtual void write_to_file() = 0;
		int get_no_of_passes()
		{
			return no_of_passes;
		}
		
		int get_no_of_comp()
		{
			return no_of_comp;
		}
		void incr_comp()
		{
			++(this->no_of_comp);
		}
		void incr_pass()
		{
			++(this->no_of_passes);
		}
		int get_input_size()
		{
			return input_size;
		}
		void display_list()
		{
			for(int i = 0; i < list.size(); i++)
				cout<<list[i]<<" ";
		}

		void create_list(int size, const char *a_name)
		{
			
			srand(time(NULL));
			this->sizeList.push_back(size);
			this->list.clear();		//empty the list before next sort
			this->no_of_comp = 0;	//resetting the comparisons variable for a list of different size
			this->no_of_passes = 0;	//resetting the passes variable for a list of different size			
			this->input_size = size;
		
			for(int i=0;i<input_size;i++)
			{
				list.push_back(generateRandom());	
			}
			write_array_to_file(a_name, list, size);
		}
		
		int generateRandom()
		{
			return rand() % RANDOM_NO_RANGE;	
		}
		void swap_num(int &x,int &y)
		{
			int temp = x;
			x = y;
			y = temp;
		}			 
		void display_comparison_table()
		{
			cout<<endl<<"\tSIZE\tCOMPARISONS\n";
			for(int i=0;i<sizeList.size() && i < compList.size() ;i++)
			{
				cout<<"\t"<<sizeList[i]<<"\t"<<compList[i]<<endl;
			}
		}
		void write_comparisons(const char *file_name, bool has_pass_list)
		{
			if(has_pass_list)
				write_comparisons_to_file(file_name, sizeList, compList, passList);
			else
				write_comparisons_to_file(file_name, sizeList, compList);
		}

};

#endif
