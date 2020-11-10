// https://dmoj.ca/problem/coci13c1p4

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare(int item1[],int item2[]){
    if(item1[1]!=item2[1]){
        return item1[1]>item2[1];
    }
    return item1[0]<item2[0];
}

int main(){
    
    // inputs
    int n,k;
    cin>>n>>k;
    int **items=new int*[n];
    for(int i=0;i<n;i++){
        items[i]=new int[2];
    }
    for(int i=0;i<n;i++){
        cin>>items[i][0]>>items[i][1];
    }
    multiset<int> bags;
    for(int i=0;i<k;i++){
        int wt;
        cin>>wt;
        bags.insert(wt);
    }

    // logic
    sort(items,items+n,compare);
    // find the best bag possible for every element
    // means find the most fittest bag possible for the item
    ll ans=0;
    for(int i=0;i<n;i++){
        if(bags.empty()){
            break;
        }
        else if(bags.lower_bound(items[i][0])!=bags.end()){
            ans+=items[i][1];
            bags.erase(bags.lower_bound(items[i][0]));
        }
    }
    cout<<ans<<endl;
}