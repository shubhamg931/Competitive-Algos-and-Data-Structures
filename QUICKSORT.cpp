/*
Aaaye mera solution dekhne aaye ho... bdia hai... :P

Swaagat hai aap logo ka!!
*/

//Merge Sort With Pivot Element As Median of first, last and middle element

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

lld ans = 0;

lld partition(lld arr[], lld l, lld r){
    lld p = arr[l];
    lld i = l+1;

    for(lld j = l+1; j <= r; ++j){
        if(arr[j] <= p){
            swap(arr[j], arr[i]);
            i++;
        }
    }

    swap(arr[l], arr[i-1]);
    return (i-1);
}

void quickSort(lld arr[], lld l, lld r){
    if(l >= r){
        return;
    }else {

        swap(arr[l], arr[r]);
        ans += (r - l);

        lld p = partition(arr, l, r);

        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    lld i,arr[10000];

    for(i=0;i<10000;++i){
        cin>>arr[i];
    }

    quickSort(arr, 0, 9999);

    cout<<ans;

    return 0;
}


