// https://www.codechef.com/problems/COOK82C

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// as we cannot change the array 
// as we cannot apply sorting after every query due to complexity issue
// so, we will maintain a queue to solve this prob

int main(){
    int n,m;
    cin>>n>>m;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    queue<ll> q;
    int count_m=0;
    int end_p=n-1;
    int count=0;
    while(m--){
        int curr_m;
        cin>>curr_m;
        int ans;
        for(;count<curr_m;count++){
            if(end_p>=0&&(q.empty()||a[end_p]>=q.front())){
                ans=a[end_p];
                end_p--;
            }else{
                ans=q.front();
                q.pop();
            }
            q.push(ans/2);
        }
        cout<<ans<<endl;
    }
    return 0;
}