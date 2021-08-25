#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// https://leetcode.com/discuss/interview-question/1396122/Flipkart-oror-OnCampus-oror-OA-Questions-oror-10-Aug-2021
// in
/*
4 2
5 4
6 7
2 3
6 5
*/

int main(){
    int n,c;
    cin>>n>>c;
    vector<pair<int,int>> data;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        data.push_back({x,y});
    }
    
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<data[i].first<<" "<<data[i].second<<"\n";
    }
    cout<<"\n";
    // sort(data.begin(),data.end(),greater<pair<int,int>>());

    sort(data.begin(),data.end());
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<data[i].first<<" "<<data[i].second<<"\n";
    }
    cout<<"\n";

    // longest increasing subseq
    int *dp=new int[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=1;
    }

    int ans=1;
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(data[j].first<data[i].first&&data[j].second<data[i].second){
                dp[i]=max(dp[i],dp[j]+1);
                ans=max(ans,dp[i]);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }

    cout<<"\n"<<ans<<"||";

    return 0;
}