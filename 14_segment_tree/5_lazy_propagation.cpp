// in lazy propagation we only update when required, else we just save the required updates for future
/*
we'll make a minimum number in array segment tree

input
4
1 3 -2 4
2
U 1 4 3
U 1 2 2
out

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void view_tree(int n,int *tree){
    for(int i=1;i<=4*n;i++){
        cout<<tree[i]<<" ";
    }
    cout<<"\n";
}
void view_lazy(int n,int *lazy){
    for(int i=1;i<=4*n;i++){
        cout<<lazy[i]<<" ";
    }
    cout<<"\n";
}

void build_tree(int *a,int *tree,int s,int e,int i){
    // base case
    if(s==e){
        tree[i]=a[s];
        return;
    }
    int mid=(s+e)/2;
    build_tree(a,tree,s,mid,i*2);
    build_tree(a,tree,mid+1,e,i*2+1);
    tree[i]=min(tree[i*2],tree[i*2+1]);
}

int query_tree(int *tree,int s,int e,int i,int l,int r){
    // implement it later
    return 0;
}

void update_tree(int *a,int *tree,int *lazytree,int s,int e,int i,int l,int r,int increment){
    if(s>e){
        return;
    }
    // if some updations remaining in lazy tree
    if(lazytree[i]!=0){
        // update
        tree[i]+=lazytree[i];
        // tell children to update
        if(s!=e){
            lazytree[i*2]+=lazytree[i];
            lazytree[i*2+1]+=lazytree[i];
        }
        // reset current lazy index to 0
        lazytree[i]=0;
    }
    // 3 conditions
    // completely outside
    if(l>e||r<s){
        return;
    }
    // completely inside
    if(s>=l&&e<=r){
        tree[i]+=increment;
        // tell child lazy to update when required
        if(s!=e){
            lazytree[i*2]+=increment;
            lazytree[i*2+1]+=increment;
        }
        return;
    }
    // partially in, partially out
    int mid=(s+e)/2;
    update_tree(a,tree,lazytree,s,mid,i*2,l,r,increment);
    update_tree(a,tree,lazytree,mid+1,e,i*2+1,l,r,increment);
    tree[i]=min(tree[i*2],tree[i*2+1]);
}

int main(){
    int n;
    cin>>n;
    int *a=new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int *tree=new int[4*n];
    int *lazytree=new int[4*n]{};
    build_tree(a,tree,1,n,1);
    view_tree(n,tree);
    view_lazy(n,lazytree);

    int m;
    cin>>m;
    while(m--){
        char qtype;
        cin>>qtype;
        if(qtype=='Q'){
            int x,y;
            cin>>x>>y;
            int ans=query_tree(tree,1,n,1,x,y);
            cout<<ans<<"\n";
        }else{
            int lrange,rrange,val;
            cin>>lrange>>rrange>>val;
            update_tree(a,tree,lazytree,1,n,1,lrange,rrange,val);
            view_tree(n,tree);
            view_lazy(n,lazytree);
        }
    }

    return 0;
}