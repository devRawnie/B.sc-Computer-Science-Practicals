#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "graph_helper.h"
using namespace std;
class MST{
	graph_helper *g;
	int v;
	public: 
//	MST(int n){
//		v = n;
//		g = new graph_helper(v);
//	}
	void __init(int n){
		v = n;
		g = new graph_helper(v);
	}
	~MST()
	{	delete g;	}		
	int create_graph(){
		int ch, src, dest, weight;
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
					printf("\nEnter the weight of edge (%d, %d ) : ", src, dest);
					cin>>weight;
					if(g->addNode(src, dest, weight) == 0)
						cout<<"\nNode added succesfully\n";
					else
						cout<<"\nPlease enter the vertices in range\n";
					cout<<endl;
				break;
			case 2: g->display_graph();
				break;
			case 3: return 0;
					break;
			default: cout<<"Please enter valid choice";	}
		}	
		return -1;	}
	void _init_mst(){
		int key[this->v], parent[this->v];
		bool mstSet[this->v];
		vector<pair<int, int> > list;
		pair<int, int> temp;
		for(int i = 0 ; i < v ; i++){
			key[i] = INT_MAX;
			mstSet[i] = false;		
		}
			key[0] = 0;
		//we start with the second vertex because first node is implictly in the tree
		parent[0] = -1;
	
		for(int i = 0; i < this->v-1; i++){
			//find the minimum value of key
			int u = findMinKey(key, mstSet);
			cout<<u<<endl;
			//include the minimum key vertex in the tree set
			mstSet[u] = true;
			
			//get the list of vertex u from the list of all vertices
			list = this->g->ad_list[u];
			
			for(int i = 0 ; i < list.size(); i++){
				temp = list[i];
				
				if(mstSet[temp.first] == false && temp.second < key[temp.first] ){
					parent[temp.first] = u;
					key[temp.first] = temp.second;
				}
			}
			
		}
		printMST(parent);
	}
	//Determine the minimum key for the vertex which is not yet included
	int findMinKey(int key[], bool mstSet[])
	{
		int min = INT_MAX, index;
		for(int i = 0 ;i < v; i++){
			if(mstSet[i] == false && key[i] < min){
				min = key[i];
				index = i;
			}
		}

		return index;
	}
	//utility function to fetch weight of the edge u->v
	int getWeight(int u, int dest){
		vector<pair<int, int> > list = this->g->ad_list[u];
		pair<int, int> temp;
		for(int i = 0; i < list.size(); i++){
			temp = list[i];
			if(temp.first == dest)
				return temp.second;
		}
	}
	void printMST(int parent[]){
		cout<<"\n Edge \t    Weight";
		for(int i = 1; i < v ; i++)
			printf("\n %d to %d \t %d \n", parent[i], i , getWeight(i, parent[i]));
	}
	void displayGraph()
	{
		this->g->display_graph();
	}
	void add(int u , int v, int weight){
		this->g->addNode(u, v, weight);
	}
};


int main()
{
	
	int ch, v, result = 0;
	cout<<"\n1. Make a graph\n";
	cout<<"2. Use existing graph :: ";
	cin>>v;
	MST d;
	if(v==1){
		cout<<"\nEnter no of vertices in the graph: ";
		cin>>ch;	
		d.__init(ch);
		result = d.create_graph();		
	}else{
		d.__init(5);
		d.add(0,1 , 2);
		d.add(0, 3, 6);
		d.add(1,2 , 3);
		d.add(1, 3, 8);
		d.add(1,4 , 5);
		d.add(2, 4, 7);
		d.add(3,4 , 9);
	}
	d.displayGraph();
	if(result==0){
		d._init_mst();
	}
	else{
		cout<<"An error occured. Please try again later.";
	}		
	return 0;
}	
