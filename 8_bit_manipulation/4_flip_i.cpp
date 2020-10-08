// flip the ith bit of a number => 1->0 | 0->1

// sample ip - 5 2
// op 1

// 5 - 00000101
// 1<<2 - 00000100
// 5^1<<(2) - 00000001 = 1 so, 2nd bit has been flipped

#include<bits/stdc++.h>
using namespace std;

int flip_i(int n,int i){
    n=n^1<<i;
    return n;
}

int main(){
    int n,i;
    cin>>n>>i;
    cout<<flip_i(n,i);
}