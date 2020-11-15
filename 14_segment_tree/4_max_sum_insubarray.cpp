/*
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
        int sum=INT_MIN;
        int maxsum=INT_MIN;
        int bestprefixsum=INT_MIN;
        int bestsuffixsum=INT_MIN;
};

void build(int *a,node *tree,int s,int e,int i){
    // base case
    if(s==e){
        tree[i].sum=a[s];
        tree[i].maxsum=a[s];
        tree[i].bestprefixsum=a[s];
        tree[i].bestsuffixsum=a[s];
        return;
    }
    // build left and right trees
    int mid=(s+e)/2;
    build(a,tree,s,mid,i*2);
    build(a,tree,mid+1,e,i*2+1);
    
    // save values in current node from left and right children
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    tree[i].bestprefixsum=max(tree[i*2].bestprefixsum,tree[i*2].sum+tree[i*2+1].bestprefixsum);
    tree[i].bestsuffixsum=max(tree[i*2+1].bestsuffixsum,tree[i*2+1].sum+tree[i*2].bestsuffixsum);
    tree[i].maxsum=
    max(
        tree[i*2].bestsuffixsum+tree[i*2+1].bestprefixsum,
        max(
            max(
                tree[i*2].maxsum,
                tree[i*2+1].maxsum
            ),
            max(
                tree[i*2].sum+tree[i*2+1].bestprefixsum,
                tree[i*2+1].sum+tree[i*2].bestsuffixsum
            )
        )
    ); 
}

node query(node *tree,int s,int e,int i,int l,int r){
    // 3 cases
    // completely out
    if(e<l||s>r){
        node temp;
        // cant use int_min here as it will become +ve when some number is subtracted from it during recursion 
        temp.sum=-100000;
        temp.maxsum=-100000;
        temp.bestprefixsum=-100000;
        temp.bestsuffixsum=-100000;
        return temp;
    }
    // completely in
    if(s>=l&&e<=r){
        return tree[i];
    }
    // partially in, partially out 
    int mid=(s+e)/2;

    node lchild=query(tree,s,mid,i*2,l,r);
    node rchild=query(tree,mid+1,e,i*2+1,l,r);

    node ans;
    ans.sum=lchild.sum+rchild.sum;
    ans.bestprefixsum=max(lchild.bestprefixsum,lchild.sum+rchild.bestprefixsum);    
    ans.bestsuffixsum=max(rchild.bestsuffixsum,rchild.sum+lchild.bestsuffixsum);
    ans.maxsum=
    max(
        lchild.bestsuffixsum+rchild.bestprefixsum,
        max(
            max(
                lchild.maxsum,
                rchild.maxsum
            ),
            max(
                lchild.sum+rchild.bestprefixsum,
                rchild.sum+lchild.bestsuffixsum
            )
        )
    );
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
    int n;
    cin>>n;
    int *a=new int[n+1]{};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    node *tree=new node[4*n];
    // start=1,end=n,i=1
    build(a,tree,0,n-1,1);
    int m;
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        // start=1,end=n,i=1
        node ans=query(tree,0,n-1,1,l-1,r-1);
        cout<<ans.maxsum<<"\n";
    }
    return 0;
}