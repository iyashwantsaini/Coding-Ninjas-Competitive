/*
Given a number N, find number of primes in the range [1,N].
Input:
The only line of input consists of a number N
Output:
Print the number of primes in the range [1,N].`
Constraints:
1≤N≤1000000
Sample Input :
3 
Sample Output -
2
*/

// method => sieve of eratosthenes

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
   
int main(){
    int n;
    cin>>n;
    int count=0;
    // sieve for storing primes
    int *sieve=new int[n+1];
    for(int i=0;i<=n;i++){
        sieve[i]=1;
    }
    // 0 and 1 are not primes
    sieve[0]=0;
    sieve[1]=0;
    // we only need to go i from 2 to root(N)
    // j will cover all the the rest from root(N) to N
    for(int i=2;i*i<=n;i++){
        // if already known => no need ot check
        if(sieve[i]==0){
            continue;
        }
        // if sieve is 1 => means its a prime
        // set all the primes of this i to 0 as well
        for(int j=i*i;j<=n;j+=i){
            sieve[j]=0;
        }
    }
    // count 1's
    for(int i=1;i<=n;i++){
        if(sieve[i]==1){
            count+=1;
        }
    }
    cout<<count<<"\n";
	return 0;
}