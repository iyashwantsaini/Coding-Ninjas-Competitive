/*
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input
The first line contains T, number of testcases.
T lines follows each containing the number N.
Output
Print T lines of output each containing the answer.
Constraints
1 <= T <= 500
0 <= N <= 50000
Sample Input:
3
2
3
4
Sample Output:
2
4
8
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

ll divisors(ll n){
	// create sieve for storing primes upto n
	int *sieve=new int[n+2];
	for(ll i=0;i<=n;i++){
		sieve[i]=1;
	}
	sieve[0]=0;
	sieve[1]=0;
	for(ll i=2;i*i<=n;i++){
		if(sieve[i]==1){
			for(int j=i*i;j<=n;j+=i){
				sieve[j]=0;
			}
		}
	}

	// now process for each prime
	ll divi_=1;
	for(ll i=2;i<=n;i++){
		// if prime
		if(sieve[i]==1){
			// find how many times this primes comes from 1 to n
			ll presence_num=0;
			for(ll j=1;pow(i,j)<=n;j++){
				ll ipoj=pow(i,j);
				presence_num+=( n/ipoj );
			}
			// add this count to the divisors
			divi_=(divi_%mod*(presence_num+1)%mod)%mod;
		}
	}

	// delete sieve;
	return divi_;
}

int main(){
    ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cout<<divisors(n)<<"\n";
	}
	return 0;
}