// given n and i - set all bits from least significant bit (right most) to ith bit to 0 
// eg - n=5 => 0101 ,i=1
// return -> 0100

#include<bits/stdc++.h>
using namespace std;

int clear_upto_i(int n,int i){
    int mask=~((1<<(i+1))-1);
    return n&mask;
}

int main(){
    int n,i;
    cin>>n>>i;
    cout<<clear_upto_i(n,i);
}