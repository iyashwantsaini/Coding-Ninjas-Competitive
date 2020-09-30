#include<bits/stdc++.h>
using namespace std;

// return first non rep char in string
// if not found return first

int main(){
    string s="aabbcccdeefghhg";
    map<char,int> m;
    for(int i=0;i<s.length();i++){
        m[s[i]]++;
    }
    for(int i=0;i<s.length();i++){
        if(m[s[i]]==1){
            cout<< s[i];
            return 0;
        }
    }
    cout<< s[0];
    return 0;
}