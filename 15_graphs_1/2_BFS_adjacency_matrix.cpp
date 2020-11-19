/*
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Note:
1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains space separated two integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print the BFS Traversal, as described in the task.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second

Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2

input 2
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
output 2
0 1 2 3 4 6 5

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// call children to print itself
void bfs_print(int **aj,int n,int start_vertex,int *visited){
    vector<int> q;
    q.push_back(start_vertex);
    visited[start_vertex]=1;

    while(!q.empty()){
        int current=q[0];
        cout<<current<<" ";

        for(int i=0;i<n;i++){
            if(i==current){
                continue;
            }
            if(aj[current][i]==1&&visited[i]==0){
                q.push_back(i);
                visited[i]=1;
            }
        }

        q.erase(q.begin());
    
    }
}

int main(){
    // n=no of vertices
    // e=no of edges
    int n,e;
    cin>>n>>e;
    // if(e==0&&n==0){
    //     return 0;
    // }
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
    // if(e==0&&n!=0){
    //     for(int i=0;i<n;i++){
    //         cout<<i<<" ";
    //     }
    //     return 0;
    // }

    // BFS PRINT
    // to avoid going back to same vertex and stuck in an infinite loop
    int *visited=new int[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    // as we can have disconnected graphs as well
    // so we'll need to run a loop to tak ein consideration all the components
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            bfs_print(aj, n, i, visited);
        }
    }

    // bfs_print(aj,n,0,visited);
    
    // delete all memory
    return 0;
}