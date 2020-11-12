// build a segment tree

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
    // start the tree filling from 1st index
    updatetree(arr,tree,0,4,1,2,10);
    viewtree(tree,n);



    delete tree;
    return 0;
}