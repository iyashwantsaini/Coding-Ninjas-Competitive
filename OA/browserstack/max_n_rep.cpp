/*
Given a list of words return 1 and 0 for each word depending on whether they have at max n repetition of a single character in them
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> words ={"xxaadv","xxfvsaasdqa","acdwecacsa","afwefcwvw"};
    char c ='a';
    int n=3;
    int count=0;

    for(int i=0;i<words.size();i++){
        count=0;
        for(int j=0;j<words[i].size();j++){
            if(words[i][j]==c){
                count++;
            }
        }
        if(count==n){
            cout<<1<<" ";
        }else{
            cout<<0<<" ";
        }
    }

    return 0;
}