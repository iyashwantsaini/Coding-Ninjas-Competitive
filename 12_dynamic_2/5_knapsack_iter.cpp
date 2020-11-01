/*
A thief robbing a store and can carry a maximal weight of W into his helper_. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/

#include<iostream>
using namespace std;
typedef long long ll;

// this solution is space optimized
// at any point we only use 2 arrays one for i and other for i-1 values
// so we can do this problem in o(W) complexity
ll helper_(int* weights, int* values, int n, int maxWeight){

    // we'll have only 2 columns and we'll keep putting 0'th values in 1'st posn after every step
    int dp[2][maxWeight+1];
    for(int i=0;i<=maxWeight;i++){
        dp[0][i]=0;
        dp[1][i]=0;
    }
    // fill 1st row
    // fill 1st col

    // filling all next using these
    for(int i=0;i<=n;i++){
        for(int j=0;j<=maxWeight;j++){

            if(i%2!=0){
                
                if(weights[i]<=j){
                    dp[1][j]=max( values[i]+dp[0][j-weights[i]] , dp[0][j] );
                }else{
                    dp[1][j]=dp[0][j];
                }
            }else{
                if(weights[i]<=j){
                    dp[0][j]=max( values[i]+dp[1][j-weights[i]] , dp[1][j] );
                }else{
                    dp[0][j]=dp[1][j];
                }
            }
        
        }
    }
    
    return dp[1][maxWeight];

}

// this solution is not space optimized, will not pass some test cases
// ll helper_(int* weights, int* values, int n, int maxWeight,ll **storage){

//     // fill 1st row
//     for(int i=0;i<=maxWeight;i++){
//         storage[0][i]=0;
//     }
//     // fill 1st col
//     for(int i=0;i<=n;i++){
//         storage[i][0]=0;
//     }

//     // filling all next using these
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=maxWeight;j++){
//             if(weights[i-1]<=j){
//                 storage[i][j]=max( values[i-1]+storage[i-1][j-weights[i-1]] , storage[i-1][j] );
//             }else{
//                 storage[i][j]=storage[i-1][j];
//             }
//         }
//     }
    
//     return storage[n][maxWeight];

// }

int knapsack(int* weights, int* values, int n, int maxWeight){
	ll ans=helper_(weights,values,n,maxWeight);
    // ll **storage=new ll*[n+1];
	// for(int i=0;i<=n;i++){
	//   storage[i]=new ll[maxWeight+1];
	// }
    // ll ans=helper_(weights,values,n,maxWeight,storage);
    // ans=(int)ans;
    // for(int i=0;i<=n;i++){
    //     delete storage[i];
    // }
    // delete storage;
    return ans;
}

int main(){

  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

}


