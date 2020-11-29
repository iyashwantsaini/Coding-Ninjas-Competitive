/*
MONK AND THE ISLAND
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
Input:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
Output:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N
SAMPLE INPUT
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
SAMPLE OUTPUT
2
2
*/

#include<bits/stdc++.h>
using namespace std;

int bfs(int n,vector<int> *edges,queue<pair<int,int>> *pending){
    int level=0;
    pending->push(make_pair(1,0));
    int *visited=new int[n+1]{};
    visited[1]=1;

    while(!pending->empty()){
        pair<int,int> el=pending->front();
        pending->pop();
        if(el.first==n){
            return el.second;
        }
        for(auto i=edges[el.first].begin();i<edges[el.first].end();i++){   
            if(visited[*i]==0){
                pending->push(make_pair(*i,el.second+1));
                visited[*i]=1;
            }
        }
    }

    return level;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> *edges=new vector<int>[n+1];
        while(m--){
            int x,y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        queue<pair<int,int>> *pending=new queue<pair<int,int>>;
        int numbridges=bfs(n,edges,pending);
        cout<<numbridges<<"\n";
    }
    return 0;
}