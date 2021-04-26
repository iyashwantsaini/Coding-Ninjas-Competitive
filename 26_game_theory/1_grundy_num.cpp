#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int wins=0;
    int turn=0;
    while(1){
        turn=turn==1?0:1;
        if(n==0){
            break;
        }
        n-=n/2==0?n/2:n/3==0?n/3:n/6==0?n/6:0;
    }
    return turn;
}