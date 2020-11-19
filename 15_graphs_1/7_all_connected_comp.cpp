/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs_traversal(int **aj,int v,int *visited,int start,vector<int> &path){
    path.push_back(start);
    visited[start]=1;

    for(int i=0;i<v;i++){
        if(aj[start][i]==1){
            if(visited[i]==0){
                dfs_traversal(aj,v,visited,i,path);
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

    // for loop helps in printing all disconnected components as well
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            // vector for storing path of current component
            vector<int> path;
            dfs_traversal(aj,v,visited,i,path);
            // as we have to print every component in ascending order
            sort(path.begin(),path.end());
            for(int x=0;x<path.size();x++){
                cout<<path.at(x)<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}