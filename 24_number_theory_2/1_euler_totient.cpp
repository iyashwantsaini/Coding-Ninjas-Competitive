/*
phi(n) => count of all m (1<=m<n) which are less than n and gcd(m,n)==1 | (coprime with n)
n => can be represented as => (p1^a1)*(p2^a2)*(p3^a3)..
phi(n) => phi(p1^a1)*phi(p2^a2)*phi(p3^a3)..
phi(p^a)= p^a * [1-(1/p)]
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int n;
    cin>>n;
    // sieve => will store phi(n) at each index
    int *sieve=new int[n+1];
    for(int i=0;i<=n;i++){
        sieve[i]=i;
    }
    // fill sieve
    for(int i=2;i<=n;i++){
        // if prime => then only do work
        if(sieve[i]==i){
            sieve[i]=i-1;
            for(int j=2*i;j<=n;j+=i){
                sieve[j]=(sieve[j]*(i-1))/i;
            }
        }
    }
    cout<<sieve[n]<<"\n";
    return 0;
}