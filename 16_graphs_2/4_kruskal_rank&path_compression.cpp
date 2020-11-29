// This is the implementation of Kruskal's Algo using Rank and Path Compression Algorithm

#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
        int ei;
        int ej;
        int cost;
};

// sorting on basis of cost
bool compare(edge e1,edge e2){
    return e1.cost<e2.cost;
}

// dfs to get parent of current node
// but while backtracjing we set the parent of each element in the chain to the topmost parent
// the element with the most number of children will have higher rank
int get_parent(int num,int *par,int *rank){
    if(num==par[num]){
        return num;
    }
    int p=get_parent(par[num],par,rank);
    
    // parent will always be the one with higher children (higher rank)
    if(rank[num]<=rank[p]){
    	par[num]=p;
        rank[p]++;
    }else{
        par[p]=num;
        rank[num]++;
    }
    
    return p;
}

int main(){
    int n,m;
    cin>>n>>m;
    edge *edges=new edge[m];
    for(int i=0;i<m;i++){
        cin>>edges[i].ei>>edges[i].ej>>edges[i].cost;
    }
    // sorting according to cost
    sort(edges,edges+m,compare);
    // parents array
    int *parents=new int[n];
    for(int i=0;i<n;i++){
        parents[i]=i;
    }
    // storing the answer
    // mst's always have n-1 edges
    edge *mst=new edge[n-1];

    // saving rank in an array
    int *rank=new int[n]{};

    int count=0;
    for(int i=0;i<m;i++){
        // if required vertices obtained already break
        if(count>=n-1){
            break;
        }

        edge curr=edges[i];
        // get parents of both vertices    
        int p1=get_parent(curr.ei,parents,rank);
        int p2=get_parent(curr.ej,parents,rank);

        if(p1!=p2){
            mst[count]=curr;

            // parent will always be the one with higher children (higher rank)
            if(rank[p1]<=rank[p2]){
                parents[p1]=p2;
                rank[p2]++;
            }else{
                parents[p2]=p1;
                rank[p1]++;
            }
            
            count++;
        }
    }
    
    // for(int i=0;i<n;i++){
    //     cout<<parents[i]<<" ";
    // }cout<<"\n";

    // printing in required format
    for(int i=0;i<n-1;i++){
        if(mst[i].ei<mst[i].ej){
            cout<<mst[i].ei<<" "<<mst[i].ej<<" "<<mst[i].cost<<"\n";
        }else{
            cout<<mst[i].ej<<" "<<mst[i].ei<<" "<<mst[i].cost<<"\n";
        }
    }

}