#ifndef _FILE_IO_H
#define _FILE_IO_H
#include<iostream>
#include<ios>
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
using namespace std;

void write_array_to_file(const char *file_name, vector<int> array_list, int array_size)
{
	ofstream fout;
	fout.open(file_name, ios::out | ios::app );
	if(fout.is_open())
	{
		fout<<array_size<<" : ";
		for(int i=0; i < array_list.size(); i++)
			fout<<array_list[i]<<" ";
			}
	fout << "\n\n";
	fout.close();
}

// For writing both comparisons and number of passes occurred in the sort
void write_comparisons_to_file(const char *file_name, vector<int> size_list, vector<int> comp_list, vector<int> pass_list)
{
	ofstream fout;
	fout.open(file_name, ios::out | ios::app);
	if(fout.is_open())
	{
		fout<<" SIZE OF ARRAY \n ";
		for(int i=0; i<size_list.size(); i++)
		{
			fout << "\t "<< size_list[i]<<endl; 
		}
		fout<<" Comparisons \n ";
		for(int i=0; i<comp_list.size(); i++)
		{
			fout << "\t "<< comp_list[i]<<endl; 
		}
		fout<<" Passes \n ";
		for(int i=0; i<size_list.size(); i++)
		{
			fout << "\t "<< pass_list[i]<<endl; 
		}
	}
	fout.close();
}

// For writing both comparisons and number of passes occurred in the sort
void write_comparisons_to_file(const char *file_name, vector<int> size_list, vector<int> comp_list)
{
	ofstream fout;
	fout.open(file_name, ios::out | ios::app);
	if(fout.is_open())
	{
		fout<<" SIZE OF ARRAY \n ";
		for(int i=0; i<size_list.size(); i++)
		{
			fout << "\t "<< size_list[i]<<endl; 
		}
		fout<<" Comparisons \n ";
		for(int i=0; i<comp_list.size(); i++)
		{
			fout << "\t "<< comp_list[i]<<endl; 
		}
		
	}
	fout.close();
}


#endif
