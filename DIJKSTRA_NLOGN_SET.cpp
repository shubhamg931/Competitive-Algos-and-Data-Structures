/*
* shubhamg931 - Shubham Gupta (B.Tech - IT, 2016-2020 batch)
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define INF				 0x3f3f3f3f 
#define mod              1000000007
#define MAXN             500005
#define PI               3.14159265
#define pb               push_back
#define eb               emplace_back
#define FAST_IO          ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define FILE_READ_WRITE \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);
#define mp(a,b)          make_pair(a,b)
#define mset(arr,val)    memset(arr,val,sizeof arr)
#if 1
typedef long long let;
#else
typedef int let;
#endif
typedef unsigned long long ull;
typedef long ld;
typedef long double ldo;
typedef pair<let, let> pll;

#define ordered_set tree<let, null_type,less_equal<let>, rb_tree_tag,tree_order_statistics_node_update> 

void add_edge(vector<pll> g[], let u, let v, let wt){
    g[u].push_back({v, wt});
    g[v].push_back({u, wt});
}

vector<let> dijkstra(vector<pll> g[], let V, let src){
    set<pll> distance_set;
	vector<let> shortest_paths(V, INF);

	distance_set.insert({0, src});
	shortest_paths[src] = 0;

	while(!distance_set.empty()){
		pll tmp = *(distance_set.begin());
		let u = tmp.second;
		distance_set.erase(distance_set.begin());

		for(auto it: g[u]){
			if(shortest_paths[it.first] > shortest_paths[u] + it.second){
				if(shortest_paths[it.first] != INF){
					distance_set.erase(distance_set.find(mp(shortest_paths[it.first], it.first)));
				}
				shortest_paths[it.first] = shortest_paths[u] + it.second;
				distance_set.insert({shortest_paths[it.first], it.first});
			}
		}
	}
	return shortest_paths;
}

int main(){
    FAST_IO
    #ifndef ONLINE_JUDGE 
        FILE_READ_WRITE
    #endif
    
    let V = 9;
    vector<pll> graph[V];
    add_edge(graph, 0, 1, 4); 
    add_edge(graph, 0, 7, 8); 
    add_edge(graph, 1, 2, 8); 
    add_edge(graph, 1, 7, 11); 
    add_edge(graph, 2, 3, 7); 
    add_edge(graph, 2, 8, 2); 
    add_edge(graph, 2, 5, 4); 
    add_edge(graph, 3, 4, 9); 
    add_edge(graph, 3, 5, 14); 
    add_edge(graph, 4, 5, 10); 
    add_edge(graph, 5, 6, 2); 
    add_edge(graph, 6, 7, 1); 
    add_edge(graph, 6, 8, 6); 
    add_edge(graph, 7, 8, 7);

    dijkstra(graph, V, 0);

	vector<let> shortest_paths = dijkstra(graph, V, 0);
	for(let i = 0; i < V; ++i){
		cout<<"Shortest path to vertex "<<i<<": "<<shortest_paths[i]<<"\n";
	}

    return 0;
}
