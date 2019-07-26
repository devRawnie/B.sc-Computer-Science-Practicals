#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<list>
#include<time.h>
#include "graph_helper.h"
using namespace std;
class bfs{
	graph_helper *g;
	int v;
	public: 
	bfs(int n){
		v = n;
		g = new graph_helper(v);
	}
	~bfs(){
		delete g;
	}
	void bfs_util(int ch){
		bool *visited = new bool[v];
		for(int i = 0; i < v ; i++)
			visited[i] = false;
		list<int> q;
		visited[ch] = true;
		q.push_back(ch);
		int s;
		while(!q.empty()){
			s = q.front();
			cout<<s<<" ";
			q.pop_front();
			for(int i = 0; i < g->ad_list[ch].size(); i++){
				pair<int, int> p = g->ad_list[ch][i];
				if(!visited[p.first]){
					visited[p.first] = true;
					q.push_back(p.first);			}
			}	}	}	
	int create_graph(){
		int ch, src, dest;
		while(1){
			cout<<"\n1.Add a node\n";
			cout<<"2.Display Graph\n";
			cout<<"3.End Making Graph\n::";
			cin>>ch;
		switch(ch){
			case 1: cout<<"\na. Enter source vertex(0-"<<v-1<<") : ";
					cin>>src;
					cout<<"\nb. Enter destination vertex(0-"<<v-1<<") : ";
					cin>>dest;
					if(g->addNode(src, dest) == 0)
						cout<<"\nNode added succesfully\n";
					else
						cout<<"\nPlease enter the vertices in range\n";
				break;
			case 2: g->display_graph();
				break;
			case 3: return 0;
			default: cout<<"Please enter valid choice";
		}		}	
		return -1;
	}
	void generate_random_graph(){
		srand(time(0));

	for(int i = 0 ; i < v ; i++){
			int s = rand() % v;
			int d = rand() % v;
			if(s!=d)
				g->addNode(s, d);
	}
	cout<<"The graph is :-\n";
	g->display_graph();	
	}	
	void _init_bfs(){
		int ch;
		while(1){
			cout<<"\n1. Breadth First Traversal\n";
			cout<<"2. Display Graph\n";
			cout<<"3. Exit\n::";
			cin >>ch;
			switch(ch){
				case 1: cout<<"\nEnter node to start bfs from: ";
						cin>>ch;
						if(ch<v)
							bfs_util(ch);
						else
							cout<<"Please enter a node between 0 and "<<v-1;
						break;
				case 2: g->display_graph();
					break;
				case 3: exit(0);
						break;
				default: cout<<"Please enter correct choice";		}
		}	}
};
int main()
{	int ch, result;
	cout<<"\nEnter no of vertices in the graph: ";
	cin>>ch;
	bfs b(ch);
	result = b.create_graph();
	if(result==0)
		b._init_bfs();
	else
		cout<<"An error occured. Please try again later.";	
	return 0;
}	
