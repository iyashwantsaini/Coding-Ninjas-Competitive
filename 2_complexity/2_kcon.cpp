// You are given an array A with size N (indexed from 0) and an integer K. Let's define another array B with size N · K as the array that's formed by concatenating K copies of array A.
// For example, if A = {1, 2} and K = 3, then B = {1, 2, 1, 2, 1, 2}.
// You have to find the maximum subarray sum of the array B. Fomally, you should compute the maximum value of Bi + Bi+1 + Bi+2 + ... + Bj, where 0 ≤ i ≤ j < N · K.

// Input:
// 2
// 2 3
// 1 2
// 3 2
// 1 -2 1

// Output:
// 9
// 2

#include<bits/stdc++.h>
using namespace std;

int kcon(int b[],int n,int s[]){
    s[0]=b[0];
    int maxnum=s[0];
    for(int i=1;i<n;i++){
        if(b[i-1]>0){
            s[i]=s[i-1]+b[i];
        }else{
            s[i]=b[i];
        }
        if(s[i]>maxnum){
            maxnum=s[i];
        }
    }
    
    // for(int i=1;i<n;i++){
    //     if(s[i]>maxnum){
    //         maxnum=s[i];
    //     }
    // }
    return maxnum;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int b[n*k];
        int x=0;
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                b[x++]=a[j];
            }
        }
        int s[n*k];
        int ans=kcon(b,n*k,s);
        cout<<ans<<endl;
    }
}