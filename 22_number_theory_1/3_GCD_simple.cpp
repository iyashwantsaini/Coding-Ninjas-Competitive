/*
Calculate and return GCD of two given numbers x and y. Numbers are within range of Integer.
Input format :
x and y (separated by space)
Output format :
GCD of x and y
Sample Input 1:
20 
5
Sample Output 1:
5
Sample Input 2:
96 
14
Sample Output 2:
2
*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    int gcd_=1;
    for(int i=2;i<=min(a,b);i++){
        // updating gcd if => current i divisible by both
        if((a%i==0)&&(b%i==0)){
            gcd_=i;
        }
    }
    return gcd_;
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}
