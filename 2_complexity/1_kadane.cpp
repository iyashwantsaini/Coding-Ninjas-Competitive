// max subarray sum return

#include<bits/stdc++.h>
using namespace std;

int kadane(int a[],int n,int s[]){
    s[0]=a[0];
    for(int i=1;i<n;i++){
        if(a[i]+s[i-1]>a[i]){
            s[i]=a[i]+s[i-1];
        }else{
            s[i]=a[i];
        }
    }
    int maxnum = s[0];
    for(int i=1;i<n;i++){
        if(s[i]>maxnum){
            maxnum=s[i];
        }
    }
    return maxnum;
}

int main(){
    int a[]={-5,6,7,-20,3,5,8,-9};
    int s[8];
    // OP=16
    cout<<kadane(a,8,s);
    return 0;
}