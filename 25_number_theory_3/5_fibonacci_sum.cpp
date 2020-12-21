/*
The fibonacci sequence is defined by the following relation:
 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
Input Format :
Two non-negative integers N and M. (N <= M)
N<=10^9, M<=10^9
Output Format :
A single line containing the answer for the task.
Sample Input :
10 
19
Sample Output :
10857
*/

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define mod 1000000007

void multiply(ll A[2][2],ll M[2][2]){
    // find all 4 values and put back in an A
    ll first=A[0][0]*M[0][0]+A[0][1]*M[1][0];
    ll second=A[0][0]*M[0][1]+A[0][1]*M[1][1];
    ll third=A[1][0]*M[0][0]+A[1][1]*M[1][0];
    ll fourth=A[1][0]*M[0][1]+A[1][1]*M[1][1];
    A[0][0]=first%mod;
    A[0][1]=second%mod;
    A[1][0]=third%mod;
    A[1][1]=fourth%mod;
}

void power_(ll A[2][2],ll n){
    if(n==0||n==1){
        return;
    }
    // find A^(n/2)
    power_(A,n/2);
    // find A^n my multiplying A^n/2*A^n/2
    multiply(A,A);
    // if odd multiply with A again
    if(n%2!=0){
        ll M[2][2]={{1,1},{1,0}};
        multiply(A,M);
    }
}

ll fib(ll n){
    ll A[2][2]={{1,1},{1,0}};
    if(n==0){
        return 0;
    }
    power_(A,n-1);
    // after A^n-1 our ans i.e f(n) will be stored at [0][0] index
    return A[0][0]%mod;
}

unsigned long long fiboSum(unsigned long long m,unsigned long long n){
    // as N,M<=10^9 linear O(n) operation can't be done
    // we'll need two values to find the rest of the series of fibonacci
    // as fib(n)=fib(n-1)+fib(n-2)
    // so fib(1)+fib(2)+fib(3)....fib(5)=fib(5+2)-fib(1+1)
    return (fib(n + 2)%mod - fib(m + 1)%mod+mod)%mod;
}

int main(){
    unsigned long long m,n;
    cin>>m>>n;
	cout<<fiboSum(m,n);
    return 0;
}
