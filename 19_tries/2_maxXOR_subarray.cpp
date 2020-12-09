/*
Given an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 
Sample Input
4
1 2 3 4
Sample Output
7
*/

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        node *left; //for 0
        node *right; //for 1
};

void insert(node *head,int num){
    node *curr=head;
    // find every bit in num from left to right
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1;
        if(bit==1){
            // move right
            // not present create
            if(!curr->right){
                curr->right=new node();
            }
            curr=curr->right;
        }else{
            // move left
            // not present create
            if(!curr->left){
                curr->left=new node();
            }
            curr=curr->left;
        }
    }
}

int find_xor(int n,int *a){
    // int max_xor=INT_MIN;
    node *head=new node();

    // 1st element added to tree
    insert(head,a[0]);

    // iterate over all elements
    // upto_xor contains xor of all elements upto current i
    int upto_xor=a[0];
    int max_xor=a[0];

    for(int i=1;i<n;i++){
        node *curr=head;

        // int curr_num=a[i];
        upto_xor=upto_xor^a[i];
        
        if(upto_xor>max_xor){
            max_xor=upto_xor;
        }

        // find value which makes best max XOR
        int curr_max=0;
        for(int j=31;j>=0;j--){
            int bit=(upto_xor>>j)&1;
            if(bit==0){
                // we need to move right now as xor(0,1)=1
                if(curr->right){
                    curr_max+=pow(2,j);
                    curr=curr->right;
                }else{
                    curr=curr->left;
                }
            }else{
                // we need to move left now as xor(0,1)=1
                if(curr->left){
                    curr_max+=pow(2,j);
                    curr=curr->left;
                }else{
                    curr=curr->right;
                }
            }
        }
        if(curr_max>max_xor){
            max_xor=curr_max;
        }

        insert(head,upto_xor);
    }
    // iterate over all possible in tree

    return max_xor;
}

int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<find_xor(n,a)<<"\n";
    return 0;
}