/*
Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence ai, ai+1, ..., aj.
Input Format
Line 1: n (1 ≤ n ≤ 30000).
Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^9).
Line 3: q (1 ≤ q ≤ 200000), the number of k- queries.
In the next q lines, each line contains 3 numbers i, j, k representing a k-query (1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 10^9).
Output Format
For each k-query (i, j, k), print the number of elements greater than k in the subsequence ai, ai+1, ..., aj in a single line.
Sample Input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 
Sample Output
2
0
3 
*/

#include<bits/stdc++.h>
using namespace std;

class event{
    public:
        int l,r,k,index;
        event(){
            l=0,r=0,k=0,index=0;
        }
};

int query(int index,int *BIT,int n){
    int count=0;
    for(;index>0;index-=index&(-index)){
        count+=BIT[index];
    }
    return count;
}

void update(int index,int *BIT,int n){
    for(;index<=n;index+=index&(-index)){
        BIT[index]++;
    }
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> a;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push_back({x,i});
    }
    // sort input in increasing order
    sort(a.begin(),a.end());
    // for(int i=0;i<n;i++){
    //     cout<<a[i].first<<" ";
    // }cout<<"\n";

    int q;
    cin>>q;

    vector<pair<pair<int,int>,pair<int,int>>> events;
    for(int i=1;i<=q;i++){
        int l,r,k;
        cin>>l>>r>>k;
        events.push_back({{k,i},{l,r}});
    }
    // sort in decreasing order on basis of k value
    // if k same then use larger l value
    sort(events.begin(),events.end(),greater<pair<pair<int,int>,pair <int,int>>>());

    int *BIT=new int[30002]{};
    int *ans=new int[200002]{};
    // find for larger k values first then go to smaller k values
    // this is beacause smaller will use larger to get ans from BIT
    for(int i=0;i<q;i++){
        int l,r,index,k;
        l=events[i].second.first;
        r=events[i].second.second;
        k=events[i].first.first;
        index=events[i].first.second;

        // go to each a value from greater to smaller and check if its greater than k
        for(int j=a.size()-1;j>=0;j--){
            // check if greater than k
            if(a[j].first >k){
                // update for this index in BIT
                update(a[j].second,BIT,n);
                // now this element is no more required
                a.pop_back();
            }else{
                break;
            }
        }
        // save answer for this query 
        ans[index]=query(r,BIT,n)-query(l-1,BIT,n);
    }

    for(int i=1;i<=events.size();i++){
        cout<<ans[i]<<"\n";
    }

	return 0;
}
