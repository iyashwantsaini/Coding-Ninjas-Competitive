// https://codeforces.com/blog/entry/70589

#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n,m,k;
	cin>>n>>m>>k;
//cout<<1;
	vector<vector<pair<int, int>>> adj(n + 1);
 
	for(int i=0;i<m;i++){
		int u, v, w;
		cin>>u>>v>>w;
		adj[u-1].push_back({v-1, w});
		adj[v-1].push_back({u-1, w});
	}
 
	vector<vector<int>> dp(n + 1, vector<int>(k + 2, INT_MAX));
	for(int i = 0;i <=k;i++){
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, 0});
		dp[0][i] = 0;
		while(!pq.empty()){
			auto tp = pq.top();
			pq.pop();
			int u = tp.second;
			for(auto it : adj[u]){
				int v = it.first;
				int w = it.second;
				if(i > 0){
					if(dp[v][i] > min(dp[u][i-1] , dp[u][i] + w)){
						dp[v][i] = min(dp[u][i-1] , dp[u][i] + w);
						pq.push({dp[v][i], v});
					}
				}
				else{
					if(dp[v][i] > dp[u][i] + w){
						dp[v][i] = dp[u][i] + w;
						pq.push({dp[v][i], v});
					}
				}
			}
 
		}
 
 
	}
	for(int i = 0;i < n;i++){
		cout<<dp[i][k]<<" ";
	}
	cout<<endl;
 
}