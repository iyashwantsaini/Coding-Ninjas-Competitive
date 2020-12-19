/*
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
Input
Your input will consist of a single integer T followed by a newline and T test cases. Each test cases consists of a single line containing integers a, b, and n as described above.
Output
Output for each test case one line containing the number of n-factorful integers in [a, b].
Constraints
T < 10000

1 ≤ a ≤ b ≤ 10^6

0 ≤ n ≤ 10
Sample Input
5
1 3 1
1 10 2
1 10 3
1 100 3
1 1000 0
Sample Output
2 
2
0
8
1
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin>>t;
    // create sieve for storing number of distinct prime factors for each num
    int maxrange=1000000;
    int *sieve=new int[maxrange+1];
    for(int i=0;i<=maxrange;i++){
        sieve[i]=0;
    }
    for(int i=2;i<=maxrange;i++){
        // if sieve is 0 => means it is prime => do work
        if(sieve[i]==0){
            for(int j=1;j*i<=maxrange;j++){
                sieve[j*i]++;
            }
        }
    }
    // make table for storing number of 0<=n<=10 factors for every range
    int **table=new int*[11];
    for(int i=0;i<=10;i++){
        table[i]=new int[maxrange+1];
    }  
    // fill table
    for(int i=0;i<=10;i++){
        table[i][0]=0;
        table[i][1]=0;
        for(int j=2;j<=maxrange;j++){
            // check for this j in sieve if it matches the i
            if(sieve[j]==i){
                table[i][j]=table[i][j-1]+1;
            }else{
                table[i][j]=table[i][j-1];
            }
        }
    }
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        if(a==1&&n==0){
            cout<<"1\n";
            continue;
        }
        cout<<table[n][b]-table[n][a-1]<<"\n";
    }

    // delete storage
    // for(int i=0;i<=maxrange;i++){
    //     delete table[i];
    // }
    // delete table;
    // delete sieve;
	return 0;
}