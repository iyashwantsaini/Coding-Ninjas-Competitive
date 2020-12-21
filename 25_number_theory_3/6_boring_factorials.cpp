/*
Sameer and Arpit want to overcome their fear of Maths and so they have been recently practicing Maths problems a lot. Aman, their friend has been helping them out. But as it goes, Sameer and Arpit have got bored of problems involving factorials. Reason being, the factorials are too easy to calculate in problems as they only require the residue modulo some prime and that is easy to calculate in linear time. So to make things interesting for them, Aman - The Mathemagician, gives them an interesting task. He gives them a prime number P and an integer N close to P, and asks them to find N! modulo P. He asks T such queries.
Input
First line contains an integer T, the number of queries asked.

Next T lines contains T queries of the form “N P”. (quotes for clarity)
Output
Output exactly T lines, containing N! modulo P.
Constraints:
1 <= T <= 1000

1 < P <= 2*10^9

1 <= N <= 2*10^9

Abs(N-P) <= 1000
Sample Input:
3
2 5
5 11
21 71
Sample Output:
2
10
6
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll modular_exp(ll a,ll b,ll c){
	// base cases
	if(a==0){
		return 0;
	}
	if(b==0){
		return 1;
	}
	ll ans;
	// if even
	if(b%2==0){
		ll smallans=modular_exp(a,b/2,c);
		ans=(smallans*smallans)%c;
	}
	// if odd
	else{
		ll smallans=modular_exp(a,b-1,c);
		ans=a%c;
		ans=(ans*smallans)%c;
	}
	return ans;
}

int main() {
	ll t;
	cin>>t;
	while(t--){
		ll n,p;
		cin>>n>>p;
		// handling basic cases
		if(n>=p){
			cout<<0<<"\n";
			continue;
		}
		// n<p
		// multiply n! with numbers from n+1 to p-1 => to use (p-1)!%p=-1
		// so n!%p=-1*((n+1)^(-1))%p*((n+2)^(-1))%p....((p-1)^(-1))%p
		// a^(-1)%p=a^(p-2)%p
		ll fact=1;
		for(ll i=n+1;i<=p-1;i++){
			// ans=ans*modular_exp(i,p-2,p);
			fact=(fact*i)%p;
			if(fact==0){
				break;
			}
		}
		ll ans=modular_exp(fact,p-2,p);
		cout<<p-ans<<"\n";
	}
	return 0;
}