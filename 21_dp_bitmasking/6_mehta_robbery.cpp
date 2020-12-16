/*
One fine day, when everything was going good, Mehta was fired from his job and had to leave all the work. So, he decided to become a member of gangster squad and start his new career of robbing. Being a novice, mehta was asked to perform a robbery task in which he was given a bag having a capacity W units. So, when he reached the house to be robbed, there lay N items each having particular second and particular first associated with it. But, theres a twist associated, He has first 10 primes with him, which he can use atmost once, if he picks any item x, then he can multiply his first[x] with any of the first 10 primes and then put that item into his bag. Each prime can only be used with one particular item and one item can only have atmost one prime multiplied with its first. Its not necessary to pick all the items. If he doesnt want to use a prime with any particular item, he can simply add the first as it is, more specifically, 1*first[x] for xth item will get added to its total first, and that he can do with as many items as he wants. He cannot fill his bag more than second W units. Each item should be picked with its whole second, i.e it cannot be broken into several other items of lesser second. So, now to impress his squad, he wishes to maximize the total first he can achieve by robbing this wealthy house.
Input:
First Line of input containts two integers N and W. Next N lines contain information of ith item, describing first and second of the ith item, first and second are separated by single space.
Output:
In a single line, output the maximum first obtainable.
Constraints:
1 <= N <= 2000, 1 <= W <= 2000
1 <= first[i] <= 10^9, 1 <= second[i] <= 2000
SAMPLE INPUT
3 4
1 1
2 1
3 1
SAMPLE OUTPUT
152
Explanation:
As all, the items can be picked, so maximum first is equal to = 1 X 19 + 2 X 23 + 3 X 29 = 152
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll max_profit(ll n,ll w,ll ***dp,pair<ll,ll> *items){
    // sorting on basis of second
    sort(items,items+n);
    
    // 1 is not a prime => just a dummy
    int primes[11]={1,2,3,5,7,11,13,17,19,23,29};

    // base case
    // => suppose it was not a primes problem => use simple knapsack
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            // fill the base for each iteration => 2 possibilities
            // not included
            dp[0][i][j]=dp[0][i-1][j];
            // include only if second less than current required
            if(j>=items[i-1].second){
                dp[0][i][j]=max(dp[0][i][j],dp[0][i-1][j-items[i-1].second]+items[i-1].first);
            }
        }
    }

    // go to each prime and try to include it
    for(int prime=1;prime<=10;prime++){
        // p => for 1=>1 , 2=>0, 3=>1, 4=>0 ..
        int p=prime%2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                // 1=>not including
                dp[p][i][j]=dp[p][i-1][j];
                // 2=>including
                // including 2 cases => without prime, with prime
                if(j>=items[i-1].second){
                    dp[p][i][j]=
                    max(
                        dp[p][i][j],
                        max(
                            dp[p][i-1][j-items[i-1].second]+items[i-1].first,
                            dp[p^1][i-1][j-items[i-1].second]+items[i-1].first*primes[prime]
                            )
                    );
                }
            }
        }
    }
    // last 10 index => 10%2=0
    // so ans will be stored at 0th index
    return dp[0][n][w];
}

int main(){
    ll n,w;
    cin>>n>>w;
    pair<ll,ll>*arr=new pair<ll,ll>[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    // DP storage
    // we need only p,p-1 at a time
    // so we'll create only 2 indices and use XOR to toggle
    ll ***dp=new ll**[2];
    dp[0]=new ll*[n+1];
    dp[1]=new ll*[n+1];
    for(int i=0;i<=n;i++){
        dp[0][i]=new ll[w+1];
        dp[1][i]=new ll[w+1];
        for(int j=0;j<=w;j++){
            dp[0][i][j]=0;
            dp[1][i][j]=0;
        }
    }
    cout<<max_profit(n,w,dp,arr)<<"\n";
    return 0;
}

