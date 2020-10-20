/*
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic subsequence
Input Constraints:
1<= N <= 100000
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
Sample Input 3:
2
5 1
Sample Output 3:
2
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m=1000000007;

int longestBitonicSubarray(int *input, int n) {	
	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
    */
    if(n<=1){
        return 1;
    }
    // LIS - longest inc subseq
    int *lis=new int[n]{};
    lis[0]=1;
    for(int i=1;i<n;i++){
        lis[i]=1;
        for(int j=i-1;j>=0;j--){
            if(input[j]<input[i]){
                if(lis[j]+1>lis[i]){
                    lis[i]=(lis[j]+1)%m;
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<lis[i]<<" ";
    // }
    // cout<<endl;
    // LDS - longest dec subseq - starting from end
    // at each starting from end find lds from that point till end    
    int *lds=new int[n]{};
    lds[n-1]=1;
    for(int i=n-2;i>=0;i--){
        lds[i]=1;
        for(int j=i+1;j<n;j++){
            if(input[j]<input[i]){
                if(lds[j]+1>lds[i]){
                    lds[i]=(lds[j]+1)%m;
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<lds[i]<<" ";
    // }
    // cout<<endl;
    // LBS - longest bitcoin subarray
    // for each element find lax in left and max in right and add 1
    // return max of all elements in the end
    int *lbs=new int[n]{};
    lbs[0]=1;
    for(int i=1;i<n;i++){
        lbs[i]=1;
        int maxleft=INT_MIN;
        for(int j=i-1;j>=0;j--){
            if(lis[j]>maxleft){
                maxleft=lis[i];
            }
        }
        int maxright=INT_MIN;
        for(int j=i+1;j<n;j++){
            if(lds[i]>maxright){
                maxright=lds[i];
            }
        }
        if(maxright>1&&maxleft>1){
        	lbs[i]=((maxright+maxleft))%m;
        }
    }
    int maxoverall=INT_MIN;
    for(int i=0;i<n;i++){
        if(lbs[i]>maxoverall){
            maxoverall=lbs[i];
        }
    }
    delete lis;
    delete lds;
    delete lbs;
    return (maxoverall-1)%m;
}

int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}
