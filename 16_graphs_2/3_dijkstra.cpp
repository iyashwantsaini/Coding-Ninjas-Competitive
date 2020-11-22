/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
Note : Order of vertices in output doesn't matter.
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
0 0
1 3
2 4
3 5
*/

#include<bits/stdc++.h>
using namespace std;

int findminvertex(int v,int *visited,int *distances){
    int minv=-1;
    for(int i=0;i<v;i++){
        if(visited[i]==0&&(minv==-1||distances[minv]>distances[i])){
            minv=i;
        }
    }
    return minv;   
}

int main(){
    int v,e;
    cin>>v>>e;
    int **aj=new int*[v];
    for(int i=0;i<v;i++){
        aj[i]=new int[v]{};
    }

    for(int i=0;i<e;i++){
        int ei,ej,wi;
        cin>>ei>>ej>>wi;
        aj[ei][ej]=wi;
        aj[ej][ei]=wi;
    }

    // create arrays
    int *visited=new int[v]{};
    int *distances=new int[v];
    distances[0]=0;
    for(int i=1;i<v;i++){
        distances[i]=INT_MAX;
    }
    
    for(int i=0;i<v-1;i++){
        // get minedge 
        int minvertex=findminvertex(v,visited,distances);
        // set visited
        visited[minvertex]=1;
        // update unvisited neighbours which can be reached with better cost
        for(int j=0;j<v;j++){
            if(visited[j]==0&&aj[minvertex][j]!=0){
                if(distances[j]>distances[minvertex]+aj[minvertex][j]){
                    distances[j]=distances[minvertex]+aj[minvertex][j];
                }
            }
        }
    }

    // print result
    for(int i=0;i<v;i++){
        cout<<i<<" "<<distances[i]<<"\n";
    }

    delete visited;
    delete distances;
    for(int i=0;i<v;i++){
        delete aj[i];
    }
    delete aj;
    return 0;
}