/*
Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
Yes
*/

#include <bits/stdc++.h>
using namespace std;

bool subset_sum(int n,int s,int *el,bool **dp){
    // fill first row | n=0
    for(int i=1;i<=s;i++){
        dp[0][i]=0;
    }
    // fill first col | sum=0
    // at n=0,sum=0 | possibilities = 1 i.e select no element
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    
    // fill others using this
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            // check possibility
            if(el[i-1]<=j){
                // include
                bool opt1=dp[i-1][j-el[i-1]];
                // dont include
                bool opt2=dp[i-1][j];
                dp[i][j] = opt1||opt2;
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][s];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // inputs
    int n,sum;
    cin>>n;
    int *el=new int[n+1];
    for(int i=0;i<n;i++){
        cin>>el[i];
    }
    cin>>sum;
    // dp
    bool **dp=new bool*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new bool[sum+1]{};
    }
    // logic
    string ans=subset_sum(n,sum,el,dp)==0?"No":"Yes";
    cout<<ans<<endl;
}
