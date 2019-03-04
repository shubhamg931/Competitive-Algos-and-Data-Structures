#include<bits/stdc++.h>
using namespace std;
typedef long long lld;

#define V 9

lld minDistance(lld distances[], lld visited[]){
    lld min = LLONG_MAX, min_index;

    for(lld i=0;i<V;++i){
        if((distances[i] <= min) and (visited[i] == 0)){
            min = distances[i];
            min_index = i;
        }
    }

    return min_index;
}

void dijkstra(lld lengths[][V], lld start){
    lld distances[V], visited[V];
    for(lld i=0;i<V;++i){
        distances[i] = LLONG_MAX;
        visited[i] = 0;
    }
    distances[start] = 0;

    for(lld i = 0; i<V;++i){
        lld u = minDistance(distances, visited);
        visited[u] = 1;

        for(lld v=0;v<V;++v){
            if(!visited[v] and lengths[u][v] and (distances[u] + lengths[u][v] < distances[v]))
                distances[v] = distances[u] + lengths[u][v];
        }
    }

    for(lld i=0;i<V;++i){
        cout<<"VERTEX "<<i<<": "<<distances[i]<<"\n";
    }
}

int main(){
    lld graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);

    return 0;
}