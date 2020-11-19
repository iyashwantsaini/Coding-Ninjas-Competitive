/*
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
Output Format :
The first and only line of output contains "true" if the given graph is connected or "false", otherwise.
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
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs_traversal(int **aj,int v,int *visited,int start){
    visited[start]=1;
    for(int i=0;i<v;i++){
        if(aj[start][i]==1){
            if(visited[i]==0){
                dfs_traversal(aj,v,visited,i);
            }
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    int **aj=new int*[v];
    for(int i=0;i<v;i++){
        aj[i]=new int[v]{};
    }
    while(e--){
        int a,b;
        cin>>a>>b;
        aj[a][b]=1;
        aj[b][a]=1;
    }
    int *visited=new int[v]{};
    dfs_traversal(aj,v,visited,0);
    // so after complete dfs traversal, if any node is left to visit
    // it means that our graph is not connected 
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            cout<<"false";
            return 0;
        }
    }
    cout<<"true";
    return 0;
}