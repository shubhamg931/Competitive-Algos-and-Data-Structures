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
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(structure arr[], lld n, lld i)
{
    lld largest = i; // Initialize largest as root
    lld l = 2*i + 1; // left = 2*i + 1
    lld r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l].gate > arr[largest].gate)
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r].gate > arr[largest].gate)
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(structure arr[], lld n)
{
    // Build heap (rearrange array)
    for (lld i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (lld i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
void printArray(structure arr[], lld n)
{
    for (int i=0; i<n; ++i)
        cout<< "arr[i].gate: " << arr[i].gate << "arr[i].link1: "<<arr[i].link1<<"arr[i].link2: "<<arr[i].link2<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //Example
    int n = 10;//size of array
    structure arr[n+1];
    //initializing array
    for(int i=0;i<10;i++)
    {
        arr[i].gate = n-i;
        arr[i].link1 = i;
        arr[i].link2 = 98-i;
    }
    //Calling heapSort function to sort the array
    heapSort(arr,n);
    //printing the array
    printArray(arr,n);

    return 0;
}

