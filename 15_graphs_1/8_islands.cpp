/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 
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
        aj[i]=new int[v];
    }
    while(e--){
        int a,b;
        cin>>a>>b;
        aj[a][b]=1;
        aj[b][a]=1;
    }
    int *visited=new int[v]{};
    int count=0;
    // counting number of groups
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            dfs_traversal(aj,v,visited,i);
            count++;
        }
    }
    cout<<count<<"\n";
    return 0;
}