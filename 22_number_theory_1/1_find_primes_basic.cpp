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

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool checkprime(int n){
    int count=0;
    for(int j=1;j*j<=n;j++){
        if(n%j==0){
            if(j*j==n){
                count+=1;
            }else{
                count+=2;
            }
        }
    }
    if(count==2){
        return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int count=0;
    for(int i=2;i<=n;i++){
        if(checkprime(i)){
            count++;
        }
    }
    cout<<count<<"\n";
	return 0;
}