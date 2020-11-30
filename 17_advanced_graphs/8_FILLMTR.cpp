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

/* Steps
- check diagonals - all must be 0
- if a[i][j] & a[j][i] are not empty then they both must have same value
- make sets on basis of which all vertices have 0 as distance between them (equal valued vertices) using union find algorithm
    - each set can be be represented by a single number
- make edges between these sets based on 1 values
- no odd vertice cycle must exist - for this check if the new generated graph is bipartite or not
- if any of the conflict occurs print "NO" else print "YES" 
*/

/*
- method 2
- as this is a 2 color graph problem - black and white
- start coloring the first uncolored vertex with 0
- for all other vertices check if coloring is possible or not
*/

#include<bits/stdc++.h>
using namespace std;

bool paint(int v,int c,int *color,vector<pair<int,int>> *g ){
    // case 1 = if already colored with same color - possible
    if(color[v]==c){
        return true;
    }
    // case 2 = if already colored with diff colored than required - not possible
    if(color[v]!=-1){
        return false;
    }
    // case 3 = not colored
    color[v]=c;

    // now color the adjacent vertices of the current vertex
    for(auto i=g[v].begin();i!=g[v].end();i++){
        // check if painting possible
        // must be painted with diff color than the current
        if(!paint(i->first,(c+i->second)%2,color,g)){
            return false;
        }
    } 
    // if all can be painted
    return true;
}

void solve(){
    int n,q;
    cin>>n>>q;

    // pair will store - (i),(j,val)
    vector<pair<int,int>> *g=new vector<pair<int,int>>[n+1];
    // to store colors of all vertices
    int *color=new int[n+1];
    for(int i=1;i<=n;i++){
        color[i]=-1;
    }

    // ATQ if i is connected by j then j is also connected by i with same value
    while(q--){
        int i,j,val;
        cin>>i>>j>>val;
        g[i].push_back(make_pair(j,val));
        g[j].push_back(make_pair(i,val));
    }

    for(int i=1;i<=n;i++){
        // if vertex in uncolored, color it if possible
        if(color[i]==-1){
            // if coloring is not possible - conflict 
            if(!paint(i,0,color,g)){
                cout<<"no\n";
                return;
            }
        }
    }
    cout<<"yes\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}