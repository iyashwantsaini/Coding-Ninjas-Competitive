/*
Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
INPUT CONSTRAINTS
1≤N≤30000
sum(len(string[i]))≤2∗10^5
1≤Q≤10^3
INPUT FORMAT
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user
OUTPUT FORMAT
If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes

NOTE: All strings are lowercase
SAMPLE INPUT
3
fact
factorial
factory
2
fact
pradyumn
SAMPLE OUTPUT
fact
factorial
factory
No suggestions
*/

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        char c;
        node **children;
        int isleaf;
        node(){
            children=new node*[26];
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isleaf=0;
        }
};

void insert(node *head,string s){
    node *curr=head;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        // find if already present in trie
        if(curr->children[c-'a']!=NULL){
            curr=curr->children[c-'a'];
            // cout<<curr->c<<"\n";
        }
        // if not present create node
        else{
            node *newnode=new node();
            newnode->c=c;
            curr->children[c-'a']=newnode;
            curr=curr->children[c-'a'];
            // cout<<curr->c<<"\n";
        }
    }
    curr->isleaf=1;
}

// dfs helper
void dfs(node *current, string prefix){
    if (current->isleaf){
        cout << prefix << endl;
    }
    for (int i = 0; i < 26; i++){
        node *temp = current;
        if (temp->children[i] != NULL){
            char suffix = (int)i + (int)'a';
            dfs(current->children[i], prefix + suffix);
        }
    }
}

void dfs_trie(node *head,string s){
    node *curr=head;
    // first go upto length of given string in trie
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(curr->children[c-'a']!=NULL){
            curr=curr->children[c-'a'];
        }else{
            cout<<"No suggestions"<<"\n";
            // for improving next time insert it into trie
            insert(head,s);
            return;
        }
    }
    dfs(curr, s);
}

int main(){
    int n;
    cin>>n;
    node *head=new node();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        insert(head,s);
    }
    int q;
    cin>>q;
    while(q--){
        string t;
        cin>>t;
        dfs_trie(head,t);
        // insert(head,t);
    }
    return 0;
}