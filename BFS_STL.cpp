#include<bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    queue<int> q;
    q.push(s);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        if(!vis[node]){
            cout<<node<<" ";
            vis[node] = true;
        }
        for(auto it: adj[node]){
            if(!vis[it]){
                q.push(it);
            }
        }
    }
    
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis, N);

        cout<<endl;

    }
}

