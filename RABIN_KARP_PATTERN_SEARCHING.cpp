//
// Created by shubhamg931 on 26/3/19.
//

#include<bits/stdc++.h>
using namespace std;

#define d 256

void search(string pattern, string text, int q, vector<int> &index){
    int textLength = (int)text.length();
    int patternLength = (int)pattern.length();
    int h = 1, textHash = 0, patternHash = 0;
    int i,j;

    for(i=0;i<patternLength-1;++i){
        h = ((h*d)%q);
    }

    for(i=0;i<patternLength;++i){
        textHash = (d*textHash + text[i])%q;
        patternHash = (d*patternHash + pattern[i])%q;
    }

    for(i=0;i<=textLength-patternLength;++i){
        if(textHash == patternHash){
            for(j=0;j<patternLength;++j){
                if(text[i+j] != pattern[j]){
                    break;
                }
            }

            if(j == patternLength){
                index.push_back(i);
            }
        }

        if(i < textLength-patternLength){
            textHash = (d*(textHash-text[i]*h) + text[i+patternLength])%q;
            if(textHash<0)
                textHash += q;
        }
    }
}

int main(){
    string text = "best competitive coder in the competitive coding community!";
    string pattern = "competitive";
    int q = 101;
    vector<int> pos;
    search(pattern, text, q, pos);

    for(auto it: pos){
        cout<<"Pattern found at position: "<<it<<endl;
    }

    return 0;
}