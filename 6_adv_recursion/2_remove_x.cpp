// remove all x from string recursively

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void rem_x(char *s){
    if(s[0]=='\0'){
        return;
    }
    if(s[0]!='x'){
        rem_x(s+1);
    }
    else{
        // s[0]==x
        int i=0;
        // null will alse be copied this way
        for(;s[i]!='\0';i++){
            s[i]=s[i+1];
        }
        rem_x(s);
    }
}

int main(){
    char s[100];
    cin>>s;
    rem_x(s);
    cout<<s;
}