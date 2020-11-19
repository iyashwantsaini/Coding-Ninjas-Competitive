/*
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
    dfs_print(aj,n,0,visited);
    
    
    // delete all memory
    return 0;
}