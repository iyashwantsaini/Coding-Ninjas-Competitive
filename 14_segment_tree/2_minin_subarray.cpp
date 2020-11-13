/*
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void buildtree(int *a,int *tree,int s,int e,int i){
    // base case
    if(s==e){
        tree[i]=a[s];
        return;
    }
    // build right and left
    int mid=(s+e)/2;
    // build left
    buildtree(a,tree,s,mid,2*i);
    // build right
    buildtree(a,tree,mid+1,e,2*i+1);
    // after building the complete r&l trees update current node
    tree[i]=min(tree[i*2],tree[i*2+1]);
    return;
}

// i= current node index
// index= index of element to change
// val= value to put at index
void updatetree(int *arr,int *tree,int s,int e,int i,int index,int val){
    // base case
    if(s==e){
        arr[index]=val;
        tree[i]=val;
        return;
    }
    // update to the required branch only
    int mid=(s+e)/2;
    if(index>mid){
        // move right
        updatetree(arr,tree,mid+1,e,i*2+1,index,val);
    }else{
        // move left
        updatetree(arr,tree,s,mid,i*2,index,val);
    }
    // update after updation of children
    tree[i]=min(tree[i*2],tree[i*2+1]);
}

int querytree(int *tree,int s,int e,int i,int l,int r){
    // base case - with it some cases fail
    // if(s==e){
    //     return tree[i];
    // }
    // 3 options
    // completely in range
    if(s>=l&&e<=r){
        return tree[i];
    }
    // completely outside range
    if(l>e||r<s){
        return INT_MAX;
    }
    // partially in , partially out range
    int mid=(s+e)/2;
    int lmin=querytree(tree,s,mid,i*2,l,r);
    int rmin=querytree(tree,mid+1,e,i*2+1,l,r);
    return min(lmin,rmin);
}

void viewtree(int *tree,int n){
    for(int i=1;i<=2*n;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
    int n,q;
    cin>>n>>q;
    int *a=new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    // as max size of tree can be nearly equal to 4n in worst case
    int *tree=new int[4*n+1]{};
    // array start=1,end=n-1
    // tree start(root) = at 1 index
    buildtree(a,tree,1,n,1);
    // viewtree(tree,n);

    while(q--){
        char qtype; // u or q
        int first,second;
        cin>>qtype>>first>>second;
        if(qtype=='u'){
            // first=index
            // second=val
           updatetree(a,tree,1,n,1,first,second);
        }else{
            // range=l to r
            // first=left of range
            // second=right of range
            int ans=querytree(tree,1,n,1,first,second);
            cout<<ans<<'\n';
        }
    }

    delete a;
    delete tree;
    return 0;
}