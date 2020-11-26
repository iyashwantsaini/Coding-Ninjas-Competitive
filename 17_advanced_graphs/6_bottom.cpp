/*
We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
Input Specification
The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E) where the vertices will be identified by the integer numbers in the set V={1,…,v}. You may assume that 1≤v≤5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.
Output Specification
For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.
Sample Input
3 3
1 3 
2 3 
3 1
2 1
1 2
0
Sample Output
1 3
2
Sample Input
6 7
1 2
2 3
3 1
2 4
4 5
5 6
6 4
0
Sample Output
4 5 6
*/

// find all strongly connected components
// for each of vertex in each components
// - if any edge is going out to any other component , skip this component
// - else print the component

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs_stack(int v,vector<int> *edges,int *visited,int num,stack<int> &s){
    visited[num]=1;
    vector<int>::iterator it;
    for(it=edges[num].begin();it!=edges[num].end();it++){
        if(visited[*it]==0){
            dfs_stack(v,edges,visited,*it,s);
        }
    }
    s.push(num);
}

void dfs_search(int v,vector<int> *edgesT,int *visited,int num,set<int> &sget){
    visited[num]=1;
    sget.insert(num);
    vector<int>::iterator it;
    for(it=edgesT[num].begin();it!=edgesT[num].end();it++){
        if(visited[*it]==0){
            dfs_search(v,edgesT,visited,*it,sget);
        }
    }
}

int main(){
    while(1){
        int v,e;
        cin>>v;
        if(v==0){
            break;
        }
        cin>>e;
        vector<int> *edges=new vector<int>[v];
        vector<int> *edgesT=new vector<int>[v];
        while(e--){
            int x,y;
            cin>>x>>y;
            edges[x-1].push_back(y-1);
            edgesT[y-1].push_back(x-1);
        }
        int *visited=new int[v+1]{};
        stack<int> s;
        for(int i=0;i<v;i++){
            if(visited[i]==0){
                dfs_stack(v,edges,visited,i,s);
            }
        }
        // cout<<s.size();

        set<set<int>> out;
        for(int i=0;i<v;i++){
            visited[i]=0;
        }
        while(!s.empty()){
            int i=s.top();
            s.pop();
            if(visited[i]==0){
                set<int> sget;
                dfs_search(v,edgesT,visited,i,sget);
                out.insert(sget);
            }
        }
        
        // cout<<"............\n";
        // set<set<int>>::iterator outer;
        // set<int>::iterator inner;
        // for(outer=out.begin();outer!=out.end();outer++){
        //     for(inner=outer->begin();inner!=outer->end();inner++){
        //         cout<<*inner+1<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"............\n";

        set<set<int>>::iterator outer;
        set<int>::iterator inner;
		
        set<int> final;
        for(outer=out.begin();outer!=out.end();outer++){
            int flag=1;
            for(inner=outer->begin();inner!=outer->end();inner++){
                // if not connected to anyone
                if(edges[*inner].empty()){
                    final.insert(*inner+1);
                    continue;
                }
                for(auto i=edges[*inner].begin();i<edges[*inner].end();i++){
                    if(outer->find(*i)==outer->end()){
                        flag=0;
                        break;
                    }
                }
                if(flag==0){
                    break;
                }
            }
            if(flag==1){
                for(inner=outer->begin();inner!=outer->end();inner++){
                    final.insert(*inner+1);
                }
            }
        }
        for(inner=final.begin();inner!=final.end();inner++){
            cout<<*inner<<" ";
        }
		cout<<"\n";

    }
    return 0;
}