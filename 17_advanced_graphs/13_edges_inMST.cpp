/*
Edges in MST
You are given a connected weighted undirected graph without any loops and multiple edges.

Let us remind you that a graph's spanning tree is defined as an acyclic connected subgraph of the given graph that includes all of the graph's vertexes. The weight of a tree is defined as the sum of weights of the edges that the given tree contains. The minimum spanning tree (MST) of a graph is defined as the graph's spanning tree having the minimum possible weight. For any connected graph obviously exists the minimum spanning tree, but in the general case, a graph's minimum spanning tree is not unique.

Your task is to determine the following for each edge of the given graph: whether it is either included in any MST, or included at least in one MST, or not included in any MST.
Input
The first line contains two integers n and m (2 ≤ n ≤ 10^5, ) — the number of the graph's vertexes and edges, correspondingly. Then follow m lines, each of them contains three integers — the description of the graph's edges as "ai bi wi" (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 10^6, ai ≠ bi), where ai and bi are the numbers of vertexes connected by the i-th edge, wi is the edge's weight. It is guaranteed that the graph is connected and doesn't contain loops or multiple edges.
Output
Print m lines — the answers for all edges. If the i-th edge is included in any MST, print "any"; if the i-th edge is included at least in one MST, print "at least one"; if the i-th edge isn't included in any MST, print "none". Print the answers for the edges in the order in which the edges are specified in the input.
Sample input 1
4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
sample output 1
none
any
at least one
at least one
any
Sample input 2
3 3
1 2 1
2 3 1
1 3 2
sample output 2
any
any
none
sample input 3
3 3
1 2 1
2 3 1
1 3 1
sample output 3
at least one
at least one
at least one
Note
In the second sample the MST is unique for the given graph: it contains two first edges.

In the third sample any two edges form the MST for the given graph. That means that each edge is included at least in one MST.
*/

#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
        int ei,ej,wt,index;
        string arg="at least one";
};

bool sortcost(edge e1,edge e2){
    e1.wt<e2.wt;
}

bool sortindex(edge e1,edge e2){
    e1.wt<e2.wt;
}

int find_parent(int num,int *parents){
    if(num==parents[num]){
        return num;
    }
    return find_parent(parents[num],parents);
}

void do_dfs(int n,int *parents,int *visited){
    visited[n]=1;
    if(n==parents[n]){
        return;
    }
    do_dfs(parents[n],parents,visited);
}

int dfs(int n,int*parents,int *visited){
    int count=0;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            count++;
            do_dfs(i,parents,visited);
        }
    }
    return count;
}

int main(){
    int n,m;
    cin>>n>>m;
    edge *edges=new edge[m];
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        edges[i].ei=x;
        edges[i].ej=y;
        edges[i].wt=wt;
        edges[i].index=i;
    }
    sort(edges,edges+m,sortcost);
    
    int *parents=new int[n+1];
    for(int i=0;i<=n;i++){
        parents[i]=i;
    }
    int count=0;
    int *rank=new int[n+1]{};
    int *visited=new int[n+1]{};

    for(int i=0;i<m-1;i++){

        // count the number of edges of this similar weight
        int j; 
        for(j=i+1;j<m-1;j++){
            if(edges[i].wt==edges[j].wt){
                j++;
            }else{
                break;
            }
        }


        // if single element take single decision
        if((j-i)==1){
            edge e=edges[i];
            int p1=find_parent(e.ei,parents);
            int p2=find_parent(e.ej,parents);
            // find if cycle is being formed
            if(p1==p2){
                edges[i].arg="none";
            }else{
                int before=dfs(n,parents,visited);
                if(rank[p1]<=rank[p2]){
                    parents[p1]=p2;
                    rank[p2]++;
                }else{
                    parents[p2]=p1;
                    rank[p1]++;
                }
                int after=dfs(n,parents,visited);
                if(before!=after){
                    edges[i].arg="any";
                }
            }
            i=j;
            continue;
        }

        // find parents of all the similar weight elements 
        vector<pair<int,pair<int,int>>> par;
        for(int x=i;x<j;x++){
            edge e=edges[x];
            int p1=find_parent(e.ei,parents);
            int p2=find_parent(e.ej,parents);
            // find if cycle is being formed
            if(p1==p2){
                edges[i].arg="none";
            }else{
                par.push_back(make_pair(x,make_pair(max(p1,p2),min(p1,p2))));
            }
        }

        // find the args
        // ma to store occurances of same parents
        map<int,int> p;
        for(auto x=par.begin();x!=par.end();x++){
			p[x->second.first]++;
            p[x->second.second]++;
        }

        int flag=0;
        for(auto x=p.begin();x!=p.end();x++){
            if(x->second>1){
                flag=1;
            }
        }

        if(flag==0){
            int done=0;
            for(auto x=par.begin();x!=par.end();x++){
                if(done==0){
                    
                }
            }
        }else{
            for(auto x=par.begin();x!=par.end();x++){
                
            }
        }

        // move to next non equal cost
        i=j;
    }

    sort(edges,edges+m,sortindex);
    for(int i=0;i<m;i++){
        cout<<edges[i].arg<<"\n";
    }

    return 0;
}