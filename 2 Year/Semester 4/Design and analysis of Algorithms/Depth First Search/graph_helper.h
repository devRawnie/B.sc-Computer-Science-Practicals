#ifndef _GRAPH_HELPER_H
#define _GRAPH_HELPER_H
#include<vector>
#include<list>
#include<utility>
#include<iostream>
using namespace std;
	class graph_helper{
		int n_vertices;
		public: 
		vector< pair<int, int> > *ad_list;
		graph_helper(int v){
			n_vertices = v;
			ad_list = new vector<pair<int, int> >[v];
		}
		~graph_helper(){
			delete[] ad_list;
		}
		
		int addNode(int src, int dest, int weight = 0){
			if(src > n_vertices || dest > n_vertices)
				return -1;
			else{
				pair<int, int> s = make_pair(src, weight);
				pair<int, int> d = make_pair(dest, weight);
				ad_list[src].push_back(d);
				ad_list[dest].push_back(s);
		
				return 0;
			}
		}
		void display_graph(){
			for(int i =0 ; i < n_vertices; i++){
				cout<<i<<"->";
				for(int j = 0; j < ad_list[i].size(); j++)
				{
					pair<int, int> p = ad_list[i][j];
				if(j==ad_list[i].size()-1)
					cout<<p.first<<endl;
				else
					cout<<p.first<<"->";	
				}
		}
	}
	int no_of_vertices(){
		return this->n_vertices;
	}
	};
#endif	
