/*
used for solving higher power problems which cross ranges
pow(a,b,c) => (a^b)%c => in O(log(n))
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int power_(ll x,ll n,ll c){
    // base cases
    if(x==0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    // if n even
    ll ans;
    if(n%2==0){
        ll smallans=power_(x,n/2,c);
        ans=(smallans*smallans)%c;
    }
    // if n odd
    else{
        ll smallans=power_(x,n-1,c);
        ans=x%c;
        ans=(ans*smallans)%c;
    }
    // removing negative value of ans if present
    // -a => (a+c)%c => +ve
    return (int)((ans+c)%c);
}

int main(){
    ll x,n,c;
    x=2;
    n=10;
    c=5;
    cout<<power_(x,n,c);
    return 0;
}