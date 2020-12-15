// find number of subsets in an array which sum to k

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[7]={2,5,4,3,1,6,7};
    int n=7; // num of elements
    int k=7; // sum value
    // ans contains total number of subsets with sum k
    int ans=0;

    // total masks possible for n elements => 2^n
    // for every mask
    for(int mask=0;mask<(1<<n);mask++){
        int curr_sum=0;
        for(int i=0;i<n;i++){
            // add to sum if maks has 0 at that place
            if((mask&(1<<i))==0){
                curr_sum+=a[i];
            }
        }
        if(curr_sum==k){
            ans++;
        }
    }
    cout<<ans<<"\n";

    // possible cases with k=7 =>5
    // 2,5
    // 2,4,1
    // 3,4
    // 6,1
    // 7
}