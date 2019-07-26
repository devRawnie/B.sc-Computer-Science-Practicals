#include<iostream>
#include<vector>
#include<list>
#include<utility>
using namespace std;
class DFS{
	private:	vector<int > *adlist;
				int v;
	public:
		DFS(int v){
			this->v = v;
			adlist = new vector<int >[v];
		}
		~DFS(){
			delete[] adlist;
		}
		int insertNode(int src, int dest){
			if(src < 0 || src >= v || dest < 0 || dest >= v){
				return -1;
			}
			
			adlist[src].push_back(dest);
			adlist[dest].push_back(src);
			return 0;
		}
		void displayGraph(){
			for(int i = 0 ;i < v; i++){
				cout<<i<<"->";
				for(int j = 0 ; j < adlist[i].size(); j++){
						cout<<adlist[i][j]<<"->";
				}
				cout<<endl;
			}
		}
		
		int createGraph(){
			int ch;
			int src, dest;
			while(1){
				cout<<"\n1. Add Node\n2.Display Graph\n3.End making graph\n->";
				cin>>ch;
				switch(ch){
					case 1: cout<<"Enter source vertex: ";
							cin>>src;
							cout<<"Enter destination vertex: ";
							cin>>dest;
							if(insertNode(src, dest) == -1)
								printf("Please enter the vertex numbers within range( 0 - %d).", v-1);
							else
								cout<<"Node added successfully";
							break;
					case 2: this->displayGraph();
							break;
					case 3: return 0;
							break;
					default: cout<<"Invalid choice";
				}				
			}
		}
		void dfs(bool *visited, int node){
		
			visited[node] = true;
			cout<<node<<" ";
			for(int i = 0; i < adlist[node].size(); i++){
				if(!visited[adlist[node][i]])
					dfs(visited, adlist[node][i]);
			}
		}
		void dfs_util(int start){
			if(start < 0 || start >= this->v){
				printf("Please enter the vertex numbers within range( 0 - %d).", v-1);
				return;
			}
			bool *visited = new bool[this->v];
			for(int i = 0 ; i < this->v; i++)
				visited[i] = false;
			dfs(visited, start);
		}
};


int main(){
	int n, ch, node;
	cout<<"Enter no of vertices: ";
	cin>>n;
	DFS d(n);
	d.createGraph();
	while(1){
		cout<<"\n1. DFS from node n\n2.Display Graph\n3.Exit\n->";
		cin>>ch;
		switch(ch){
			case 1: cout<<"enter node to start dfs from: ";
					cin>>node;
					d.dfs_util(node);
					break;
			case 2: d.displayGraph();
					break;
			case 3: return 0;
			default: cout<<"Invalid choice ";
		}		
	}
}
