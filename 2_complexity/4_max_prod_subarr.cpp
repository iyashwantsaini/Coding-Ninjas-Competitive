// max subarray product return

#include<bits/stdc++.h>
using namespace std;

int kadane_maxprod(int a[],int n){
    int max_ending_here=1;
    int min_ending_here=1;
    int max_so_far=0;
    for(int i=0;i<n;i++){
        if(a[i]>0){
            max_ending_here=max_ending_here*a[i];
            min_ending_here=min(1,min_ending_here*a[i]);
        }else if(a[i]==0){
            max_ending_here=1;
            min_ending_here=0;
        }else{
            int temp=max_ending_here;
            max_ending_here=max(1,min_ending_here*a[i]);
            min_ending_here=temp*a[i];
        }
        max_so_far=max(max_so_far,max_ending_here);
    }
    return max_so_far;
}

int main(){
    int a[]={6,-3,-10,0,2};
    cout<<kadane_maxprod(a,5);
    return 0;
}