/*
Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.
Note: gcd ( a , b ) is the greatest common divisor of integers a and b .
Input format
Input contains single integer n ( 1 ≤ n ≤ 2 * 10^6) — the size of permutation p p.
Output format
Print n integers — array a .
Sample Input:
5
Sample Output:
5 4 2 3 1
Explanation
It's needed 4 iterations to create array a:
Add 5
Add 4 and 2
Add 3
Add 1
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n;
    cin>>n;
    // make a sieve with all numbers having thier lowest prime divisor
    ll *sieve=new ll[n+2]{};
    for(ll i=0;i<=n;i++){
        sieve[i]=i;
    }
    for(ll i=2;i<=n;i++){
        for(ll j=1;i*j<=n;j++){
            ll el_=i*j;
            if(sieve[el_]==el_){
                sieve[el_]=i;
            }
        }
    }
    // for(ll i=0;i<=n;i++){
    //     cout<<sieve[i]<<" ";
    // }cout<<"\n";

    ll *mark=new ll[n+2]{};
    for(ll i=n;i>=1;i--){
        // vector for storing results of every iteration
        vector<ll> v;
        ll lpd=sieve[i]; // lowest prime divisor
        // do work if not already done
        if(mark[i]==0){
            ll n_bakup=i;
            // storing current num
            v.push_back(n_bakup);
            mark[n_bakup]=1;
            // do while work for all prime multiples of current num is done
            while(n_bakup!=1){
                ll n_temp=i;
                // mark all multiples of current lpd as true
                while(n_temp!=lpd){
                    n_temp-=lpd;
                    if(mark[n_temp]==0){
                        mark[n_temp]=1;
                        v.push_back(n_temp);
                    }
                }
                // find next bigger lpd for num
                while(n_bakup%lpd==0){
                    n_bakup/=lpd;
                }
                // mark new lpd of current num from sieve
                lpd=sieve[n_bakup];
            }
        }
        // sort and print vector for current num
        sort(v.begin(),v.end(),greater<ll>());
        // print vector
        for(ll i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }
    delete sieve;
    delete mark;
    return 0;
}