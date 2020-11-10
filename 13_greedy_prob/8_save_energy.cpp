// https://www.codechef.com/problems/SVENGY

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    // inputs
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    // logic
    // for i select next j based on conditions given
    // then make that j as i and move forward

    // we have to include the first always
    ll cost=0;
    // ll i=0;
    for(ll i=0;i<n-1;){
        ll j=i+1;
        for(;j<n-1;j++){
            if(
                (abs(a[i])>abs(a[j]))
                ||
                ((abs(a[i])==abs(a[j]))&&a[i]>0)
            ){
                break;
            }
        }
        cost += (j-i)*a[i] + ((j*j - i*i)*a[i]*a[i]);
        i=j;
    }
    cout<<cost<<endl;

}