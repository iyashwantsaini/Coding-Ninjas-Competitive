// check if num is even or odd
// just check last bit

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if((n&1)==1){
        cout<<"Odd";
    }else{
        cout<<"Even";
    }
}