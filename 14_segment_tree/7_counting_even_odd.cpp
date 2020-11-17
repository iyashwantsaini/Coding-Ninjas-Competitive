/*
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
        int numodd=0;
        int numeven=0;
};

class lazynode{
    public:
        int evenrem=0;
        int oddrem=0;
};

void build(int *a,node *tree,int s,int e,int i){
    // base case
    if(s==e){
        if(a[s]%2==0){
            tree[i].numeven+=1;
        }else{
            tree[i].numodd+=1;
        }
        return;
    }
    // build children
    int mid=(s+e)/2;
    build(a,tree,s,mid,i*2);
    build(a,tree,mid+1,e,i*2+1);
    // fill current
    tree[i].numeven=tree[i*2].numeven+tree[i*2+1].numeven;
    tree[i].numodd=tree[i*2].numodd+tree[i*2+1].numodd;
}

void view_tree(int n,node *tree){
    for(int i=1;i<4*n;i++){
        cout<<tree[i].numeven<<" "<<tree[i].numodd<<"\n";
    }
}

void update_set(int *a,node *tree,lazynode *lazy,int s,int e,int i,int index,int val){
    // out of bound
    if(s>e){
        return;
    }
    // element reached
    if(s==e){
        a[index]=val;
        if(val%2==0){
            tree[i].numeven=1;
            tree[i].numodd=0;
        }else{
            tree[i].numodd=1;
            tree[i].numeven=0;
        }
        return;
    }
    int mid=(s+e)/2;
    if(index>mid){
        update_set(a,tree,lazy,mid+1,e,i*2+1,index,val);
    }else{
        update_set(a,tree,lazy,s,mid,i*2,index,val);
    }
    tree[i].numeven=tree[i*2].numeven+tree[i*2+1].numeven;
    tree[i].numodd=tree[i*2].numodd+tree[i*2+1].numodd;
}

int query_even(node *tree,int s,int e,int i,int l, int r){
    // completely outside
    if(l>e||r<s){
        return 0;
    }
    // completely inside
    if(s>=l&&e<=r){
        return tree[i].numeven;
    }
    // partially in, partially out
    int mid=(s+e)/2;
    int lans=query_even(tree,s,mid,i*2,l,r);
    int rans=query_even(tree,mid+1,e,i*2+1,l,r);
    return lans+rans;
}

int query_odd(node *tree,int s,int e,int i,int l, int r){
    // completely outside
    if(l>e||r<s){
        return 0;
    }
    // completely inside
    if(s>=l&&e<=r){
        return tree[i].numodd;
    }
    // partially in, partially out
    int mid=(s+e)/2;
    int lans=query_odd(tree,s,mid,i*2,l,r);
    int rans=query_odd(tree,mid+1,e,i*2+1,l,r);
    return lans+rans;
}

int main(){
    int n;
    cin>>n;
    int *a = new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    node *tree=new node[4*n];
    lazynode *lazy=new lazynode[4*n];

    build(a,tree,1,n,1);
    // view_tree(n,tree);

    int q;
    cin>>q;
    while(q--){
        int qtype,x,y;
        cin>>qtype>>x>>y;
        if(qtype==0){
            update_set(a,tree,lazy,1,n,1,x,y);
        }else if(qtype==1){
            int ans=query_even(tree,1,n,1,x,y);
            cout<<ans<<endl;
        }else{
            int ans=query_odd(tree,1,n,1,x,y);
            cout<<ans<<endl;
        }
    }
    return 0;
}