/* basic pattern matching
find if p is a substring of s
*/

// O(n*m)

#include<bits/stdc++.h>
using namespace std;

int is_found(string s,string p){
    int flag;
    for(int i=0;i<=s.length()-p.length();i++){
        flag=1;
        for(int j=0;j<p.length();j++){
            if(s[i+j]!=p[j]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    return flag;
}

int main(){
    string s="abcdabg";
    
    string p="cda";
    cout<<is_found(s,p)<<"\n";

    string p1="abe";
    cout<<is_found(s,p1)<<"\n";

    return 0;
}