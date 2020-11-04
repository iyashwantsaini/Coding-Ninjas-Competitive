/*
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.
Input Format :
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Sample Input :
babab
babba
Sample Output :
3
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll helper(string S,string V,int **dp){
    int n=S.length();
    int m=V.length();
    // base cases
    if(n==0){
        return 1001;
    }
    if(m<=0){
        return 1;
    }
    // work already done
    if(dp[n][m]>=0){
        return dp[n][m];
    }
    
    // for each index of S, we can either include it or not
    
    // not include
    ll opt1=helper(S.substr(1),V,dp);
    
    // include
    // find index of S[0] in V
    int index=0;
    for(index=0;index<m;index++){
        if(S[0]==V[index]){
            break;
        }
    }
    // if num is not found in string, then 1 option in possible
    if(index==m){
        return 1;
    }
    ll opt2=1+helper(S.substr(1),V.substr(index+1),dp);
    ll ans=min(opt1,opt2);
    dp[n][m]=ans;
    return ans;
}

int solve(string S,string V){
    int n=S.length();
    int m=V.length();
	int **dp=new int* [n+1];
    for(int i=0; i<n+1; i++)
    {
        dp[i]=new int [m+1];
        for(int j=0; j<m+1; j++)
        {
            dp[i][j]=-1;
        }
    }
	int ans= helper(S,V,dp);
    for(int i=0;i<=n;i++){
        delete dp[i];
    }
    delete dp;
    return ans;
}