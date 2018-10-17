/*
Aaaye mera solution dekhne aaye ho... bdia hai... :P

Swagat hai aap logo ka!!
*/
//KARATSUBA multiplication for Z

#include<bits/stdc++.h>
#define ull unsigned long long
#define lld long long
#define mod 1000000007
#define ld long
#define ldo long double

using namespace std;

string stringAddition(string s1, string s2){
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    lld s1l = s1.length();
    lld s2l = s2.length();
    if(s1l > s2l){
        for(int i = 0; i < s1l - s2l; ++i){
            s2.append("0");
        }
    }else{
        for(int i = 0; i < s2l - s1l; ++i){
            s1.append("0");
        }
    }
    string s3;
    int carry = 0, sum;
    s3.clear();
    for(int i = 0; i < s1.length(); ++i){
        sum = (s1[i] + s2[i] - 96 + carry)%10;
        carry = (s1[i] + s2[i] - 96 + carry)/10;
        s3 += (char)(sum+48);
    }
    s3 += (char)(carry+48);
    reverse(s3.begin(), s3.end());
    return s3;
}

string karatsuba(string s1, string s2){
    lld s1l = s1.length();
    lld s2l = s2.length();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    if(s1l > s2l){
        for(int i  = 0; i < s1l - s2l; ++i){
            s2.append("0");
        }
    }else{
        for(int i = 0; i < s2l - s1l; ++i){
            s1.append("0");
        }
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    if(s1.length() == 1 && s2.length() == 1){
        string s;
        s = to_string((s1[0] - 48)*(s2[0] - 48));
        return s;
    }

    string a,b,c,d,z1,z2;
    z1.clear();
    z2.clear();
    a = s1.substr(0, s1.length()/2);
    b = s1.substr(s1.length()/2);
    c = s2.substr(0, s2.length()/2);
    d = s2.substr(s2.length()/2);
    for(int i=0;i<s1.length();++i){
        z1.append("0");
    }
    for(int i=0;i<s1.length()/2;++i){
        z2.append("0");
    }

    string ans = stringAddition(stringAddition((karatsuba(a, c).append(z1)),(stringAddition(karatsuba(a,d), karatsuba(b,c)).append(z2))),karatsuba(b,d));
    lld pos;
    for(int i = 0;i < ans.length(); ++i){
        if(ans[i] != '0'){
            pos = i;
            break;
        }
    }
    return ans.substr(pos);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n1,n2;
    cin>>n1;
    cin>>n2;

    cout<<karatsuba(n1, n2);

    return 0;
}

