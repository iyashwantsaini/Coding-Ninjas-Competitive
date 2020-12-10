/*
A straightforward question. Given an array of positive integers you have to print the number of subarrays whose XOR is less than K. Subarrays are defined as a sequence of continuous elements Ai, Ai+1, ..., Aj . XOR of a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. Symbol ^ is Exclusive Or.
Input Format
First line contains T, the number of test cases. 
Each of the test case consists of N and K in one line, followed by N space separated integers in next line.
Output Format
For each test case, print the required answer.
Constraints:
1 ≤ T ≤ 5
1 ≤ N ≤ 10^5
1 ≤ A[i] ≤ 10^5
1 ≤ K ≤ 10^6
Sample Input
1
5 2
4 1 3 2 7
Sample Output
3
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
        node *left=NULL;
        node *right=NULL;
        ll left_=0;
    	ll right_=0;
};

void insert(ll num,node *head){
    node *curr=head;
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1;
        if(bit==1){
            curr->right_++;
            // move right
            if(!curr->right){
                curr->right=new node();
            }
            curr=curr->right;
        }else{
            curr->left_++;
            // move left
            if(!curr->left){
                curr->left=new node();
            }
            curr=curr->left;
        }
    }
}

ll find_num_subarrays(ll *a,int n,int k){
    ll num_lt=0;
    ll curr_xor=0;
    node *head=new node();
    insert(0,head);
    for(int i=0;i<n;i++){
        curr_xor=curr_xor^a[i];
        node *curr=head;
        if(!curr){
            return 0;
        }
        for(int j=31;j>=0;j--){
            int bit_x=(curr_xor>>j)&1;
            int bit_k=(k>>j)&1;
            // move smartly in trie to get only those subarrays whose xor is less than k
            if(bit_x==1&bit_k==1){
                num_lt+=curr->right_;
                if(curr->left){
                    curr=curr->left;
                }else{
                    break;
                }
            }else if(bit_x==0&bit_k==1){
                num_lt+=curr->left_;
                if(curr->right){
                    curr=curr->right;
                }else{
                    break;
                }
            }else if(bit_x==0&bit_k==0){
                if(curr->left){
                    curr=curr->left;
                }else{
                    break;
                }
            }else if(bit_x==1&bit_k==0){
                if(curr->right){
                    curr=curr->right;
                }else{
                    break;
                }
            }
        }
        insert(curr_xor,head);
    }
    return num_lt;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        ll *a=new ll[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<find_num_subarrays(a,n,k)<<"\n";
    }
    return 0;
}