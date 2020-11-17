/*
Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri
Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output
2
2
4
5
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class warrior{
    public:
        int a;
        int b;
};

class node{
    public:
        int a;
        int b;
        int index;
};

void build_tree(warrior *w,node *tree,int s,int e,int i){
    // base case
    if(s==e){
        tree[i].a=w[s].a;
        tree[i].b=w[s].b;
        tree[i].index=s;
        return;
    }
    // build children
    int mid=(s+e)/2;
    build_tree(w,tree,s,mid,i*2);
    build_tree(w,tree,mid+1,e,i*2+1);

    // fix current
    // set current as the one having greater "A"
    // if "A" is same set to the one having less "B"
    // if "A" is same & "B" is same, set to the one having less index
    
    node left=tree[i*2];
    node right=tree[i*2+1];

    // choose on basis of a
    if(left.a>right.a){
        tree[i].index=left.index;
        tree[i].a=left.a;
        tree[i].b=left.b;
    }else if(right.a>left.a){
        tree[i].index=right.index;
        tree[i].a=right.a;
        tree[i].b=right.b;
    }else{
        // choose on basis of b
        if(left.b<left.b){
            tree[i].index=left.index;
            tree[i].a=left.a;
            tree[i].b=left.b;
        }else if(right.b<left.b){
            tree[i].index=right.index;
            tree[i].a=right.a;
            tree[i].b=right.b;
        }else{
            // choose on basis of index
            if(left.index<right.index){
                tree[i].index=left.index;
                tree[i].a=left.a;
                tree[i].b=left.b;
            }else{
                tree[i].index=right.index;
                tree[i].a=right.a;
                tree[i].b=right.b;
            }
        }
    }
}

void view_tree(int n,node *tree){
    for(int i=1;i<4*n;i++){
        cout<<tree[i].index<<" ";
    }
    cout<<"\n";
}

node find_warr(node *tree,int s,int e,int i,int l,int r){
    // 3 cases
    // completely out
    if(l>e||r<s){
        node ans;
        ans.a=INT_MIN;
        ans.b=INT_MAX;
        ans.index=INT_MAX;
        return ans;
    }
    // completely in
    if(s>=l&&e<=r){
        return tree[i];
    }
    // partially in, partially out
    int mid=(s+e)/2;
    node left=find_warr(tree,s,mid,i*2,l,r);
    node right=find_warr(tree,mid+1,e,i*2+1,l,r);
    if(left.a>right.a){
        return left;
    }else if(right.a>left.a){
        return right;
    }else{
        if(left.b<right.b){
            return left;
        }else if(right.b<left.b){
            return right;
        }else{
            if(left.index<right.index){
                return left;
            }else{
                return right;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    warrior *w=new warrior[n+1];
    for(int i=1;i<=n;i++){
        cin>>w[i].a;
    }
    for(int i=1;i<=n;i++){
        cin>>w[i].b;
    }
    node *tree=new node[4*n]{};
    build_tree(w,tree,1,n,1);
    // view_tree(n,tree);

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        node ans=find_warr(tree,1,n,1,l,r);
        cout<<ans.index<<endl; 
    }
    return 0;
}