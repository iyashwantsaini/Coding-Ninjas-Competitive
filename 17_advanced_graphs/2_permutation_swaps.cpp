/*
Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.

Also he believes that there are M good pairs of integers (ai , bi). Kevin can perform following operation with his permutation:

Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.
Input format:
The first line of input will contain an integer T, denoting the number of test cases.

Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi. The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers ai and bi.
Output format:
For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.
Constraints:
1 ≤ T ≤ 10
2 ≤ N ≤ 100000
1 ≤ M ≤ 100000
1 ≤ Pi, Qi ≤ N. Pi and Qi are all distinct.
1 ≤ ai < bi ≤ N
SAMPLE INPUT
2
4 1
1 3 2 4
1 4 2 3
3 4
4 1
1 3 2 4
1 4 2 3
2 4
SAMPLE OUTPUT
NO 
YES

SAMPLE INPUT
1
6 3
1 3 2 4 5 6
1 4 2 3 6 5
2 4
2 5
5 6
SAMPLE OUTPUT
YES
*/

#include<bits/stdc++.h>
using namespace std;

// dfs search and save to set
void dfs_search(int n,vector<int> *aj,int *visited,int num,set<int> &s){
    visited[num]=1;
    s.insert(num);
    vector<int>::iterator it;
    for(it=aj[num].begin();it!=aj[num].end();it++){
        if(*it==num){
            continue;
        }
        if(visited[*it]==0){
            dfs_search(n,aj,visited,*it,s);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int *p=new int[n];
        int *q=new int[n];
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        for(int i=0;i<n;i++){
            cin>>q[i];
        }

        // instead of adjacency matrix we'll use adjacency list
        // int **aj=new int*[n+1];
        // for(int i=1;i<=n;i++){
        //     aj[i]=new int[n+1]{};
        // }

        // each index will have a list of adjacent vertices to that index
        vector<int> *aj=new vector<int>[n+1];

        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            // aj[a][b]=1;
            // aj[b][a]=1;
            aj[a-1].push_back(b-1);
            aj[b-1].push_back(a-1);
        }
        int *visited=new int[n]{};
        int flag=1;

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                set<int> s;
                dfs_search(n,aj,visited,i,s);
                if(s.empty()){
                    continue;
                }

                set<int> pset;
                set<int> qset;                
                set<int>::iterator inner;

                // for(inner=s.begin();inner!=s.end();inner++){
                //     cout<<*inner<<" ";
                // }
                // cout<<"\n";

                for(inner=s.begin();inner!=s.end();inner++){
                    pset.insert(p[*inner]);
                    qset.insert(q[*inner]);
                }
                
                // for(inner=qset.begin();inner!=qset.end();inner++){
                //     auto pos = pset.find(*inner);
                //     if(pos==pset.end()){
                //         flag=0;
                //         break;
                //     } 
                // }

                if(pset!=qset){
                    flag=0;
                    break;
                }
            }
            if(flag==0){
                break;
            }
        }
        if(flag==0){
            cout<<"NO"<<"\n";
        }else{
            cout<<"YES"<<"\n";
        }
    }
    return 0;
}