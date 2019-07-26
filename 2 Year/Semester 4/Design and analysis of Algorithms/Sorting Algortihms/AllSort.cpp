#include<iostream>
#include "sorting_algo.h"
#include "sort_template.h"

using namespace std;
int i;
void beginSorting(generic_sort *sort)
{
	for(i=3;i<100;i++)
	{
		sort->init_sort(i*10);
		}	
		sort->write_to_file();
}

int main()
{
	generic_sort *sort;
	
	sort = new bubble_sort();
	beginSorting(sort);
	delete sort; 
	
	sort = new selection_sort();
	beginSorting(sort);
	delete sort;
	
	sort = new insertion_sort();
	beginSorting(sort);
	delete sort; 
	
	sort = new merge_sort();
	beginSorting(sort);
	delete sort;
	
	sort = new quick_sort();
	beginSorting(sort);
	delete sort; 
	
	return 0;
}
