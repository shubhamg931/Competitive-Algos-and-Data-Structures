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

struct structure{
    lld gate = 0;
    lld link1 = 0;
    lld link2 = 0;
};

void heapify(structure arr[], lld n, lld i)
{
    lld largest = i;
    lld l = 2*i + 1; 
    lld r = 2*i + 2; 

    if (l < n && arr[l].gate > arr[largest].gate)
        largest = l;

    if (r < n && arr[r].gate > arr[largest].gate)
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(structure arr[], lld n)
{
    for (lld i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (lld i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(structure arr[], lld n)
{
    for (int i=0; i<n; ++i){
        cout<< "arr[i].gate: " << arr[i].gate; 
        cout<< ", arr[i].link1: "<< arr[i].link1;
        cout<<", arr[i].link2: "<< arr[i].link2<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 10;
    structure arr[n+1];
    for(int i=0;i<10;i++)
    {
        arr[i].gate = n-i;
        arr[i].link1 = i;
        arr[i].link2 = 98-i;
    }
    heapSort(arr,n);
    printArray(arr,n);

    return 0;
}

