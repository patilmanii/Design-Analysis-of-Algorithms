#include <iostream>
using namespace std;
class DSU{
	int *parent;
	int *rank;
	public:
		
	DSU(int n){
		parent = new int[n];
		rank = new int[n];
		
		for (int i =0; i<n; i++){
			parent[i] = i;
			rank[i] = 0;
		}
	}
	int find(int node){
		if(node == parent[node])
		return node;
		return parent[node] = find(parent[node]);
	}
	void Union(int u, int v){
	u = find(u);
	v = find(v);
	
	if(u != v){
		if(rank[u] < rank[v]){
			int temp = u;
			u = v;
			v= temp;
		}
		parent[v] = u;
		
	if(rank[u] == rank[v])
	rank[u]++; 
	}
}
};

int main(){
	int n = 5;
	
	DSU dsu(n);
	dsu.Union (0, 1);
	dsu.Union (2, 3);
	
	dsu.Union(0,4);
	
	for(int i=0; i<n; i++){

	
	cout<<"parent of"<< i << "is" <<dsu.find(i) << endl;

}
 	return 0;
 }
