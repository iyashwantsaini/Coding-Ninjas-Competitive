/*
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)
B) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)  + (2 ^ 2)
C) (1^1) + (1^1) + (1^1) + (1^1) + (2 ^ 2) + (2 ^ 2)
D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/

#include <bits/stdc++.h>
using namespace std;

int findmin_rec(int n,int *dp){
    // if its a perfect square then count=1
    if(ceil(sqrt(n))==sqrt(n)){
		return 1;
	}
	// only possible combination if sum of 1's
	if(n<=3){
		return n;
	}
	// n>3
    //if work already done
    if(dp[n]>0){
        return dp[n];
    }
	// max count can be n itself (sum of 1's)
	int count=n;
    for(int i=1;i<=n;i++){
        int sq=i*i;
        // can't be added to our ans
        if(sq>n){
            break;
        }
        // if i include the num count will be increased by 1
        // if i dont include the num my count will remain same as count which is currently n
        count=min(count,1+findmin_rec(n-sq,dp));
    }
    dp[n]=count;
    return count;
}

int findmin_iter(int n,int *dp){
    if(ceil(sqrt(n))==sqrt(n)){
        return 1;
    }
    if(n<=3){
        return n;
    }

    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;

    for(int i=3;i<=n;i++){
        int count=i;
        for(int j=1;j<=i;j++){
            int sq=j*j;
            if(sq>i){
                break;
            }
            count=min(count,1+dp[i-sq]);
        }
        dp[i]=count;
    }

    return dp[n];
}

int minCount(int n)
{
    // rec approach
	// int *dp=new int[10000+1]{};
    // int ans = findmin_rec(n,dp);
    // delete dp;
    // return ans;

    // iter approach
    int *dp=new int[1000+1]{};
    int ans = findmin_iter(n,dp);
    delete dp;
    return ans;
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}