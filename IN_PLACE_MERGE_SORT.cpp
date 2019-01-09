#include <bits/stdc++.h>
using namespace std;

/*
swap function to swap two elements in the
array
*/
void swap(int &a,int &b)
{
    int t = a;
    a = b;
    b = t;
}


//merge function to merge two sorted arrays
void merge(int arr[],int s,int e)
{
    int mid = (s+e)/2;
    int i,j;
    i=s;j=mid+1;
    while(i<=mid && j<=e)
    {
        if(arr[i]<=arr[j])
        {
            i++;
        }
        else
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

/*
mergeSort function recursively call its left half and
right half and the call merge function to merge the two
sorted halves
*/
void mergeSort(int arr[],int s,int e)
{
    if(s==e)
        return;
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}

int main() {
    int n, a[100001], i;
    //size of the input array
    cin >> n;

    //input array
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    /*
    calling mergeSort on input array
    mergeSort(array,start,end)
    */
    mergeSort(a, 0, n - 1);

    //sorted array
    for (i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}