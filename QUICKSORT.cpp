/*
Aaaye mera solution dekhne aaye ho... bdia hai... :P

Swaagat hai aap logo ka!!
*/

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define eb emplace_back
typedef unsigned long long ull;
typedef long long lld;
typedef long ld;
typedef long double ldo;
typedef pair<lld, lld> pll;

lld partition(lld arr[], lld l, lld r){
    lld pivot = arr[l];
    lld i = l;
    
    for(lld j = l+1; j <= r; ++j){
        if(arr[j] < pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[l],arr[i]);
    return i;
}

void quickSort(lld arr[], lld l, lld r){
    if(r>l){
        lld p = partition(arr, l, r);

        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
    }
}

void printArray(lld arr[], lld n){
    for(lld i = 0; i < n; ++i){
        cout<<arr[i]<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    lld t,i,ar[100000];
    cin>>t;
    for(i=0;i<t;++i){
        cin>>ar[i];
    }

    quickSort(ar, 0, t-1);

    printArray(ar, t);

    return 0;
}
