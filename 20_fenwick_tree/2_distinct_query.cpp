/*
Given a sequence of n numbers a1, a2, ..., an and a number of d-queries. A d-query is a pair (i, j) (1 ≤ i ≤ j ≤ n). For each d-query (i, j), you have to return the number of distinct elements in the subsequence ai, ai+1, ..., aj.
Input
Line 1: n (1 ≤ n ≤ 30000).
Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^6).
Line 3: q (1 ≤ q ≤ 200000), the number of d-queries.
In the next q lines, each line contains 2 numbers i, j representing a d-query (1 ≤ i ≤ j ≤ n).
Output
For each d-query (i, j), print the number of distinct elements in the subsequence ai, ai+1, ..., aj in a single line.
Sample Input
5
1 1 2 1 3
3
1 5
2 4
3 5
Sample Output
3
2
3 
*/

#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int s,e,index;
};

bool compare(node a,node b){
    if(a.e==b.e){
        return a.s<b.s;
    }
    return a.e<b.e;
}

void update(int n,int index,int *BIT,int type){
    // type 0=>increment
    if(type==0){
        for(;index<=n;index+=index&(-index)){
            BIT[index]++;
        }
    }
    // type 1=>decrement
    else{
        for(;index<=n;index+=index&(-index)){
            BIT[index]--;
        }
    }
}

int query(int index,int *BIT){
    int count=0;
    for(;index>0;index-=index&(-index)){
        count+=BIT[index];
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int *a=new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int q;
    cin>>q;
    node *queries=new node[q];
    for(int i=0;i<q;i++){
        cin>>queries[i].s>>queries[i].e;
        queries[i].index=i;
    }
    // sort on basis of end index
    sort(queries,queries+q,compare);

    int *BIT=new int[n+1]{};
    // k=>maintains index in queries
    int k=0;
    // prev=>to maintain last occurance index of all elements
    int *prev=new int[1000001];
    for(int i=0;i<=1000000;i++){
        prev[i]=-1;
    }
    // total=> to maintain the number of elements till current element
    int total=0;
    // ans=>to store answers of queries in correct incoming order
    int *ans=new int[q+1]{};
    for(int i=1;i<=n;i++){
        // if previous of current does not exist => means its unique => update
        if(prev[a[i]]==-1){
            // increment in BIT
            update(n,i,BIT,0);
            // increment total number of elements
            total++;
        }
        // remove previous existance of element, add current
        else{
            // decrement previous occurance of current by 1
            update(n,prev[a[i]],BIT,1);
            // increment in BIT
            update(n,i,BIT,0);
        }
        // now we can get answers for querues ending at this ith index
        while(k<q&&queries[k].e==i){
            // ans[queries[k].index]=query(queries[k].e,BIT)-query(queries[k].s-1,BIT);
            // OR
            ans[queries[k].index]=total-query(queries[k].s-1,BIT);
            k++;
        }
        prev[a[i]]=i;
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
