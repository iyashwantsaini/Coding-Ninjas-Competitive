/*
Given n, calculate and print the sum :
LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
Input Format :
Line 1 : Integer n
Output Format :
Required sum
Constraints :
1 <= T <= 300000
1 <= n <= 1000000
Sample Input 1 :
5
Sample Output 1 :
55
Sample Input 2 :
2
Sample Output 2 :
4
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a,ll b){
    // special case
    if(a<b){
        return gcd(b,a);
    }
    // base case
    if(b==0){
        return a;
    }
    // recursive case
    return gcd(b,a%b);
}

void func(long long n){
    ll ans=0;
    for(int i=1;i<=n-1;i++){
        ans+=((n*n)/gcd(i,n));
    }
    ans+=2*n;
    ans/=2;
    cout<<ans<<"\n";
}

int main(){
    long long n;
    scanf ( "%lld", &n );
	func(n);
    return 0;
}