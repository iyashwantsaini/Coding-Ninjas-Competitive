/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1,2), (1,3) and (2,2).
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int find_ans(int den[],int start,int size,int curr_val,int goal,int **storage){
  // base cases
  // current val greater than goal
  if(curr_val>goal){
    return 0;
  }
  // goal value reached
  if(curr_val==goal){
    return 1;
  }
  // checked all denominations
  if(start==size){
    return 0;
  }
  if(storage[size-start][curr_val]>0){
    return storage[size-start][curr_val];
  }
  // starting element of den included
  int leftpossible=find_ans(den,start,size,curr_val+den[start],goal,storage);
  // starting element of den not included
  int rightpossible=find_ans(den,start+1,size,curr_val,goal,storage);
  storage[size-start][curr_val]=leftpossible+rightpossible;
  return leftpossible+rightpossible;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
  sort(denominations,denominations+numDenominations);
  int **storage=new int*[numDenominations+1];
  for(int i=0;i<numDenominations+1;i++){
    storage[i]=new int[value+1];
  }
  // set all storage elements to -1
  for(int i=0;i<numDenominations+1;i++){
    for(int j=0;j<value+1;j++){
      storage[i][j]=-1;
    }
  }
  int ans=find_ans(denominations,0,numDenominations,0,value,storage);
  for(int i=0;i<numDenominations+1;i++){
    delete storage[i];
  }
  delete storage;
  return ans;
}

int main(){
  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;
  cout << countWaysToMakeChange(denominations, numDenominations, value);
  return 0;
}


