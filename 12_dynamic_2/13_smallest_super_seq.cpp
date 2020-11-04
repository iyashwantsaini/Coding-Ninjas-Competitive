/*
Given two strings S and T, find and return the length of their smallest super-sequence.
A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
Input Format:
Line 1 : A string
Line 2: Another string
Output Format:
Length of the smallest super-sequence of given two strings. 
Sample Input:
ab
ac
Sample Output:
3
Sample Output Explanation:
Their smallest super-sequence can be "abc" which has length=3.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// c1,c2 current indices of string in process
int smallest(char s1[],char s2[],int l1,int l2,int c1,int c2,int **dp){
    // both strings ended
    if(c1==l1&&c2==l2){
        return 0;
    }
    // work already done
    if(dp[c1][c2]!=-1){
        return dp[c1][c2];
    }
    int ans;
    // c1 ended
    if(c1==l1){
        ans=l2-c2;
    }
    // c2 ended
    else if(c2==l2){
        ans=l1-c1;
    }
    else{
        // first equal
        if(s1[c1]==s2[c2]){
            ans= 1+smallest(s1,s2,l1,l2,c1+1,c2+1,dp);
        }
        // non equal
        else{
            ans= 1+min(
                smallest(s1,s2,l1,l2,c1+1,c2,dp),
                smallest(s1,s2,l1,l2,c1,c2+1,dp)
            );
        }
    } 
    dp[c1][c2]=ans;
    return ans;
}

int smallestSuperSequence(char str1[], int len1, char str2[], int len2) {
    int **dp=new int*[len1+1];
    for(int i=0;i<=len1;i++){
        dp[i]=new int[len2+1];
        for(int j=0;j<=len2;j++){
            dp[i][j]=-1;
        }
    }
    int ans=smallest(str1,str2,len1,len2,0,0,dp);
    for(int i=0;i<=len1;i++){
        delete dp[i];
    }
    delete dp;
    return ans;
}

int main()
{
    char str1[50], str2[50];
    cin>>str1;
    cin>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = smallestSuperSequence(str1, len1, str2, len2);
    cout<<min_len;
    return 0;
}
