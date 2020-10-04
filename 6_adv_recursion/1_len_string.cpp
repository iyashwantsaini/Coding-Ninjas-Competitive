// find length of string recursively

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int len(char *s){
    if(s[0]=='\0'){
        return 0;
    }
    return 1+len(s+1);
}

int main(){
    char s[100];
    cin>>s;
    cout<<len(s);
}