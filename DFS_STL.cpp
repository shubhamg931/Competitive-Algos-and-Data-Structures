#include<bits/stdc++.h>
using namespace std;

void dfs(int s, vector<int> g[], bool vis[])
{
    stack<int> stk;
    stk.push(s);
    while(!stk.empty()){
        int node = stk.top();
        stk.pop();
        if(!vis[node]){
            cout<<node<<" ";
            vis[node] = true;
        }
        for(auto it= g[node].rbegin(); it != g[node].rend(); ++it){
            if(!vis[*it]){
                stk.push(*it);
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
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0,g,vis);
        
        cout<<endl;

    }
}