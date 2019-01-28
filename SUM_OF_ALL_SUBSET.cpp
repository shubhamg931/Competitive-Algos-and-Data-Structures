#include<bits/stdc++.h>
using namespace std;

typedef long long lld;

void subsetSum(lld arr[], lld n){
    lld siz = 1<<n;

    for(lld i = 0; i < siz;++i){
        lld sum = 0;
        for(lld j=0;j<n;++j){
            if(i & (1<<j)){
                sum += arr[j];
            }
        }
        cout<<sum<<" ";
    }
}

int main(){
    lld n,i,arr[1000];
    cin>>n;
    for(i=0;i<n;++i){
        cin>>arr[i];
    }

    subsetSum(arr, n);
}