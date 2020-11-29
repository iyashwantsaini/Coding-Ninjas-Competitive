/*
This is the story in Zimbo, the kingdom officially made for monkeys. Our Code Monk visited Zimbo and declared open a challenge in the kingdom, thus spoke to all the monkeys :

You all have to make teams and go on a hunt for Bananas. The team that returns with the highest number of Bananas will be rewarded with as many gold coins as the number of Bananas with them. May the force be with you!
Given there are N monkeys in the kingdom. Each monkey who wants to team up with another monkey has to perform a ritual. Given total M rituals are performed. Each ritual teams up two monkeys. If Monkeys A and B teamed up and Monkeys B and C teamed up, then Monkeys A and C are also in the same team.

You are given an array A where Ai is the number of bananas i'th monkey gathers.

Find out the number of gold coins that our Monk should set aside for the prize.
Input:
First line contains an integer T. T test cases follow. First line of each test case contains two space-separated N and M. M lines follow. Each of the M lines contains two integers Xi and Yi, the indexes of monkeys that perform the i'th ritual. Last line of the testcase contains N space-separated integer constituting the array A.
Output:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
0 ≤ M ≤ 10^5
0 ≤ Ai ≤ 10^12
SAMPLE INPUT
1
4 3
1 2
2 3
3 1
1 2 3 5
SAMPLE OUTPUT
6
Explanation
Monkeys 1,2 ,3 are in the same team. They gather 1+2+3=6 bananas.
Monkey 4 is a team. It gathers 5 bananas.
Therefore, number of gold coins (highest number of bananas by a team) = 6.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dfs(int n,vector<int> *edges,int *visited,ll *a,int curr){
    visited[curr]=1;
    ll ans=a[curr];
    for(auto i=edges[curr].begin();i!=edges[curr].end();i++){
        if(visited[*i]==0){
            ans+=dfs(n,edges,visited,a,*i);
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> *edges=new vector<int>[n+1];
        while(m--){
            int x,y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        ll *a=new ll[n+1]{};
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int *visited=new int[n+1]{};
        ll maxnums=INT_MIN;
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                ll ans=dfs(n,edges,visited,a,i);
                if(ans>maxnums){
                    maxnums=ans;
                }
            }
        }
        cout<<maxnums<<"\n";
    }
}