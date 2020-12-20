/*
In this problem you have to print all primes from given interval.
Input
t - the number of test cases, then t lines follows. [t <= 150]
On each line are written two integers L and U separated by a blank. L - lower bound of 
interval, U - upper bound of interval. [2 <= L < U <= 2147483647] [U-L <= 1000000].
Output
For each test case output must contain all primes from interval [L; U] in increasing order.
Sample Input:
2
2 10
3 7
Sample Output:
2
3
5
7
3
5
7 
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAX 100001

// we'll create a sieve from 0 to root(r)
// max value of root(r) can be 100001
vector<int> *make_sieve(){
	int sieve[MAX];
	// set all one
	for(int i=0;i<MAX;i++){
		sieve[i]=1;
	}	
	// set multiples of primes as 0
	for(int i=2;i*i<MAX;i++){
		if(sieve[i]==1){
			for(int j=i*i;j<MAX;j+=i){
				sieve[j]=0;
			}
		}
	}
	vector<int> *v=new vector<int>;
	for(int i=2;i<MAX;i++){
		if(sieve[i]==1){
			v->push_back(i);
		}
	}
	return v;
}

void print_primes(int l,int r,vector<int> *primes){
	int *sieve=new int[r-l+1];
	for(int i=0;i<=r-l;i++){
		sieve[i]=1;
	}
	// for all primes mark multiples in l to r as 0
	for(int i=0;primes->at(i)*(ll)primes->at(i)<=r;i++){
		// we'll find the minimum closer value from which we'll start working for every prime using => (num/i)*i
		// (get just smaller or equal value required)
		ll curr_prime=primes->at(i);
		ll base=(l/curr_prime)*curr_prime;
		if(base<l){
			base+=curr_prime;
		}
		for(ll j=base;j<=r;j+=curr_prime){
			sieve[j-l]=0;
		}
		// special case
		// eg (2/3)*3 will become 0
		// base+curr_index will become current_prime
		if(base==curr_prime){
			sieve[base-l]=1;
		}
	}
	// print all those which are prime
	for(int i=0;i<=r-l;i++){
		if(sieve[i]==1){
			cout<<i+l<<"\n";
		}
	}
}

int main(){
    ll t;
	cin>>t;
	vector<int> *sieve=make_sieve();
	while(t--){
		ll l,u;
		cin>>l>>u;
		print_primes(l,u,sieve);
	}
	return 0;
}