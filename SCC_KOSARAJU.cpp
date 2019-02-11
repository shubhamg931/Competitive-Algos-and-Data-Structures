#include<bits/stdc++.h>
using namespace std;

typedef long long lld;

class Graph{
    lld V;

    vector<lld> *adj;
public:
    Graph(lld V);
    void addEdge(lld v, lld w);

    Graph getTranspose();
    void fillOrder(lld v, bool visited[], stack<lld> &Stack);
    void DFSUtil(lld v, bool visited[]);
    void printSCCs();
};

Graph::Graph(lld V) {
    this->V = V;

    adj = new vector<lld>[V];
}

void Graph::addEdge(lld v, lld w) {
    adj[v].push_back(w);
}

Graph Graph::getTranspose() {
    Graph gT(V);

    for(lld i = 0;i<V;++i){
        for(auto it: adj[i]){
            gT.adj[it].push_back(i);
        }
    }

    return gT;
}

void Graph::DFSUtil(lld v, bool *visited) {
    visited[v] = true;
    cout<<v<<"  ";

    for(auto it: adj[v]){
        if(!visited[it])
            DFSUtil(it, visited);
    }
}

void Graph::fillOrder(lld v, bool *visited, stack<lld> &Stack) {
    visited[v] = true;

    for(auto it: adj[v]){
        if(!visited[it]){
            fillOrder(it, visited, Stack);
        }
    }

    Stack.push(v);
}

void Graph::printSCCs() {
    bool visited[V];
    for(lld i=0;i<V;++i)
        visited[i] = false;

    stack<lld> Stack;

    for(lld i=0;i<V;++i){
        if(!visited[i]){
            fillOrder(i, visited, Stack);
        }
    }

    Graph transposedGraph = getTranspose();

    for(lld i=0;i<V;++i){
        visited[i] = false;
    }

    while(!Stack.empty()){

        lld v = Stack.top();
        Stack.pop();

        if(!visited[v]){
            transposedGraph.DFSUtil(v, visited);
            cout<<endl;
        }

    }
}

int main(){

    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout<<"Following are the Strongly connected components: "<<endl;
    g.printSCCs();

    return 0;
}