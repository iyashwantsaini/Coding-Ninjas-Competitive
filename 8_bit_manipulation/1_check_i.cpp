// check if ith bit of a number is set(1) or not(0)

// sample ip - 5 2
// op "Set"
// 5 - 00000101
// 1<<2 - 00000100
// 5&1<<(2) - 00000100 => 1<<2

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string check_i(int n,int i){
    if((n&1<<i)==1<<i){
        return "Set";
    }
    return "Not Set";
}

int main(){
    int n,i;
    cin>>n>>i;
    cout<<check_i(n,i);
}