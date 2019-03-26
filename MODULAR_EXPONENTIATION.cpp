//
// Created by shubhamg931 on 27/3/19.
//

#include<bits/stdc++.h>
using namespace std;

int power(int x, int y, int q){
    int res = 1;
    x = x%q;

    while(y > 0){
        if(y & 1){
            res = (res*x)%q;
        }

        y = y>>1;
        x = (x*x)%q;
    }

    return res;
}

int main(){
    int x = 2, y = 5, q = 13;
    cout<<power(x, y, q);

    return 0;
}