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

// euclid's algo => gcd(a,b)=gcd(b,a%b);
int gcd(int a,int b){
    // this method works only if a>b
    // special case
    if(a<b){
        return gcd(b,a);
    }
    // base case
    if(b==0){
        return a;
    }
    // recursive case 
    return gcd(b,a%b);
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}
