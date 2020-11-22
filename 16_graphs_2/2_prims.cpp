/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// here we'll find the vertex which is not visited and which has the min weight
int getminvertex(bool *visited,int *weight,int v){
    int minvertex=-1;
    for(int i=0;i<v;i++){
        // if not visited 
        if(visited[i]==0&&((minvertex==-1)||(weight[minvertex]>weight[i]))){
            minvertex=i;
        }
    }
    return minvertex;
}

int main(){
    int v,e;
    cin>>v>>e;
    int **aj=new int*[v];
    for(int i=0;i<v;i++){
        aj[i]=new int[v]{};
    }
    for(int i=0;i<e;i++){
        int ei,ej,wt;
        cin>>ei>>ej>>wt;
        aj[ei][ej]=wt;
        aj[ej][ei]=wt;
    }

    // make required arrays
    bool *visited=new bool[v]{};
    int *parent=new int[v];
    int *weight=new int[v];
    for(int i=0;i<v;i++){
        weight[i]=INT_MAX;
        parent[i]=-1;
    }

    // select any vertex as starting vertex
    // as we have to include every vertex in the MST, we can choose any one
    parent[0]=-1;
    weight[0]=0;

    for(int i=0;i<v-1;i++){
        // get min vertex - unvisited vertex with minimum weight
        int minvertex=getminvertex(visited,weight,v);
        visited[minvertex]=1;

        // explore all the possible neighbours from this vertex and update parent and new weights of these vertices
        for(int j=0;j<v;j++){
            // checking if there is some vertex connected to min vertex
            // proceed only if its not visited
            if(aj[minvertex][j]!=0&&visited[j]==0){
                // update weight if the new weight is better than previous
                if(weight[j]>aj[minvertex][j]){
                    weight[j]=aj[minvertex][j];
                    parent[j]=minvertex;
                }
            }
        }
    }

    // printing the mst
    for(int i=1;i<v;i++){
        if(parent[i]<i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<"\n";
        }else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<"\n";
        }
    }

    delete parent;
    delete visited;
    delete weight;
    
    return 0;
}