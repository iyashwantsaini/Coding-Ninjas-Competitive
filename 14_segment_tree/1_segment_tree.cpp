// build,update,query a segment tree

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void buildtree(int arr[],int *tree,int s,int e,int i){
    // cout<<s<<" "<<e<<endl;
    // base cases - when we reach to leaf
    // the answer is the element at arr[s]or arr[e] itself
    if(s==e){
        tree[i]=arr[s];
        return;
    }
    int mid=(s+e)/2;
    buildtree(arr,tree,s,mid,i*2);
    buildtree(arr,tree,mid+1,e,i*2+1);
    tree[i]=tree[i*2]+tree[i*2+1];
}

// log(n)
// i = index of starting of filling in tree array, initially 1
// index = index in array, val=value of array
void updatetree(int arr[],int *tree,int s,int e,int i,int index,int val){
    // base case
    if(s==e){
        arr[index]=val;
        tree[i]=val;
        return;
    }
    
    int mid=(s+e)/2;
    // go right side
    if(index>mid){
        updatetree(arr,tree,mid+1,e,2*i+1,index,val);
    }else{
    // go left side
        updatetree(arr,tree,s,mid,2*i,index,val);
    }
    // after all updation of children is  done
    tree[i]=tree[i*2+1]+tree[i*2];
}

// log(n)
// i=starting of indexing in tree, initially (root) = 1
int querytree(int *tree,int s,int e,int i,int l,int r){
    // 3 cases possible
    // completely outside the given range
    if(s>r||e<l){
        return 0;
    }
    // completely inside the given range
    if(s>=l&&e<=r){
        return tree[i];
    }
    // partially inside, partially outside the given range
    int mid=(s+e)/2;
    int leftans=querytree(tree,s,mid,2*i,l,r);
    int rightans=querytree(tree,mid+1,e,2*i+1,l,r);
    return leftans+rightans;
}

void viewtree(int *tree,int n){
    // as we have saved starting from 1st index
    for(int i=1;i<2*n;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n=5;
    int arr[n]={1,2,3,4,5};
    int *tree=new int[n*2];
    
    // build a tree from 0 to 4 and put the first element at index 1
    buildtree(arr,tree,0,4,1);
    viewtree(tree,n);
    
    // update the array at arr[2]=10, so update the tree respectively
    // start the tree filling from 1st index, root=1
    updatetree(arr,tree,0,4,1,2,10);
    viewtree(tree,n);

    // get sum of arr[2] to arr[4] | both included
    // l=2,r=4
    int q=querytree(tree,0,4,1,2,4);
    cout<<q<<endl;

    delete tree;
    return 0;
}