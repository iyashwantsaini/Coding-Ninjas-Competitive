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
    int a[]={7,6,-5,10};
    int s[4];
    // OP=18
    cout<<kadane(a,4,s);
    return 0;
}