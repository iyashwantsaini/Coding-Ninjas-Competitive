// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1/?company[]=BrowserStack&company[]=BrowserStack&page=1&query=company[]BrowserStackpage1company[]BrowserStack

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
        int val;
        node *prev;
        node(int data){
            val=data;
            prev=NULL;
        }
};

void printfac(node *tail){
    if(tail==NULL) return;
    printfac(tail->prev);
    cout<<tail->val<<" ";
}

// vector<int> factorial(int N){
void factorial(int N){
    // code here
    node *tail=new node(1);
    for(int i=2;i<=N;i++){
        node *x=tail;
        node *back=tail;
        int carry=0;
        while(x!=NULL){
            x->val=x->val*i+carry;
            carry=x->val/10;
            x->val=x->val%10;
            back=x;
            x=x->prev;
        }
        // x=back;
        while(carry!=0){
            back->prev=new node(carry);
            back->prev->val=carry%10;
            carry=carry/10;
            back=back->prev;
        }
    }
    printfac(tail);
    // cout<<"111";
    // vector<int> ans;
    // while(tail!=NULL){
    //     ans.push_back(tail->val);
    //     tail=tail->prev;
    // }
    // return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<int> ans = factorial(10);
    factorial(10);
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    return 0;
}