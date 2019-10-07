#include<bits/stdc++.h>
using namespace std;


#if 1
typedef long long let;
#else
typedef int let;
#endif

let dp[20][200][2];

let digits(let x, vector<let> &arr){
    while(x){
        arr.push_back(x%10);
        x /= 10;
    }
}

let digit_sum(let index, let tight, let sum, vector<let> &arr){
    if(index == -1)
        return sum;

    if(dp[index][sum][tight] != -1 and tight != 1){
        return dp[index][sum][tight];
    }

    let return_sum = 0;
    let range = tight?arr[index]:9;

    for(let i=0;i<=range;++i){
        let new_tight = (arr[index] == i)?tight: 0;

        return_sum += digit_sum(index-1, new_tight, sum+i, arr);
    }

    if(!tight)
        dp[index][sum][tight] = return_sum;

    return return_sum;
}

int main(){
    let l,r;
    memset(dp, -1, sizeof(dp));
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif //ONLINE_JUDGE
    cin>>l>>r;
    vector<let> arr_l, arr_r;
    digits(l-1, arr_l);
    digits(r, arr_r);

    cout<<digit_sum(arr_r.size()-1, 1, 0, arr_r) - digit_sum(arr_l.size()-1, 1, 0, arr_l);
}