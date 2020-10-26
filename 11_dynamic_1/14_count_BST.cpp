/* question to find catalan's number
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define m 1000000007

// int rec_soln(int n,ll *storage){
//   // base case
//   if(n==0||n==1) return 1;
//   ll total=0;
//   if(storage[n]>0){
//     return storage[n];
//   }
//   for(int k=1;k<=n;k++){
//     ll ans_left=rec_soln(k-1,storage);
//     storage[k-1]=ans_left;
//     ll ans_right=rec_soln(n-k,storage);
//     storage[n-k]=ans_right;
//     total += (ans_left*ans_right);
//     total = total%m;
//   }
//   int ans=(int)total;
//   return ans;
// }

int iter_soln(int n){
  ll *storage=new ll[n+1]{};
  storage[0]=1;
  storage[1]=1;

  for(int i=2;i<=n;i++){
    for(int j=0;j<i;j++){
      storage[i]+=storage[i-j-1]*storage[j];
      storage[i]=storage[i]%m;
    }
  }

  int final=(int)storage[n];

  delete storage;
  return final;
}

int countBST(int n)
{
  // recursive_soln
  // ll *storage=new ll[n+1]{};
  // return rec_soln(n,storage);
  // delete storage;

  // iterative soln 
  return iter_soln(n);
}

int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}


