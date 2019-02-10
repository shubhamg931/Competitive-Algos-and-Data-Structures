#include<bits/stdc++.h>
using namespace std;

typedef long long lld;

class Graph{
    lld V;

    vector<lld> *adj;
public:
    Graph(lld V);

    void addEdge(lld v, lld w);

    void topologicalSortUtil(lld v, bool visited[], stack<lld> &Stack);
    void topologicalSort();
};

Graph::Graph(lld V) {
    this->V = V;

    adj = new vector<lld>[V];
}

void Graph::addEdge(lld v, lld w) {
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(lld v, bool *visited, stack<lld> &Stack) {
    visited[v] = true;

    for(auto it: adj[v]){
        if(!visited[it])
            topologicalSortUtil(it, visited, Stack);
    }

    Stack.push(v);
}

void Graph::topologicalSort() {
    stack<lld> Stack;

    bool visited[V];
    for(lld i=0;i<V;++i)
        visited[i] = false;

    for(lld i=0;i<V;++i){
        if(!visited[i]){
            topologicalSortUtil(i, visited, Stack);
        }
    }

    while (!Stack.empty()){
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
}

int main(){

    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}