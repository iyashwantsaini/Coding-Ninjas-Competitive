/* 
Find and print connected components in a disconnected graph. Each component in a separate line.
Input: 
8 7
1 2
1 3
3 4
3 6
4 5
4 6
7 8
Output: 
1 2 3 4 5 6 
7 8
*/

#include<bits/stdc++.h>
using namespace std;

void get_set(int v,int **aj,int *visited,int num,set<int> &comp){
    visited[num]=1;
    comp.insert(num);

    for(int i=0;i<=v;i++){
        if(i==num){
            continue;
        }
        if(aj[num][i]==1&&visited[i]==0){
            get_set(v,aj,visited,i,comp);
        }
    }
}

int main(){
    // vertices,edges
    int v,e;
    cin>>v>>e;
    int **aj=new int*[v+1];
    for(int i=0;i<=v;i++){
        aj[i]=new int[v+1]{};
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        aj[a][b]=1;
        aj[b][a]=1;
    }
    int *visited=new int[v+1]{};

    set< set<int> > output;
    for(int i=1;i<=v;i++){
        if(visited[i]==0){
            set<int> comp;
            get_set(v,aj,visited,i,comp);
            output.insert(comp);
        }
    }

    set<set<int>>::iterator outer;
    set<int>::iterator inner;
    for(outer=output.begin();outer!=output.end();outer++){
        for(inner=outer->begin();inner!=outer->end();inner++){
            cout<<*inner<<" ";
        }
        cout<<"\n";
    }

    for(int i=0;i<=v;i++){
        delete aj[i];
    }
    delete aj;
    delete visited;
}