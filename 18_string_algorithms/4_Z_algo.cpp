#include<bits/stdc++.h>
using namespace std;

// z at each index gives longest substring which is in prefix
void build(int *z,string str){
    int l=0;
    int r=0;
    int n=str.length();
    for(int i=1;i<n;i++){
        // i does not lie in range of l and r
        // z for this does not exit
        if(i>r){
            l=i;
            r=i;
            // comparing current with previous elements
            while(r<n&&str[r-l]==str[r]){
                r++;
            }
            z[i]=r-l;
            r--;
        }else{
            int k=i-l;
            if(z[k]<=r-i){
                // i lies between l and r
                // z will exist previously
                z[i]=z[k];
            }else{
                // some part of z is already included
                // we have to start matching further
                while(r<n&&str[r-l]==str[r]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }
        }

    }
}

void searchstring(string text,string pattern){
    string str=pattern+"$"+text;
    int n=str.length();
    int *z=new int[n]{};
    build(z,str);
    for(int i=0;i<n;i++){
        if(z[i]==pattern.length()){
            // print the index from where the pattern is present in the original string
            cout<<i-pattern.length()-1<<"\n";
        }
    }
}

int main(){
    string text="abcdsafbcdfasbcda";
    string pattern="bcd";
    searchstring(text,pattern);
    return 0;
}