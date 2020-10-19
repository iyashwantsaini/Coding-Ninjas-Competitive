#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fib_dp_rec(int n, ll storage[]){
    if(n==0||n==1){
        return storage[n];
    }
    if(storage[n]!=0){
        return storage[n];
    }
    ll ans=fib_dp_rec(n-1,storage)+fib_dp_rec(n-2,storage);
    storage[n]=ans;
    return ans;
}

ll fib_dp_iter(int n,ll storage[]){
    for(int i=2;i<=n;i++){
        storage[i]=storage[i-1]+storage[i-2];
    }
    return storage[n];
}

int main(){
    int n;
    cin>>n;
    ll storage[n+1]{};
    // as we know fib(0)=1, fib(1)=1
    storage[0]=1;
    storage[1]=1;
    cout<<fib_dp_rec(n,storage)<<endl;
    cout<<fib_dp_iter(n,storage)<<endl;
}