//
// Created by shubhamg931 on 18/3/19.
//

#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
typedef long long lld;

lld DSU[MAXN];

void make_set(lld i){
    DSU[i] = i;
}

void union_set(lld i, lld j){
    DSU[i] = j;
}

lld find_set(lld i){
    if(DSU[i] == i)
        return i;
    else{
        DSU[i] = find_set(DSU[i]);
    }
    return DSU[i];
}

int main(){
    lld i;
    lld x[10] = {1,2,3,4,5,6,7,8,9,10};
    for(i=0;i<10;++i){
        make_set(x[i]);
    }

    lld pairs[5][2] = {{2,3}, {5,6}, {1,3}, {8,9}, {10,1}};
    for(i=0;i<5;++i){
        union_set(find_set(pairs[i][0]),find_set(pairs[i][1]));
    }

    for(i=0;i<10;++i){
        cout<<x[i]<<" belongs to set of element: "<<find_set(x[i])<<endl;
    }

    return 0;
}
