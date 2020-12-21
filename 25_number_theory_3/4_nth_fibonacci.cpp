/*
eg f(8)=21 => in O(log(n))
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
    A[0][0]=first;
    A[0][1]=second;
    A[1][0]=third;
    A[1][1]=fourth;
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
    return A[0][0];
}

int main(){
    cout<<fib(8)<<"\n";
    return 0;
}