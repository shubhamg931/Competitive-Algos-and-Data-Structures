#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
typedef long long ll;

vector<ll> graph[MAXN],vis,par,disc,low,ap;
ll t;


void dfs(ll n)
{
    ll ch = 0;
    vis[n] = true;
    low[n] = disc[n] = ++t;
    for(auto it: graph[n])
    {
        if(!vis[it])
        {
            ch++;
            par[it]=n;
            dfs(it);
            low[n] = min(low[n],low[it]);
            
            if(par[n]!=-1 && disc[n]<=low[it])
                ap[n] = true;
        }
        else if(it!=par[n])
        {
            low[n] = min(low[n],disc[it]);
        }
    }
    if(par[n]==-1 && ch>1)  ap[n]=true;
}

void reset(ll n)
{
    vis.assign(n+1,false);
    ap.assign(n+1,false);
    par.assign(n+1,-1);
    disc.assign(n+1,0);
    low.assign(n+1,0);
    t=0;
}

int main()
{
    ll n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    reset(n);

    for(i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i);
    }
    
    cout<<"Articulation points:\n";
    for(i=1;i<=n;i++)
        if(ap[i])
            cout<<i<<" ";
    
    return 0;
}
