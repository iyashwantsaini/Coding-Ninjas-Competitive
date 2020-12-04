/*
Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
Input format :

Line 1 : String S

Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3
Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1
*/

#include <bits/stdc++.h>
using namespace std;

int *getlps(char pattern[],int len){
    // int len=0;
    // for(int i=0;pattern[i]!='\0';i++){
    //     cout<<pattern[i]<<" ";
    // }cout<<"\n";

    int *lps=new int[len]{};
    lps[0]=0;

    int i=1; //front
    int j=0; //back

    while(i<len){
        if(pattern[i]==pattern[j]){
            lps[i++]=lps[j++]+1;
        }else{
            if(j!=0){
                j=lps[j-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

// S and T - input strings
// You need to check if string T is present in S or not

int findString(char S[], char T[]) {
    // Write your code here
    int len_text=0;
    for(int i=0;S[i]!='\0';i++){
        len_text++;
    }
    int len_pattern=0;
    for(int i=0;T[i]!='\0';i++){
        len_pattern++;
    }

    int *lps=getlps(T,len_pattern);

    // for(int i=0;i<len_text;i++){
    //     cout<<lps[i]<<" ";
    // }cout<<"\n";
    
    int i=0,j=0;
    while(i<len_text&&j<len_pattern){
        // equal
        if(S[i]==T[j]){
            i++;
            j++;
            if(j==len_pattern){
                return i-len_pattern;
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
    return -1;
}


int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}
