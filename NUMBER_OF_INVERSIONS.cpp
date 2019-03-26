/*
Aaaye mera solution dekhne aaye ho... bdia hai... :P

Swagat hai aap logo ka!!
*/


#include<bits/stdc++.h>
#define ull unsigned long long
#define lld long long
#define mod 1000000007
#define ld long
#define ldo long double

using namespace std;

lld merge(lld arr[], lld l, lld mid, lld r){
    lld i,j,k,temp[100000], count = 0;
    i = l;
    j = mid;
    k = l;
    while ((i < mid) && (j < r)){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
        }else{
            temp[k] = arr[j];
            j++;
            count = count + (mid - i);
        }
        k++;
    }

    while (i < mid ){
        temp[k++] = arr[i++];
    }

    while (j < r){
        temp[k++] = arr[j++];
    }

    for(i = l; i < r; ++i){
        arr[i] = temp[i];
    }

    return count;
}

lld numberOfInversions(lld arr[], lld l, lld r){
    lld mid, count = 0;
    if(r-1 > l){
        mid = (l+r-1)/2;

        count = numberOfInversions(arr, l, mid+1);
        count += numberOfInversions(arr, mid+1, r);

        count += merge(arr, l, mid+1, r);
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input(w2).txt", "r", stdin);

    lld arr[100000];
    for(lld i=0;i<100000; ++i)
        cin>>arr[i];
    cout<<numberOfInversions(arr, 0, 100000);

    return 0;
}

