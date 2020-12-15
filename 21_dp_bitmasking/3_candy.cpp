/*
Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes.
Input Format :
Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
Next N lines : N integers describing the preferences of one student. 1 at i'th (0 <= i < N) position denotes that this student likes i'th candy , 0 means he doesn't.
Assume input to be 0-indexed based.
Output Format :
Return the number of ways Gary can distribute these N candies to his N students such that every student gets exactly one candy he likes.``
Sample Input:
3
1 1 1
1 1 1
1 1 1
Sample Output:
6
*/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 16
typedef long long ll;

ll solver_helper(int like[][MAXN],int n,ll *dp,int p,int mask){
    // base case
    if(p>=n){
        return 1;
    }
    if(dp[mask]!=-1){
        return dp[mask];
    }
    ll ans=0;
    // go to each index and see if assigning to the current person possible or not
    for(int i=0;i<n;i++){
        // check if candy not allocated and current person likes that candy
        if(!(mask&(1<<i))&&like[p][i]==1){
                ans+=solver_helper(like,n,dp,p+1,mask|(1<<i));
        }
    }
    dp[mask]=ans;
    return ans;
}

long long solve(int like[][MAXN],int N){
    ll *dp=new ll[(1<<N)];
    for(int i=0;i<(1<<N);i++){
        dp[i]=-1;
    }
    // start with 0 mask and with 0th person
    return solver_helper(like,N,dp,0,0);
}

int main(){
	int n,like[MAXN][MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			cin>>like[i][j];
		}
	}
	cout<<solve(like,n)<<endl;
}