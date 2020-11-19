/*
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
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

int find_path_bfs(int **aj,int v,int start,int end,map<int,int> &m){
    queue<int> q;
    int visited[v+1]{};
    // stores the child->parent relation for each node
    // map<int,int> m;
    
    q.push(start);
    visited[start]=1;
    m[start]=-1;

    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(int i=0;i<v;i++){
            if(i==current){
                continue;
            }
            if(aj[current][i]==1){
                if(visited[i]==0){
                    q.push(i);
                    visited[i]=1;
                    m[i]=current;
                }
                if(i==end){
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

    while(e--){
        int a,b;
        cin>>a>>b;
        aj[a][b]=1;
        aj[b][a]=1;
    }
    int v1,v2;
    cin>>v1>>v2;


    map<int,int> path;
    int ans=find_path_bfs(aj,v,v1,v2,path);
    if(ans==1){
        // print path
        int current=v2;
        while(current!=-1){
            cout<<current<<" ";
            current=path[current];
        }
    }
    // delete memory
    return 0;
}