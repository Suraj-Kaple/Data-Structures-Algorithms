// DFS in graph
#include <bits/stdc++.h>
using namespace std;

void DFS(auto g, auto &visited, auto node){
    visited[node] = 1;
    cout<<node<<endl;
    for(int i=0; i<g[node].size(); i++){
        int nodeNumber = g[node][i];
        if(!visited[nodeNumber]){
            DFS(g,visited,nodeNumber);
        }
    }
}

int make_edge(auto g, int a, int b){
    g[a].push_back(b);
    g[b].push_back(a);
}

int main() {
    int n = 5;
    vector<int> g[n];
    
    make_edge(g,0,1);
    make_edge(g,2,3);
    make_edge(g,3,4);
    make_edge(g,1,4);
    make_edge(g,0,4);
    make_edge(g,1,2);
    
    vector<int> visited(n,0);
    DFS(g,visited,0);
    
    return 0;
}