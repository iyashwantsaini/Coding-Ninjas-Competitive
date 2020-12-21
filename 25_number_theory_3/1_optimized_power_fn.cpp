/*
pow(x,n) in O(log(n))
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll power_(ll x,ll n){
    // base case
    if(n==1){
        return x;
    }
    // if even
    if(n%2==0){
        ll val=power_(x,n/2);
        return val*val;
    }
    // if odd
    else{
        ll val=power_(x,n/2);
        return val*val*x;
    }
}

int main(){
    ll x,n;
    cin>>x>>n;
    cout<<power_(x,n);
    return 0;
}
