// https://www.codechef.com/problems/CHEFRES

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        // pairs for intervals
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int start,end;
            cin>>start>>end;
            v.push_back(make_pair(start,end));
        }
        // sort the intervals according to first value
        sort(v.begin(),v.end());
        while(m--){
            int time;
            cin>>time;
            // find the position for this time in intervals using lower_bound (gives a pointer in return)
            // lower_bound gives the position if found, if not found it gives next element pointer 
            // lower_bound(startpointer,endpointer,element_tobefound);
            // as we are searching in pairs we need to pair a pair for target element say - (el,0)
            int position=lower_bound(v.begin(),v.end(),make_pair(time,0))-v.begin();

            // check conditions
            // if 0 posn 
            if(position==0){
                // means we came before the firts interval itself
                // we'll have to wait until shop opens
                int ans=v[0].first-time;
                cout<<ans<<endl;

                // check if the time is within any interval - wait =0
            }else if(v[position-1].second>time){
                cout<<0<<endl;
            }

            // its somewhere in between the timgaps between intervals
            // wait time= current posn -> first - time
            else if(position<v.size()){
                int ans=v[position].first-time;
                cout<<ans<<endl;
            }else{
                // posn==v.size() means we'll have to wait infinitely
                cout<<-1<<endl;
            }
        }
    }
}
