// Given an array of length N, you need to find and return the sum of all elements of the array.
// Do this recursively.

#include<bits/stdc++.h>
using namespace std;

int sum(int a[],int n) {
    // base
	if(n==0) return 0;
    if(n==1) return a[0];
    return a[0]+sum(a+1,n-1);
}

int main(){
    int a[]={1,2,3,4,5};
    cout<<sum(a,5);
}
