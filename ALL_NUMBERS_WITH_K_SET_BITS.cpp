#include <iostream>
#include <algorithm>
using namespace std;

// Function to find all N-digit binary numbers with k-bits set where 
// k ranges from 1 to N
void printAllCombinations(int N)
{
    // string to store N-digit binary number
    string str;

    // construct N-digit binary number filled with all 0's
    int j = N;
    while (j--)
        str.push_back('0');

    // print all numbers with k-bit set together in ascending order
    for (int k = 1; k <= 15; k++)
    {
        cout<<"k: "<<k<<endl;
        cout<<"start"<<endl;
        // set last k bits to '1'
        str[N - k] = '1';
        string curr = str;

        cout << "(k = " << k << ") " ;

        // use std::next_permutation to print string lexicographically
        do
        {
            cout << curr << " ";
        }
        while (next_permutation(curr.begin(), curr.end()));

        cout << endl;
        cout<<"end"<<endl;
    }
}

// main function
int main()
{
    int N = 30;

    printAllCombinations(N);

    return 0;
}