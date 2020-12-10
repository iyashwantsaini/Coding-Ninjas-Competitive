/*
Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.
INPUT
First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.

Next q lines follow, each line having a string t, which needs to be completed.
OUTPUT
Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
CONSTRAINTS
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
total length of all strings in database entries ≤ 10^6
total length of all query strings ≤ 10^6
SAMPLE INPUT
2 1
hackerearth 10
hackerrank 9
hacker
SAMPLE OUTPUT
10
*/

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        // current value
        char a;
        int wt;
        // vector of children nodes
        // vector<node> *nodes=new vector<node>;
        node **children;
        node(){
            children=new node*[26];
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            wt=0;
        }
};

void insert(node *head,int n,string s,int w){
    node *curr=head;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        // search for children of currrent node to find if character already present 
        if(curr->children[c-'a']!=NULL){
            curr=curr->children[c-'a'];
            if(curr->wt<w){
                curr->wt=w;
            }
            // cout<<curr->a<<" "<<curr->wt<<" \n";
        }else{
        // character not already present in trie
            node *current;
            current=new node();
            current->a=c;
            current->wt=w;
            curr->children[c-'a']=current;
            curr=curr->children[c-'a'];
            // cout<<curr->a<<" "<<curr->wt<<" \n";
        }
    }
}

int query(node *head,int n,string t){
    node *curr=head;
    for(auto i=t.begin();i!=t.end();i++){
        char c=*i;
        int flag=0;
        if(curr->children[c-'a']!=NULL){
            curr=curr->children[c-'a'];
            flag=1;
        }
        if(flag==0){
            return -1;
        }
    }
    return curr->wt;
}

int main(){
    int n,q;
    cin>>n>>q;
    node *head=new node();
    string s;
    int w;
    for(int i=0;i<n;i++){
        cin>>s>>w;
        // insert in trie
        insert(head,n,s,w);
    }
    while(q--){
        string t;
        cin>>t;
        // logic
        cout<<query(head,n,t)<<"\n";
    }
    return 0;
}