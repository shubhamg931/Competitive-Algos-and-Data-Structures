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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lld decimal;
    string binary;
    cin>>decimal;

    while(decimal/2 != 0){
        binary += (char)((decimal%2)+48);
        decimal /= 2;
    }

    binary += (char)(decimal + 48);
    reverse(begin(binary), end(binary));
    cout<<binary;

    return 0;
}

