/*
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].

Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.

Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// node for segment tree
struct node{
    int mx=0;
    int smx=0;
};

void build_tree(int *a,node *tree,int s,int e,int i){
    // base case
    if(s==e){
        tree[i].mx=a[s];
        // as there is no min than current val at leaf
        tree[i].smx=INT_MIN;
        return;
    }
    // build left and right
    int mid=(s+e)/2;
    // lbuild
    build_tree(a,tree,s,mid,i*2);
    // rbuild
    build_tree(a,tree,mid+1,e,i*2+1);
    
    // updating tree at current index
    tree[i].mx=max(
        tree[i*2].mx,
        tree[i*2+1].mx
    );
    tree[i].smx=min(
        max(
            tree[i*2].smx,tree[i*2+1].mx
        ),
        max(
            tree[i*2+1].smx,tree[i*2].mx
        )
    );
}

node query_tree(node *tree,int s,int e,int i,int l,int r){
    // 3 cases
    // completely ouside
    if(e<l||s>r){
        node a;
        a.mx=INT_MIN;
        a.smx=INT_MIN;
        return a;
    }
    // completely inside
    if(s>=l&&e<=r){
        return tree[i];
    }
    // partially in, partially out
    int mid=(s+e)/2;
    node lans=query_tree(tree,s,mid,i*2,l,r);
    node rans=query_tree(tree,mid+1,e,i*2+1,l,r);

    node ans;
    ans.mx=max(lans.mx,rans.mx);
    ans.smx=min(max(lans.mx,rans.smx),max(lans.smx,rans.mx));
    return ans;
}

// logn
void update_tree(int *a,node *tree,int s,int e,int i,int index,int val){
    // base case - reched the required leaf node
    if(s==e){
        a[index]=val;
        tree[i].mx=val;
        tree[i].smx=INT_MIN;
        return;
    }
    int mid=(s+e)/2;
    if(index>mid){
        // move right
        update_tree(a,tree,mid+1,e,i*2+1,index,val);
    }
    else{
        // move left
        update_tree(a,tree,s,mid,i*2,index,val);
    }
    tree[i].mx=max(
        tree[i*2].mx,
        tree[i*2+1].mx
    );
    tree[i].smx=min(
        max(
            tree[i*2].mx,tree[i*2+1].smx
        ),
        max(
            tree[i*2].smx,tree[i*2+1].mx
        )
    );
}

void view_tree(int n,node *tree){
    for(int i=1;i<=4*n;i++){
        cout<<tree[i].mx<<" "<<tree[i].smx<<"\n";
    }
}

int main(){
    int n;
    cin>>n;
    int *a=new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    // build tree - take 4*n    
    node *tree=new node[4*n];
    // tree from 1 to n
    // array from 1 to n
    build_tree(a,tree,1,n,1);
    // view_tree(n,tree);
    int q;
    cin>>q;
    while(q--){
        char qtype;
        int x,y;
        cin>>qtype>>x>>y;
        if(qtype=='Q'){
            // query
            node ans=query_tree(tree,1,n,1,x,y);
            cout<<ans.mx+ans.smx<<endl;
        }else{
            // update
            update_tree(a,tree,1,n,1,x,y);
            // view_tree(n,tree);
        }
    }
    delete a;    
    return 0;
}

// below approach only works for sorted array

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// void build_tree(int *a,int *tree,int s,int e,int i){
//     // base case
//     if((e-s)==1){
//         tree[i]=a[s]+a[e];
//         return;
//     }
//     // build left and right tree
//     int mid=(s+e)/2;
//     // left
//     build_tree(a,tree,s,mid,i*2);
//     // right
//     build_tree(a,tree,mid,e,i*2+1);
//     tree[i]=max(tree[i*2],tree[i*2+1]);
// }

// void view_tree(int n,int *tree){
//     for(int i=1;i<=n+2;i++){
//         cout<<tree[i]<<" ";
//     }
//     cout<<"\n";
// }

// int query_tree(int *tree,int s,int e,int i,int l,int r){
//     // cout<<s<<" "<<e<<" "<<i<<" "<<l<<" "<<r<<" "<<"\n";
//     // 3 cases
//     // base case
//     if((e-s)==1){
//         if(s>=l&&e<=r){
//             // completely inside
//             return tree[i];
//         }else{
//             return INT_MIN;
//         }
//     }
//     // completely outside
//     if(r<s||l>e){
//         return 0;
//     }

//     // partially inside, patially out
//     int mid=(s+e)/2;
//     int lans=query_tree(tree,s,mid,i*2,l,r);
//     int rans=query_tree(tree,mid,e,i*2+1,l,r);
//     return max(lans,rans);
// }

// void update_tree(int *a,int *tree,int s,int e,int i,int index,int val){
//     // base case
//     if((e-s)==1){
//         a[index]=val;
//         tree[i]=a[s]+a[e];
//         return;
//     }
//     // build trees
//     int mid=(s+e)/2;
//     if(index>mid){
//         // build right tree
//         update_tree(a,tree,mid,e,i*2+1,index,val);
//     }else if(index<mid){
//         // build left tree
//         update_tree(a,tree,s,mid,i*2,index,val);
//     }else{
//         // index==mid
//         update_tree(a,tree,s,mid,i*2,index,val);
//         update_tree(a,tree,mid,e,i*2+1,index,val);
//     }
//     tree[i]=max(tree[i*2],tree[i*2+1]);
// }

// int main(){
//     int n;
//     cin>>n;
//     int *a=new int[n+1];
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//     }
//     // build tree
//     int *tree=new int[n+1]{};
//     // tree from 1 to n
//     // array from 1 to n
//     build_tree(a,tree,1,n,1);
//     view_tree(n,tree);
//     int q;
//     cin>>q;
//     while(q--){
//         char qtype;
//         int x,y;
//         cin>>qtype>>x>>y;
//         if(qtype=='Q'){
//             // query
//             int ans=query_tree(tree,1,n,1,x,y);
//             cout<<ans<<endl;
//         }else{
//             // update
//             update_tree(a,tree,1,n,1,x,y);
//             view_tree(n,tree);
//         }
//     }
//     delete a;    
//     return 0;
// }