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

void merge(lld arr[], lld l, lld r, lld m){ // arrays are by default passed by reference!

    lld n1 = m-l+1;
    lld n2 = r - m;

    lld left[n1];
    lld right[n2];

    for(lld i = l; i < m+1; ++i){
        left[i-l] = arr[i];
    }

    for(lld i = m+1; i < r+1; ++i){
        right[i-m-1] = arr[i];
    }

    //replace in the array while sorting the subarrays

    lld i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            ++i;
        }else{
            arr[k] = right[j];
            ++j;
        }

        ++k;
    }

    while(i < n1){
        arr[k] = left[i];
        ++i;
        ++k;
    }
    while(j < n2){
        arr[k] = right[j];
        ++j;
        ++k;
    }

}

void mergeSort(lld arr[], lld l, lld r){
    if(l < r){

        lld mid = l + (r-l)/2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        merge(arr, l, r, mid);
    }
}

void printArray(lld arr[], lld size){
    for(lld i = 0; i < size; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    lld arr[] = {12,4,23,3434,23,5,23,54,3,23,12,23,12,56,34,1,2,3,2,8,7,6,5,4,3};
    lld size = sizeof(arr)/ sizeof(arr[0]);

    printArray(arr, size);
    mergeSort(arr, 0, size-1);
    printArray(arr, size);
    return 0;
}

