/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int find_path_dfs(int **aj,int v,int *visited,int start,int end,queue<int> *path){
    visited[start]=1;

    // if end reached
    if(start==end){
        path->push(end);
        return 1;
    }
    // check all nodes connected to current node
    for(int i=0;i<v;i++){
        if(i==start){
            continue;
        }
        if(aj[start][i]==1){
            if(visited[i]==0){
                int ans=find_path_dfs(aj,v,visited,i,end,path);
                // if my child has found a possible path
                // add current to path and notify my parent
                if(ans==1){
                    path->push(start);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    int v,e;
    cin>>v>>e;
    int **aj=new int*[v];
    for(int i=0;i<v;i++){
        aj[i]=new int[v]{};
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        aj[a][b]=1;
        aj[b][a]=1;
    }
    int v1,v2;
    cin>>v1>>v2;

    // in this queue the first possible path will be stored
    queue<int> *path=new queue<int>;

    int *visited=new int[v+1]{};
    int ans=find_path_dfs(aj,v,visited,v1,v2,path);
    // if path found, print
    if(ans==1){
        // print solution
        while(!path->empty()){
            int current=path->front();
            cout<<current<<" ";
            path->pop();
        }
    }
    return 0;
}