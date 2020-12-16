/*
Gengar has got an integer N. Now using his ghostly powers, he can create the permutation from 1 to N of this given number.
Since, he's a special kind of Poke'mon, so he thinks he deserves special permutations. He wants to find the total number of special permutations of length N, consisting of the integers from 1 to N.

A permutation is called special if it satisfies following condition:
If Ap & Aq == Ap, then p < q, where p and q are two distinct indices of permutation and A is the permutation itself. "&" denotes the bitwise and operation.
Help Gengar in finding the number of such permutations.
Input format:
The only line of input will consist of a single integer N denoting the length of the permutation.
Output format:
Output the total number of special permutations of length N.

Constraints:
1 ≤ N ≤ 20
SAMPLE INPUT
4
SAMPLE OUTPUT
8

Explanation
All the special permutations of length 4 are: 
1 2 3 4
1 2 4 3
1 4 2 3
2 1 3 4
2 1 4 3
2 4 1 3
4 1 2 3
4 2 1 3
*/

#include <iostream>
using namespace std;
typedef long long ll;

ll permute(int n,int mask,ll *dp){
    // base case
    // so our total number of ways will be the total number of leaves
    // check for mask = 1111....
    if(mask==((1<<(n+1))-2)){
        return 1;
    }
    if(dp[mask]!=-1){
        return dp[mask];
    }
    ll ans=0;
    // try to assign values
    for(int i=1;i<=n;i++){
        // try to assign if mask is not set
        if( !(mask&(1<<i)) ){
            // check if x&y==x for all elemnts which are already set in current mask
            int flag=1;
            for(int j=1;j<=n;j++){
                // if that mask index is set
                if(mask&(1<<j)){
                    // check if given condition satisfies or not
                    if((i&j)==i){
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==1){
                // call with the new value of mask
                ans+=permute(n,mask|(1<<i),dp);
            }
        }
    }
    dp[mask]=ans;
    return ans;
}

int main(){
    int n;
    cin>>n;
    ll *dp=new ll[(1<<(n+1))]{};
    for(int i=0;i<(1<<(n+1));i++){
        dp[i]=-1;
    }
    ll ans=permute(n,0,dp);
    cout<<ans<<"\n";
    return 0;
}

