/*
Fill The Matrix
A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.

You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.
Input
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains two space separated integers N, Q.

Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.
Output
For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.
Constraints
1 ≤ T ≤ 10^6
2 ≤ N ≤ 10^5
1 ≤ Q ≤ 10^6
1 ≤ i, j ≤ N
0 ≤ val ≤ 1
Sum of each of N, Q over all test cases doesn't exceed 106
Input
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1
Output
yes
no
yes
no
*/

// https://www.codechef.com/SEPT17/problems/FILLMTR
// https://www.youtube.com/watch?v=WKUJvVJEsBM
// still incomplete

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int **b=new int*[n+1];
        for(int i=0;i<=n;i++){
            b[i]=new int[n+1];
            for(int j=0;j<=n;j++){
                b[i][j]=-1;
            }
        }
        while(q--){
            int i,j,val;
            cin>>i>>j>>val;
            b[i][j]=val;
        }


        // basic sanity checks
        // diagonals must be all 0 as a->a distance is always 0
        int flag=1;
        for(int i=1;i<=n;i++){
            if(b[i][i]==1){
                flag=0;
                break;
            }
        }
        if(flag==0){
            cout<<"no\n";
            continue;
        }
        flag=1;
        // b[i][j] and b[j][i] must have the same value for A to exist
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(b[i][j]!=b[j][i]){
                    flag=0;
                    break;
                }
            }
            if(flag==0){
                break;
            }
        }
        if(flag==0){
            cout<<"no\n";
            continue;
        }

        

    }
    return 0;
}