#include<iostream>
#include<vector>
#include<list>
#include<utility>
using namespace std;
class BFS{
	private:	vector<int > *adlist;
				int v;
	public:
		BFS(int v){
			this->v = v;
			adlist = new vector<int >[v];
		}
		~BFS(){
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
								cout<<"...Node added successfully";
							break;
					case 2: this->displayGraph();
							break;
					case 3: return 0;
							break;
					default: cout<<"Invalid choice";
				}				
			}
		}
		void bfs(int start){
			if(start < 0 && start >= this->v){
				printf("Please enter the node value in the range (0 - %d)", this->v-1);
				return;
			}
			
			bool *visited = new bool[this->v];
			visited[start] = true;
			cout<<start<<" ";
			list<int> q;
			q.push_back(start);
			while(!q.empty()){
				int node = q.front();
				cout<<node<<" ";
				q.pop_front();
				for(int i  = 0 ; i < adlist[node].size(); i++){
					if(!visited[adlist[node][i]]){
						visited[adlist[node][i]] = true;
						q.push_back(adlist[node][i]);
					}
				}
			}
		}
	
};


int main(){
	int n, ch, node;
	cout<<"Enter no of vertices: ";
	cin>>n;
	BFS d(n);
	d.createGraph();
	while(1){
		cout<<"\n1. bfs from node n\n2.Display Graph\n3.Exit\n->";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter node to start bfs from: ";
					cin>>node;
					d.bfs(node);
					break;
			case 2: d.displayGraph();
					break;
			case 3: return 0;
			default: cout<<"Invalid choice ";
		}		
	}
}
