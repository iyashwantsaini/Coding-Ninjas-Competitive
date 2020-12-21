/*
used for solving higher power problems which cross ranges
pow(a,b,c) => (a^b)%c => in O(log(n))
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int power_(ll a,ll b,ll c){
    ll ans=1;

    while(b!=0){
        // get right most bit of b
        int bit=b&1;
        if(bit==1){
            // need to add to ans
            ans=(ans*a)%c;
        }
        // a=a^2 for next left bit
        a=a*a;
        // get next set left bit from b
        // b=b>>1;
        // OR
        b=b/2;
    }

    return (int)ans;
}

int main(){
    ll a,b,c;
    a=2;
    b=10;
    c=5;
    cout<<power_(a,b,c);
    return 0;
}