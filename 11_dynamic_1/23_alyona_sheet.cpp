/*
During the lesson small girl Alyona works with one famous spreadsheet computer program and learns how to edit tables.
Now she has a table filled with integers. The table consists of n rows and m columns. By ai, j we will denote the integer located at the i-th row and the j-th column. We say that the table is sorted in non-decreasing order in the column j if ai, j ≤ ai + 1, j for all i from 1 to n - 1.
Teacher gave Alyona k tasks. For each of the tasks two integers l and r are given and Alyona has to answer the following question: if one keeps the rows from l to r inclusive and deletes all others, will the table be sorted in non-decreasing order in at least one column? Formally, does there exist such j that ai, j ≤ ai + 1, j for all i from l to r - 1 inclusive.
Alyona is too small to deal with this task and asks you to help!
Input
The first line of the input contains two positive integers n and m (1 ≤ n·m ≤ 100 000) — the number of rows and the number of columns in the table respectively. Note that your are given a constraint that bound the product of these two integers, i.e. the number of elements in the table.

Each of the following n lines contains m integers. The j-th integers in the i of these lines stands for ai, j (1 ≤ ai, j ≤ 109).

The next line of the input contains an integer k (1 ≤ k ≤ 100 000) — the number of task that teacher gave to Alyona.

The i-th of the next k lines contains two integers li and ri (1 ≤ li ≤ ri ≤ n).
Output
Print "Yes" to the i-th line of the output if the table consisting of rows from li to ri inclusive is sorted in non-decreasing order in at least one column. Otherwise, print "No".
Sample Input
5 4
1 2 3 5
3 1 3 2
4 5 2 3
5 5 3 2
4 4 3 4
6
1 1
2 5
4 5
3 5
1 3
1 5
Sample Output
Yes
No
Yes
Yes
Yes
No
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // inputs
    int n,m,k;
    cin>>n>>m;
    int table[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>table[i][j];
        }
    }
    cin>>k;

    // logic
    // we can take a 2D dp array
    // in each index we'll save from which index to this current index is the column non decreasing
    int dp[n+1][m+1]{};
    // int 1st row all will be sorted from 1st row to 1st row
    for(int i=1;i<=m;i++){
        dp[1][i]=1;
    }


    // also take a 1d array to save the minimum of all rows
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(table[i][j]>=table[i-1][j]){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=i;
            }
        }
    }

    // save min of each row in a array
    int rowmin[n+1]{};
    for(int i=1;i<=n;i++){
        int minnum=INT_MAX;
        for(int j=1;j<=m;j++){
            if(dp[i][j]<minnum){
                minnum=dp[i][j];
            }
        }
        rowmin[i]=minnum;
    }

    while(k--){
        int l,r;
        cin>>l>>r;
        if(rowmin[r]<=l){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}