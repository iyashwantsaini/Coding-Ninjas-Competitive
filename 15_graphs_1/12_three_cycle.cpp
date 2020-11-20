/*
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
Input Format :
The first line of input contains two space separated integers, that denotes the value of N and M.
Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v. 
Output Format :
Print the count the number of 3-cycles in the given graph
Constraints :
0 <= N <= 100
0 <= M <= (N*(N-1))/2
0 <= u <= N - 1
0 <= v <= N - 1
Time Limit: 1 sec
Sample Input 1:
3 3
0 1
1 2
2 0
Sample Output 1:
1
*/

#include <iostream>
using namespace std;

int get_count(int **aj,int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // check path between i-j
            if(aj[i][j]==1){
                for(int k=0;k<n;k++){
                    // check path between j-k , k-i
                    if(aj[j][k]==1&&aj[k][i]==1){
                        count++;
                    }
                }
            }
        }
    }
    // as each cycle will be found 6 times in differnet combinations
    // i j k
    // i k j
    // j k i
    // j i k
    // k i j
    // k j i
    return count/6;
}

int main() {
    int n,m;
    cin>>n>>m;
    int **aj=new int*[n];
    for(int i=0;i<n;i++){
        aj[i]=new int[n]{};
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        aj[a][b]=1;
        aj[b][a]=1;
    }
    cout<<get_count(aj,n);
}