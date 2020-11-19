/*

Given an undirected and disconnected graph G(V, E), print its DFS traversal.
Note:
1. Here you need to consider that you need to print DFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains space separated two integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print the DFS Traversal, as described in the task.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second

input
7
8
0 1
0 2
1 3
1 4
2 6
3 5
4 5
5 6
output
0
1
3
5
4
6
2
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// call children to print itself
void dfs_print(int **aj,int n,int start_vertex,int *visited){
    cout<<start_vertex<<endl;
    visited[start_vertex]=1;

    for(int i=0;i<n;i++){
        // each vertex is not connected to itself by any edge
        if(i==start_vertex){
            continue;
        }
        if(aj[start_vertex][i]==1){ 
            // check if this edge already visited
            if(visited[i]==1){
                continue;
            }
            dfs_print(aj,n,i,visited);
        }
    }
}

int main(){
    // n=no of vertices
    // e=no of edges
    int n,e;
    cin>>n>>e;
    // adjacency matrix
    int **aj=new int*[n];
    for(int i=0;i<n;i++){
        aj[i]=new int[n]{};
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        aj[a][b]=1;
        aj[b][a]=1;
    }
    

    // DFS PRINT
    // to avoid going back to same vertex and stuck in an infinite loop
    int *visited=new int[n+1];
    for(int i=0;i<=n;i++){
        visited[i]=0;
    }

    // as we can have disconnected graphs as well
    // so we'll need to run a loop to tak ein consideration all the components
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            dfs_print(aj,n,i,visited);
        }
    }
    
    
    // delete all memory
    return 0;
}