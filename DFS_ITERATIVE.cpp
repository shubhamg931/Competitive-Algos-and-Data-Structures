#include<bits/stdc++.h>
using namespace std;

typedef long long lld;

class Graph{
    lld V;
    vector<lld> *adj;

public:
    Graph(lld V);

    void addEdge(lld v, lld w);

    void DFS(lld s);
};

Graph::Graph(lld V) {
    this->V = V;

    adj = new vector<lld>[V];
}

void Graph::addEdge(lld v, lld w) {
    adj[v].push_back(w);
}

void Graph::DFS(lld s) {
    bool visited[V];
    for(int i = 0;i<V;++i){
        visited[i] = false;
    }

    stack<lld> stk;

    stk.push(s);

    while (!stk.empty()){
        s = stk.top();
        stk.pop();

        if(!visited[s]){
            cout<<s<<" ";
            visited[s] = true;
        }

        for (auto it : adj[s]) {
            if(!visited[it]){
                stk.push(it);
            }
        }
    }
}

int main(){

    Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);

    cout << "Following is Depth First Traversal\n";
    g.DFS(0);

    return 0;
}