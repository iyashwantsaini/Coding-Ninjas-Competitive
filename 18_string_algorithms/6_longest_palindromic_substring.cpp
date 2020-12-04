// given a string, find the length of longest palindromic substring in the string

#include<bits/stdc++.h>
using namespace std;

int getlps(string s){
    int maxlen=0;
    int len=s.length();

    for(int i=0;i<len;i++){
        int l,r;

        // find for odd length
        l=i;
        r=i;
        int lenodd=0;
        while(l>=0&&r<len&&s[l]==s[r]){
            lenodd=r-l+1;
            if(lenodd>maxlen){
                maxlen=lenodd;
            }
            l--;
            r++;
        }

        // find for even length
        l=i;
        r=i+1;
        int leneven=0;
        while(l>=0&&r<len&&s[l]==s[r]){
            leneven=r-l+1;
            if(leneven>maxlen){
                maxlen=leneven;
            }
            l--;
            r++;
        }

    }
    return maxlen;
}

int main(){
    int len_lps=getlps("abbabbabbc");
    cout<<len_lps<<"\n";
    
    len_lps=getlps("abababece");
    cout<<len_lps<<"\n";

    len_lps=getlps("ababbabcba");
    cout<<len_lps<<"\n";

    return 0;
}