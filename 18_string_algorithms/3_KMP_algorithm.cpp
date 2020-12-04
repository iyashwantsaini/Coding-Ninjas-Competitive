// KMP (Knuth Morris Pratt) Pattern Searching
// O(m)+O(n)

/*
    - step 1 = find longest prefix which is also a suffix
    - step 2 = kmp algo apply
*/

#include<bits/stdc++.h>
using namespace std;

int *getlps(string pattern){
    int len=pattern.length();
    int *lps=new int[len]{};
    lps[0]=0;

    int i=1; //front
    int j=0; //back

    while(i<len){
        // if equal,, move both forward
        if(pattern[i]==pattern[j]){
            lps[i++]=lps[j++]+1;
        }else{
            // j!=0 means go to value at (j-1)th index
            if(j!=0){
                j=lps[j-1];
            }else{
                // j==0 means lps[i] will be 0
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

bool kmpsearch(string text,string pattern,int *lps){
    int lentext=text.length();
    int lenpatt=pattern.length();

    int i=0,j=0;
    while(i<lentext&&j<lenpatt){
        // equal
        if(text[i]==pattern[j]){
            i++;
            j++;
            // checking if j has already reached its end
            // this is to avoid unncessary comparisions
            if(j==lenpatt){
                return true;
            }
        }else{
            // not equal
            // go to previous best prefix using lps array
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
    }
    // if j is ended at lenpatt, means all rest are found
    if(j==lenpatt){
        return true;
    }else{
        return false;
    }
    
}

int main(){
    // string pattern="adadabadadabadadad";
    // int *lps=getlps(pattern);
    // for(int i=0;i<pattern.length();i++){
    //     cout<<ans[i]<<" ";
    // }cout<<"\n";
    
    string text="abcxabcdabcdabcy";
    string pattern="abcdabcd";

    int *lps=new int[pattern.length()]{};
    lps=getlps(pattern);

    // for(int i=0;i<pattern.length();i++){
    //     cout<<lps[i]<<" ";
    // }cout<<"\n";

    bool ans=kmpsearch(text,pattern,lps);
    
    cout<<ans<<"\n";
    return 0;
}
