/*
Domino
Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
Input
The first line of input contains one integer specifying the number of test cases to follow.Each test case begins with a line containing two integers,each no larger than 100 000. The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
Output
For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input
1
3 2
1 2
2 3
Sample Output
1
*/

// we need to find the total number of connected components
// We'll use kosaraju's algorithm to find the answer
// but we'll run dfs on the given edges only not the transposed as we just need the total number of connected components

#include<bits/stdc++.h>
using namespace std;

void dfs_stack(int n,vector<int> *edges,int *visited,int i,stack<int> &s){  
    visited[i]=1;
    vector<int>::iterator it;
    for(it=edges[i].begin();it!=edges[i].end();it++){
        if(visited[*it]==0){
            dfs_stack(n,edges,visited,*it,s);
        }
    }
    s.push(i);
}

void dfs_(int n,vector<int> *edges,int *visited,int i){
    visited[i]=1;
    vector<int>::iterator it;
    for(it=edges[i].begin();it!=edges[i].end();it++){
        if(visited[*it]==0){
            dfs_(n,edges,visited,*it);
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        // n=number of dominos
        // m=no of pairs
        int n,m;
        cin>>n>>m;
        vector<int> *edges=new vector<int>[n];
        while(m--){
            int x,y;
            cin>>x>>y;
            edges[x-1].push_back(y-1);
        }
        // create a stack which will have all vertices according to finishing time
        stack<int> s;
        int *visited=new int[n+1]{};
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs_stack(n,edges,visited,i,s);
            }
        }
        
        for(int i=0;i<=n;i++){
            visited[i]=0;
        }
        
        int count=0;
        // pop from stack 1 by 1 and run dfs on transposed graph
        while(!s.empty()){
            int i=s.top();
            s.pop();
            if(visited[i]==0){
                count++;
                dfs_(n,edges,visited,i);
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}