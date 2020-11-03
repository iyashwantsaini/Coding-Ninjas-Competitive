/*
Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
N, M, K <= 100.
Input
Line 1:    N M

Line 2:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next city.
Output
Single Line containing the minimum amount of fare that Jack has to give.

Sample Input
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9

Sample Output
10
*/

#include <bits/stdc++.h>
using namespace std;

int minfair(int n,int m,int bp[101][101],int dp[101][101],int curr_n,int curr_m){
    // cout<<bp[curr_n][curr_m]<<endl;    
    // base cases
    
    // no more cities left
    if(curr_n==n){
        return 0;
    }
    
    //if work done
    if(dp[curr_n][curr_m]!=-1){
        return dp[curr_n][curr_m];
    }
    
    // for each index their are 3 possibilities
    // take same index bus
    int opt1=minfair(n,m,bp,dp,curr_n+1,curr_m);
    // take index-1th bus if possible
    int opt2=INT_MAX;
    if(curr_m-1>=0){
    	opt2=minfair(n,m,bp,dp,curr_n+1,curr_m-1);
    }
    // take index+1th bus
    int opt3=INT_MAX;
    if(curr_m+1<m){
    	opt3=minfair(n,m,bp,dp,curr_n+1,curr_m+1);
    }
    // return whichever returns min value
    int ans=min(opt1,min(opt2,opt3));
    // cout<<ans<<endl;
    dp[curr_n][curr_m]=bp[curr_n][curr_m]+ans;
    return dp[curr_n][curr_m];
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    //bus prices
    int bp[101][101];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>bp[i][j];
        }
    }
    //dp -to avoid repetition
    int dp[101][101];
    memset(dp,-1,101*101*sizeof(int));
    int minval=INT_MAX;
    for(int i=0;i<m;i++){
    	int min_current=minfair(n,m,bp,dp,0,i);
        if(min_current<minval){
            minval=min_current;
        }
    }
    cout<<minval<<endl;
    return 0;
}
