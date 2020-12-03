// finding longest prefix which is also a suffix for every index (for KMP)
// adadabadadabadadad

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

int main(){
    string pattern="adadabadadabadadad";
    int *ans=getlps(pattern);
    for(int i=0;i<pattern.length();i++){
        cout<<ans[i]<<" ";
    }cout<<"\n";
    return 0;
}