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
typedef long long int ll;

ll kadane(ll a[],ll n){
    ll curr_sum=0;
    ll max_so_far=INT_MIN;
    for(int i=0;i<n;i++){
        curr_sum+=a[i];
        if(max_so_far<curr_sum){
            max_so_far=curr_sum;
        }
        if(curr_sum<0){
            curr_sum=0;
        }
    }
    return max_so_far;
}

ll kcon(ll a[],ll n,ll k){

    // find kadane's sum
    ll kadane_sum=kadane(a,n);
    if(k==1){
        return kadane_sum;
    }
    
    ll current_prefix_sum=0,current_suffix_sum=0;
    ll max_prefix_sum=INT_MIN,max_suffix_sum=INT_MIN;

    // finding max prefix sum
    for(int i=0;i<n;i++){
        current_prefix_sum+=a[i];
        max_prefix_sum=max(current_prefix_sum,max_prefix_sum);
    }
    ll total_sum=current_prefix_sum;

    // finding max suffix sum
    for(int i=n-1;i>=0;i--){
        current_suffix_sum+=a[i];
        max_suffix_sum=max(max_suffix_sum,current_suffix_sum);
    }
    ll ans;

    if(total_sum<0){
        ans=max(max_suffix_sum+max_prefix_sum,kadane_sum);
    }else{
        ans=max(max_suffix_sum+max_prefix_sum+total_sum*(k-2),kadane_sum);
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll ans=kcon(a,n,k);
        cout<<ans<<endl;
    }
}