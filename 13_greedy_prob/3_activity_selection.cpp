/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare(pair<int,int> p1,pair<int,int> p2){
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    return p1.second<p2.second;
}

int main()
{
    int n;
    cin>>n;
    // contains times for ending and start of an activity
    vector<pair<int,int>> t; 
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        t.push_back(make_pair(start,end));
    }
    sort(t.begin(),t.end(),compare);
    // for(int i=0;i<t.size();i++){
    //     cout<<t[i].first<<" "<<t[i].second<<endl;
    // }
    pair<int,int> prev;
    prev.first=t[0].first;
    prev.second=t[0].second;
    int count=1;
    for(int i=1;i<t.size();i++){
        if(t[i].first>=prev.second){
            count++;
            prev.first=t[i].first;
        	prev.second=t[i].second;
        }
    }
    cout<<count;
    return 0;
}