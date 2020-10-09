// check if a number is power of 2 or not

// soln - if n is power of 2 then -> n&(n-1) will always be 0

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    // cout<<n<<" "<<n-1<<" "<<(n&(n-1));
    if(((n-1)&n)==0){
        cout<<"Yes it's a power of 2";
    }else{
        cout<<"No it's not a power of 2";
    }
}