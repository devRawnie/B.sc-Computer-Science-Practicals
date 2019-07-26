#include<iostream>
#include<vector>
#include<list>
#include<utility>
using namespace std;
class MST{
	private:	vector<pair<int,int> > *adlist;
				int v;
	public:
		MST(int v){
			this->v = v;
			adlist = new vector<pair<int,int> >[v];
		}
		~MST(){
			delete[] adlist;
		}
		int add(int src, int dest, int weight){
			
			pair<int, int> s = make_pair(dest, weight);
			pair<int, int> d = make_pair(src, weight);
			
			adlist[src].push_back(s);
			adlist[dest].push_back(d);
			return 0;
		}
		void displayGraph(){
			pair<int, int> temp;
			for(int i = 0 ;i < v; i++){
				cout<<i<<"->";
				for(int j = 0 ; j < adlist[i].size(); j++){
						temp = adlist[i][j];
						printf("%d(%d)->", temp.first, temp.second);
				}
				cout<<endl;
			}
		}
		
		int createGraph(){
			int ch;
			int src, dest, weight;
			while(1){
				cout<<"\n1. Add Node\n2.Display Graph\n3.End making graph\n->";
				cin>>ch;
				switch(ch){
					case 1: cout<<"Enter source vertex: ";
							cin>>src;
							cout<<"Enter destination vertex: ";
							cin>>dest;
							if(src < 0 || src >= v || dest < 0 || dest >= v){
								printf("Please enter the vertex numbers within range(0 - %d).", v-1);
								break;
							}
							start:
							printf("Enter the weight of edge %d-%d: ", src, dest);
							cin>>weight;
							if(weight < 0){
								cout<<"Weight can not be negative.";
								goto start;
							}
							if(add(src, dest, weight) == 0)
								cout<<"...Node added successfully";
							else
								cout<<"There has been a problem";
							break;
					case 2: this->displayGraph();
							break;
					case 3: return 0;
							break;
					default: cout<<"Invalid choice";
				}				
			}
		}
		int findKey(int key[], bool mstset[]){
			int min = INT_MAX, index;
			for(int i = 0; i < this->v; i++){
				if(!mstset[i] && key[i] < min){
					min = key[i];
					index = i;
			}
			}
			cout<<index<<"::\n";
			return index;
		}
		void checkMST(){
			vector<pair<int, int> > list;
			pair<int, int> temp;
			bool mstset[v];
			int key[v], parent[v];
			for(int i = 0 ; i < v; i++){
				mstset[i] = false;
				key[i] = INT_MAX;
			}
			key[0] = 0;
			parent[0] = -1;
			for(int i = 0; i < v-1 ; i++){
				int node = findKey(key, mstset);
				mstset[node] = true;
				cout<<node<<endl;
				list = adlist[node];
				for(int j = 0 ; j < list.size(); j++){
					temp = list[j];
					if(!mstset[temp.first] && temp.second < key[temp.first]){
						parent[temp.first] = node;
						key[temp.first] = temp.second;
					}
				}
			}
		printMST(parent);
		}
		
	void printMST(int parent[]){
		cout<<"\n Edge \t    Weight";
		for(int i = 1; i < v ; i++)
			printf("\n %d to %d \t %d \n", parent[i], i , getWeight(i, parent[i]));
	}
		int getWeight(int u, int dest){
		vector<pair<int, int> > list = adlist[u];
		pair<int, int> temp;
		for(int i = 0; i < list.size(); i++){
			temp = list[i];
			if(temp.first == dest)
				return temp.second;
		}
	}
};


int main(){
	int n, ch, node;
//	cout<<"Enter no of vertices: ";
//	cin>>n;
	MST d(5);
	d.add(0,1 , 2);
		d.add(0, 3, 6);
		d.add(1,2 , 3);
		d.add(1, 3, 8);
		d.add(1,4 , 5);
		d.add(2, 4, 7);
		d.add(3,4 , 9);
		d.displayGraph();
//	d.createGraph();
	d.checkMST();
	return 0;
}

