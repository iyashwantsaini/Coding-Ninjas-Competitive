/*
Daulat Ram is an affluent business man. After demonetization, IT raid was held at his accommodation in which all his money was seized. He is very eager to gain his money back, he started investing in certain ventures and earned out of them. On the first day, his income was Rs. X, followed by Rs. Y on the second day. Daulat Ram observed his growth as a function and wanted to calculate his income on the Nth day.
The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
Given his income on day 0 and day 1, calculate his income on the Nth day (yeah Its that simple).
Input:
The first line of input consists of a single integer T denoting number of test cases.

Each of the next T lines consists of three integers F0, F1 and N respectively.
Output:
For each test case, print a single integer FN, as the output can be large, calculate the answer modulo 10^9+7.
CONSTRAINTS:
1 ≤ T ≤ 10^5

0 ≤ F0, F1, N ≤ 10^9
Sample Input :
2
0 1 2
1 2 4
Sample Output:
1
107
Explanation
In the second test case his income on day 0 is 1 and the income on day 1 is 2. We need to calculate his income on day 4.
F0=1
F1=2
F2=1 + 2 + 1×2 = 5
F3=2 + 5 + 2×5 = 17
F4=5 + 17 + 5×17 = 107
*/

#include<bits/stdc++.h>
using namespace std;
#define m 1000000006
#define m1 1000000007
typedef long long int ll;

void multiply(ll A[2][2],ll M[2][2]){
    // find all 4 values and put back in an A
    ll first=((A[0][0]%m)*(M[0][0]%m)+(A[0][1]%m)*(M[1][0]%m))%m;
    ll second=((A[0][0]%m)*(M[0][1]%m)+(A[0][1]%m)*(M[1][1]%m))%m;
    ll third=((A[1][0]%m)*(M[0][0]%m)+(A[1][1]%m)*(M[1][0])%m)%m;
    ll fourth=((A[1][0]%m)*(M[0][1]%m)+(A[1][1]%m)*(M[1][1]%m))%m;
    A[0][0]=first;
    A[0][1]=second;
    A[1][0]=third;
    A[1][1]=fourth;
}

void power_(ll A[2][2],ll n){
    if(n==1){
        return;
    }
    // find A^(n/2)
    power_(A,n/2);
    // find A^n my multiplying A^n/2*A^n/2
    multiply(A,A);
    // if odd multiply with A again
    if(n%2!=0){
        ll M[2][2]={{1,1},{1,0}};
        multiply(A,M);
    }
}

ll fib(ll n){
    if(n==0||n==1){
        return 1;
    }
    ll A[2][2]={{1,1},{1,0}};
    power_(A,n-1);
    // after A^n-1 our ans i.e f(n) will be stored at [0][0] index
    return A[0][0];
}

ll power_modular(ll a,ll x){
  if(x==0){
    return 1;
  }
  if(x%2==0){
    return power_modular((a*a)%m1,x/2);
  }
  else{
    return ((a%m1)*power_modular((a*a)%m1,(x-1)/2)%m1)%m1;
  }
}

int main() {
	ll t,f0,f1,n;
	cin>>t;
	while(t--){
		cin>>f0>>f1>>n;
		if(n==0){
			cout<<f0<<"\n";
		}else if(n==1){
			cout<<f1<<"\n";
		}else{
			// get fib(n-1), fib(n) using matrix exponentiation
			ll fibn_m1=fib(n-1)%m;
			ll fibn=fib(n)%m;
			// get a^(fib(n-1)%(m-1))%m, b^(fib(n)%(m-1))%m using modular exponentiation
			ll one=power_modular(f0+1,fibn_m1)%m1;
			ll two=power_modular(f1+1,fibn)%m1;
			ll ansfinal=((one%m1)*(two%m1))%m1;
			ansfinal=(ansfinal-1+m1)%m1;
			cout<<ansfinal<<"\n";
		}
	}
	return 0;
}