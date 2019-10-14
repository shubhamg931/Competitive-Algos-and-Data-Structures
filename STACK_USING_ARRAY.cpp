#include<bits/stdc++.h>
using namespace std;

#define MAXN 100000

class stack_arr{
    public:
        int topp = -1;
        int arr[MAXN] = {0};
        void pop();
        void push(int x);
        int top();
        bool isEmpty();
};

void stack_arr::push(int x){
    if(topp >= MAXN-1){
        cout<<"OVERFLOW";
    }else{
        topp++;
        arr[topp] = x;
    }
}

void stack_arr::pop(){
    if(topp < 0){
        cout<<"UNDERFLOW";
    }else{
        topp--;
    }
}

int stack_arr::top(){
    if(topp < 0){
        cout<<"EMPTY STACK!";
        return 0;
    }else{
        return arr[topp];
    }
}

bool stack_arr::isEmpty(){
    return (topp<0);
}

int main(){

    class stack_arr s;
    cout<<s.isEmpty()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.top()<<endl;
    cout<<s.isEmpty();

    return 0;
}