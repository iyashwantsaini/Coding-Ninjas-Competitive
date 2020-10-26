/*
Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.
He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?
Input Format :
Line 1 : Integer N 
Line 2 : A list of N integers
Output Format :
Maximum points Gary can recieve from the Game setup
Constraints :
1<=N<=10^5
1<=A[i]<=1000
Sample Input :
2
1 2
Sample Output :
2
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>A){
	// save freq of each element from 1 to n in A vector
	int *freq=new int[1000+1]{};
	for(int i=0;i<n;i++){
		freq[A[i]]++;
	}
	// create a dp array for saving max value till each index
	int *dp=new int[1000+1];
	// max sum of 0 elements = 0
	dp[0]=0;
	// max sum of 1 element = freq of that element * element
	dp[1]=1*freq[1];
	for(int i=2;i<=1000;i++){
		// if current value included in sum then i-1 th will not be included
		int ifincluded=i*freq[i]+dp[i-2];
		// else get value of i-1 th term 
		int notincluded=dp[i-1];
		dp[i]=max(ifincluded,notincluded);
	}
	// select max of all sums possible
	int maxnum=INT_MIN;
	for(int i=0;i<=1000;i++){
		if(dp[i]>maxnum){
			maxnum=dp[i];
		}
	}
	delete dp;
	delete freq;
	return maxnum;
}

int n;
vector<int>A;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}