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

int gcdEuclid(int x, int y){
    int dividend = x;
    int divisor = y;
    while(divisor != 0){
        int remainder = dividend%divisor;
        dividend = divisor;
        divisor = remainder;
    }
    return dividend;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    cout<<"GCD : "<<gcdEuclid(a,b);
    return 0;
}

