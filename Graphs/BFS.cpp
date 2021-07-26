#include <bits/stdc++.h>
using namespace std;

class graph{
    int n;
    vector<int> *adj;
    
    public:
        graph(int n){
            this->n = n;
            adj = new vector<int>[n];
        }
        void addUndirectedEdge(int a, int b){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        void addDirectedEdge(int a, int b){
            adj[a].push_back(b);
        }
        void BFS(int src);
};

void graph::BFS(int src){
    vector<bool> visited(n,false);
    queue<int> q;
    
    visited[src] = 1;
    q.push(src);
    
    while(!q.empty()){
        int curr = q.front(), num = adj[curr].size();
        cout<<curr<<" ";
        q.pop();
        
        for(int i=0; i<num; i++){
            if(!visited[adj[curr][i]]){
                visited[adj[curr][i]] = true;
                q.push(adj[curr][i]);
            }
        }
    }
}

int main (){
    graph g(4);
    g.addUndirectedEdge(0,1);
    g.addUndirectedEdge(0,2);
    g.addUndirectedEdge(1,2);
    g.addUndirectedEdge(2,3);
    g.addUndirectedEdge(3,3);
    
    g.BFS(2);
    return 0;
}
