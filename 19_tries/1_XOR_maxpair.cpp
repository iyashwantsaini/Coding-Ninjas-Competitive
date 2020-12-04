// given some elements, find max XOR pair among them

#include<bits/stdc++.h>
using namespace std;

//  we'll create here a 32 bit tree to save even higher numbers
class trienode{
    public:
        trienode *left; //for 0
        trienode *right; //for 1
};   

// builds trie based on array elements binary form
void insert(int val,trienode *head){
    trienode *current=head;
    for(int i=31;i>=0;i--){
        // eg i=32 , then right shift i times given us the 31'st bit
        int b=(val>>i)&1;
        
        // move left
        if(b==0){
            // check if left exists
            if(!current->left){
                // create
                current->left=new trienode();
            }
            current=current->left;
        }else{
        // move right
            // check if right exists
            if(!current->right){
                // create
                current->right=new trienode();
            }
            current=current->right;
        }
    }
}

int find_maxXORpair(trienode *head,int *arr,int n){
    int max_xor=INT_MIN;
    // for each array element
    for(int i=0;i<n;i++){
        int val=arr[i];
        trienode *current=head;
        int curr_xor=0;
        // for each bit
        for(int j=31;j>=0;j--){
            int b=(val>>j)&1;
            // move right
            // if my bit is 0 then we want 1
            if(b==0){
                if(current->right){
                    curr_xor+=pow(2,j);
                    current=current->right;
                }else{
                    current=current->left;
                }
            // move left
            }else{
                if(current->left){
                    curr_xor+=pow(2,j);
                    current=current->left;
                }else{
                    current=current->right;
                }
            }
        }
        if(curr_xor>max_xor){
            max_xor=curr_xor;
        }
    }
    return max_xor;
}

int main(){
    int arr[6]={8,1,2,15,10,5};
    trienode *head=new trienode();
    for(int i=0;i<6;i++){
        insert(arr[i],head);
    }
    cout<<find_maxXORpair(head,arr,6);
    return 0;
}