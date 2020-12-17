/*
According to Ancient Ninjas , string making is an art form . There are various methods of string making , one of them uses previously generated strings to make the new one . Suppose you have two strings A and B , to generate a new string C , you can pick a subsequence of characters from A and a subsequence of characters from B and then merge these two subsequences to form the new string.
Though while merging the two subsequences you can not change the relative order of individual subsequences. What this means is - suppose there two characters Ai and Aj in the subsequence chosen from A , where i < j , then after merging if i acquires position k and j acquires p then k<p should be true and the same apply for subsequence from C.
Given string A , B , C can you count the number of ways to form string C from the two strings A and B by the method described above. Two ways are different if any of the chosen subsequence is different .
As the answer could be large so return it after modulo 10^9+7 .
Input Format :
Line 1 : String A
Line 2 : String B
Line 3 : String C
Output Format :
The number of ways to form string C
Constraints :
1 <= |A|, |B|, |C| <= 50
Sample Input :
abc
abc 
abc
Sample Output :
8
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll find_ways(string a,string b,string c,int x,int y,int z,ll ***dp){
	// base cases
	if(z<=0){
		return 1;
	}
    if(x <= 0 && y <= 0){
        return 0;
    }
	// check in DP
	if(dp[x][y][z]!=-1){
		return dp[x][y][z];
	}

	ll ans=0;
	// find in a
    for(int i=x-1;i>=0;i--){
        if(a[i]==c[z-1]){
            ans=(ans+find_ways(a,b,c,i,y,z-1,dp))%mod;
        }
    }
	// find in b
    for(int i=y-1;i>=0;i--){
        if(b[i]==c[z-1]){
            ans=(ans+find_ways(a,b,c,x,i,z-1,dp))%mod;
        }
    }
    // store in DP
    dp[x][y][z]=ans;
    // return sum
    return ans;
}

int solve(string a,string b,string c){
	// DP
    ll ***dp=new ll**[a.length()+1];
	for(int i=0;i<=a.length();i++){
		dp[i]=new ll*[b.length()+1];
		for(int j=0;j<=b.length();j++){
			dp[i][j]=new ll[c.length()+1];
			for(int k=0;k<=c.length();k++){
				dp[i][j][k]=-1;
			}
		}
	}
	ll ans=find_ways(a,b,c,a.length(),b.length(),c.length(),dp);
	ans=ans%mod;
	return ans;
}


int main(){
	string a,b,c;
	cin>>a>>b>>c;
	cout<<solve(a,b,c)<<endl;
}