// https://codeforces.com/problemset/problem/1037/C

#include<bits/stdc++.h>
using namespace std;

int main(){

    // inputs
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;

    // logic
    int cost=0;
    for(int i=0;i<n;){
        if(a[i]!=b[i]){
            // swap - only if adjacent two in both strings are unequal 
            // else flipping is a better choice
            if(a[i]!=a[i+1]&&a[i+1]!=b[i+1]){
                swap(a[i],a[i+1]);
                i+=2;
                cost++;
            }
            // flip
            else{
                if(a[i]=='0'){
                    a[i]='1';
                }else{
                    a[i]='0';
                }
                cost++;
                i++;
            }
        }else{
            i++;
        }
    }
    cout<<cost<<endl;
}