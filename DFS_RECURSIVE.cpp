#include<bits/stdc++.h>
using namespace std;

typedef long long lld;

class Graph{
    lld V;

    vector<lld> *adj;
public:
    Graph(lld V);

    void addEdge(lld v, lld w);

    void DFSUtil(lld v, bool visited[]);
    void DFS(lld s);
};

Graph::Graph(lld V) {
    this->V = V;

    adj = new vector<lld>[V];
}

void Graph::addEdge(lld v, lld w) {
    adj[v].push_back(w);
}

void Graph::DFSUtil(lld v, bool *visited) {
    visited[v] = true;
    cout<<v<<" ";

    for(auto it: adj[v]){
        if(!visited[it]){
            DFSUtil(it, visited);
        }
    }
}

void Graph::DFS(lld s) {
    bool visited[V];
    for(lld i = 0;i<V;++i){
        visited[i] = false;
    }

    DFSUtil(s, visited);
}

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout<<"DFS starting from vertex 2: ";
    g.DFS(2);

    return 0;
}