/*

** KOSARAJU'S algorithm **

find and print all strongly connected components in a graph.

input
10
12
1 2
2 3
3 9
9 1
3 4
4 5
5 6
6 4
7 6
7 8
8 7
8 10

output
0 1 2 8
3 4 5
6 7
9

*/

#include<bits/stdc++.h>
using namespace std;

void dfs_(int n,vector<int> *edges,int *visited,int num,stack<int> &s){
    if(visited[num]==1){
        return;
    }
    visited[num]=1;
    vector<int>::iterator it;
    for(it=edges[num].begin();it!=edges[num].end();it++){
        if(visited[*it]==0){
            dfs_(n,edges,visited,*it,s);
        }
    }
    s.push(num);
}

void dfs_get(int n,vector<int> *edgesT,int *visited,int num,set<int> &s){
    if(visited[num]==1){
        return;
    }
    visited[num]=1;
    s.insert(num);
    vector<int>::iterator it;
    for(it=edgesT[num].begin();it!=edgesT[num].end();it++){
        if(visited[*it]==0){
            dfs_get(n,edgesT,visited,*it,s);
        }
    }
}

int main(){
    // num of vertices
    int n;
    cin>>n;
    // number of edges
    int m;
    cin>>m;
    // adjacency list for edges
    vector<int> *edges=new vector<int>[n];
    // adjacency list for transposed edges
    vector<int> *edgesT=new vector<int>[n];

    while(m--){
        int x,y;
        cin>>x>>y;
        edges[x-1].push_back(y-1);
        edgesT[y-1].push_back(x-1);
    }

    int *visited=new int[n+1]{};
    // stack to hold all the completed components
    stack<int> s;
    
    for(int i=0;i<n;i++){
        if(visited[i]==1){
            continue;
        }
        vector<int>::iterator it;
        for(it=edges[i].begin();it!=edges[i].end();it++){
            if(visited[*it]==0){
                dfs_(n,edges,visited,*it,s);
            }
        }
    }

    set<set<int>> output;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    // get components as sets
    while(!s.empty()){
        auto i=s.top();
        s.pop();
        if(visited[i]==1){
            continue;
        }
        vector<int>::iterator it;

        // if the current is not connected by anyone
        // means its a single vertex component

        set<int> sget;
        dfs_get(n,edgesT,visited,i,sget);
        output.insert(sget);

    }

    // for(int i=0;i<n;i++){
    //     cout<<visited[i]<<" ";
    // }
    // cout<<"\n";

    // printing result
    set<set<int>>::iterator outer;
    set<int>::iterator inner;
    for(outer=output.begin();outer!=output.end();outer++){
        for(inner=outer->begin();inner!=outer->end();inner++){
            cout<<*inner+1<<" ";
        }
        cout<<"\n";
    }

    // for(int i=0;i<n;i++){
    //     if(visited[i]==0){
    //         cout<<i+1<<endl;
    //     }
    // }

}



// ninjas's code
/*
#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <unordered_set>
using namespace std;
void dfs(vector<int> *edges, unordered_set<int> &visited, stack<int> &finished_vertices, int start)
{
    visited.insert(start);
    for (int i = 0; i < edges[start].size(); i++)
    {
        int adjacent_element = edges[start][i];
        if (visited.count(adjacent_element) == 0)
        {
            dfs(edges, visited, finished_vertices, adjacent_element);
        }
    }
    finished_vertices.push(start);
}
void dfs2(vector<int> *edgesT, int start, unordered_set<int> &visited, unordered_set<int> *component)
{
    visited.insert(start);
    component->insert(start);
    for (int i = 0; i < edgesT[start].size(); i++)
    {
        int adjacent = edgesT[start][i];
        if (visited.count(adjacent) == 0)
        {
            dfs2(edgesT, adjacent, visited, component);
        }
    }
}
unordered_set<unordered_set<int> *> *getSCC(vector<int> *edges, vector<int> *edgesT, int n)
{
    unordered_set<int> visited;
    stack<int> finished_vertices;
    for (int i = 0; i < n; i++)
    {
        if (visited.count(i) == 0)
        {
            dfs(edges, visited, finished_vertices, i);
        }
    }
    unordered_set<unordered_set<int> *> *output = new unordered_set<unordered_set<int> *>();
    visited.clear();
    while (!finished_vertices.empty())
    {
        int element = finished_vertices.top();
        finished_vertices.pop();
        if (visited.count(element) != 0)
        {
            continue;
        }
        unordered_set<int> *component = new unordered_set<int>();
        dfs2(edgesT, element, visited, component);
        output->insert(component);
    }
    return output;
}
int main()
{
    int n; //number of vertices
    cin >> n;
    vector<int> *edges = new vector<int>[n];
    vector<int> *edgesT = new vector<int>[n];
    int m; //number of eges
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int j, k;
        cin >> j >> k;
        edges[j - 1].push_back(k - 1);
        edgesT[k - 1].push_back(j - 1);
    }
    unordered_set<unordered_set<int> *> *components = getSCC(edges, edgesT, n);

    unordered_set<unordered_set<int> *>::iterator it1 = components->begin();
    while (it1 != components->end())
    {
        unordered_set<int> *component = *it1;
        unordered_set<int>::iterator it2 = component->begin();
        while (it2 != component->end())
        {
            cout << *it2 + 1 << " ";
            it2++;
        }
        cout << endl;
        delete component;
        it1++;
    }

    delete components;
    delete[] edges;
    delete[] edgesT;
}
*/
