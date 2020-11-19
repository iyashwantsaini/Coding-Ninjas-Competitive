/*
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= 1000
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
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string search_dfs(int **aj,int v,int *visited,int start,int val){
    visited[start]=1;
    // check if value found
    if(start==val){
        return "true";
    }
    // iterate to all the connected vertices of the current vertice
    for(int i=0;i<v;i++){
        if(i==start){
            continue;
        }
        if(aj[start][i]==1){
            if(visited[i]==1){
                continue;
            }
            string ans=search_dfs(aj,v,visited,i,val);
            if(ans=="true"){
                return ans;
            }
        }
    }
    return "false";
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
    int *visited=new int[v+1]{};
    string ans=search_dfs(aj,v,visited,v1,v2);
    cout<<ans<<endl;
    return 0;
}