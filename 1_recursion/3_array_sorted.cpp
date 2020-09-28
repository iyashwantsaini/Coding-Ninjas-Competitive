// Check if array is sorted or not
// Do this recursively.

#include<bits/stdc++.h>
using namespace std;

int srt(int a[],int n) {
    // basecase
    if(n==0||n==1){
        return 1;
    }
    // rec case
    if(a[0]>a[1]){
        return  0;
    }
    return srt(a+1,n-1);
}

int main(){
    int a[]={1,2,3,4,5};
    cout<<srt(a,5);
}