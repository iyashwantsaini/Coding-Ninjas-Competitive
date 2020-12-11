/*
problem - find sum withing given ranges
range i/o - from 1 to N
input -
8
1 2 3 4 5 6 7 8
2
1 5
2 6
output -

*/

#include<bits/stdc++.h>
using namespace std;

void update(int n,int index,int val,int *BIT){
    // eg for updation we need to go to all possible update positions in tree
    // 1->2->4->8 => i+=i&(-i)
    for(;index<=n;index+=index&(-index)){
        BIT[index]+=val;
    }
}

int query(int n,int *a,int *BIT,int index){
    // eg for query we need to go to all possible parents of current index node
    // 7->6->4->0 => i-=i&(-i) 
    int sum=0;
    for(;index>0;index-=index&(-index)){
        sum+=BIT[index];
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    int *a=new int[n+1]{};
    int *BIT=new int[n+1]{};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(n,i,a[i],BIT);
    }
    int q;
    cin>>q;
    // eg find sum of 3 to 7
    // => query(0,7)-query(0,2)
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(n,a,BIT,r)-query(n,a,BIT,l-1)<<"\n";
    }
    return 0;
}