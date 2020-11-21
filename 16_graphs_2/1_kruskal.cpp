/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
1 2 1
0 1 3
0 3 5
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class edge{
    public:
        int ei;
        int ej;
        int wt;
};

bool compare(edge e1,edge e2){
    return e1.wt<e2.wt;
}

int get_parent(int current_vertex, int *parents){
	if (current_vertex == parents[current_vertex]){
		return current_vertex;
	}
	return get_parent(parents[current_vertex], parents);
}

int main() {
    int v,e;
    cin>>v>>e;
    edge *edges=new edge[e];
    for(int i=0;i<e;i++){
        cin>>edges[i].ei;
        cin>>edges[i].ej;
        cin>>edges[i].wt;
    }
    sort(edges,edges+e,compare);

    // cout<<"\n\n";
    // for(int i=0;i<v;i++){
    //     cout<<edges[i].ei<<" "<<edges[i].ej<<" "<<edges[i].wt<<endl;
    // }
    // cout<<"\n\n";
    
    int *parents=new int[v];
    for(int i=0;i<v;i++){
        parents[i]=i;
    }

    edge *mst=new edge[v-1];
    int count=0;

    for(int i=0;i<e;i++){
        if(count>=v-1){
            break;
        }

        edge current=edges[i];
        int p1 = get_parent(current.ei, parents);
		int p2 = get_parent(current.ej, parents);

        // int p1=parents[v1];
        // int p2=parents[v2];

        if(p1!=p2){
            mst[count]=current;
            parents[p1]=p2;
            count++;
        }
    }
    for(int i=0;i<v-1;i++){
        if(mst[i].ei<mst[i].ej){
            cout<<mst[i].ei<<" "<<mst[i].ej<<" "<<mst[i].wt<<"\n";
        }else{
            cout<<mst[i].ej<<" "<<mst[i].ei<<" "<<mst[i].wt<<"\n";
        }
    }
}