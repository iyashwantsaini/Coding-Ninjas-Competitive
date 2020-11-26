/*
Find if a graph is bicolorable or not (assuming graph is connected)

graph is a non-directed graph
vertices are number from 0 to v-1

given multiple test cases
each test case has a graph, tell whether it's a bicolorable graph or not
take input of test cases till no of vertices in a test case is 0

input
5 5
0 1
1 2
2 3
3 4
4 0
output
NOT-BICOLORABLE

input
4 4
0 1
1 3
3 2
2 0
output
NOT-BICOLORABLE

*/

#include<bits/stdc++.h>
using namespace std;

int bicolorable(vector<int> *edges,int v){
    // take 2 sets using which we'll try to make the graph bipartite
    set<int> s[2];
    // take a qeueu for pending vertices
    // pending contains the vertices which i have added to set but its neighbours are not explored yet
    // order doesn't matter here
    queue<int> pending;

    s[0].insert(0);
    pending.push(0);

    while(!pending.empty()){
        int el=pending.front();
        pending.pop();

        // find the set of current vertex
        int current_set;
        if(s[0].find(el)!=s[0].end()){
            current_set=0;
        }else{
            current_set=1;
        }
        // check the popped element's neighbours
        for(auto i=edges[el].begin();i!=edges[el].end();i++){
            int current=*i;
            // case 1 - current is in none of the sets
            if(s[0].find(current)==s[0].end()&&s[1].find(current)==s[1].end()){
                // insert the current in other set which does not have el
                s[1-current_set].insert(current);
                pending.push(current);
            }
            // case 2 - current is not in same set as el
            else if(s[current_set].find(current)==s[current_set].end()){
                s[!current_set].insert(current);
            }
            // case 3 - current is the same set as el
            else{
                return false;
            }    
        }
    }
    return true;
}

int main(){
    while(1){
        int v;
        cin>>v;
        if(v==0){
            break;
        }
        int e;
        cin>>e;
        vector<int> *edges=new vector<int>[v];
        while(e--){
            int a,b;
            cin>>a>>b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        int ans=bicolorable(edges,v);
        if(ans==1){
            cout<<"BICOLORABLE\n";
        }else{
            cout<<"NOT-BICOLORABLE\n";
        }
    }
    return 0;
}

