// n person => n jobs => assign with min cost

#include<bits/stdc++.h>
using namespace std;

// recursive solution
int mincost(int cost[4][4],int n,int p,int mask,int *dp){
    // base case
    if(p>=n){
        return 0;
    }
    if(dp[mask]!=INT_MAX){
        return dp[mask];
    }
    // go to the mask and find the bits which are not set
    // one by one set these bits(jobs) for current person => p
    int currmin=INT_MAX;
    for(int j=0;j<n;j++){
        // to check set bit we can do ((AND))
        if((mask&(1<<j))==0){
            // means jth bit is not set => we can explore this path
            // to set bit we can do ((OR))
            int ans=mincost(cost,n,p+1,mask|(1<<j),dp)+cost[p][j];
            if(ans<currmin){
                currmin=ans;
            }
        }
    }
    dp[mask]=currmin;
    return currmin;
}

// iterative solution
int mincost_iter(int cost[4][4],int n,int *dp){
    // finla ans will be stored at dp[(1<<<4)-1] ie (2^n-1)th index
    dp[0]=0;
    int p=0;

    // for every mask
    for(int mask=0;mask<=(1<<n)-1;mask++){
        int temp=mask;
        // k will store number of set bits in current mask
        int k=0;
        while(temp>0){
            if((temp%2)==1){
                k++;
            }
            temp=temp/2;
        }
        for(int j=0;j<n;j++){
            // check if job assigned or not
            // to check use AND
            if((mask&(1<<j))==0){
                // job not assigned => assign 
                // to set use OR
                dp[mask|(1<<j)]=min(dp[mask|(1<<j)],dp[mask]+cost[k][j]);
            }
        }
    }

    return dp[(1<<n)-1];
}

int main(){
    int cost[4][4]={
        {10,2,6,5},
        {1,15,12,8},
        {7,8,9,3},
        {15,13,4,10}
    };
    // 2^n can be found by 1<<n
    int *dp=new int[(1<<4)];
    for(int  i=0;i<(1<<4);i++){
        dp[i]=INT_MAX;
    }
    // start with assigning to 1st number => 0
    // pass initial mask => 0000 => 0

    // recursive
    // cout<<mincost(cost,4,0,0,dp)<<"\n";
    
    // iterative
    cout<<mincost_iter(cost,4,dp)<<"\n";

    return 0;
}