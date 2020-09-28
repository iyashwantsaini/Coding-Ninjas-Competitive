// Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
// Do this recursively.

#include<bits/stdc++.h>
using namespace std;

bool checknum(int a[],int n,int val) {
    // base
    if(n==1) return a[0]==val;
    if(a[0]==val){
        return true;
    }
    return checknum(a+1,n-1,val);
}

int main(){
    int a[]={1,2,3,4,5,7};
    cout<<checknum(a,6,5);
}
