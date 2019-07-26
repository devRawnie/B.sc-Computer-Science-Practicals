#include<iostream>
#include "heap_sort.h"

using namespace std;

int main()
{
	
	generic_sort *p = new heap_sort();
	for(int i = 3; i<=100; i++)
	{
		p->init_sort(i*10);
	}
		p->write_to_file();
		delete p;
	return 0;
}
