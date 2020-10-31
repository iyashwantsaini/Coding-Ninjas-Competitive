/*
find longest common subsequence in 2 strings
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// ierative approach
ll lcs_iter(string s1,string s2,ll **storage){

    // important
    // storage[i][j] - represents the last i chars and last j chars of s1,s2
    // so instead of 1st chars comparision like in recusrion, we'll compare last characters

    // fill 0th row - when 0 length remaining in s1
    for(int i=0;i<=s2.length();i++){
        storage[0][i]=0;
    }
    // fill 0th column - when 0 length remaining of s2
    for(int i=0;i<=s1.length();i++){
        storage[i][0]=0;
    }
    // filling rest using base cases
    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
            if(s1[s1.length()-i]==s2[s2.length()-j]){
                storage[i][j]=1+storage[i-1][j-1];
            }else{
                storage[i][j]=max(storage[i][j-1],storage[i-1][j]);
            }
        }
    }
    return storage[s1.length()][s2.length()];
}

// recursive approach
ll lcs_rec(string s1,string s2,ll **storage){
    // if end of string reached
    if(s1.length()==0||s2.length()==0){
        return 0;
    }

    // if work already done
    if(storage[s1.length()][s2.length()]>=0){
        return storage[s1.length()][s2.length()];
    }

    // if 1st char same
    if(s1[0]==s2[0]){
        ll ans=1+lcs_rec(s1.substr(1),s2.substr(1),storage);
        storage[s1.length()][s2.length()]=ans;
        return ans;
    }
    // if 1st char not same
    ll ans=max( lcs_rec(s1,s2.substr(1),storage) , lcs_rec(s1.substr(1),s2,storage) );
    storage[s1.length()][s2.length()]=ans;
    return ans;
}

int lcs(string s1, string s2)
{
    //Write your code here
    ll **storage=new ll*[s1.length()+1];
    for(int i=0;i<=s1.length();i++){
        storage[i]=new ll[s2.length()+1];
    }
    for(int i=0;i<=s1.length();i++){
        for(int j=0;j<=s2.length();j++){
            storage[i][j]=-1;
        }
    }
	
    // ll soln=lcs_rec(s1,s2,storage);
    ll soln=lcs_iter(s1,s2,storage);

    soln=(int)soln;

    for(int i=0;i<=s1.length();i++){
        delete storage[i];
    }
    delete storage;
    
    return soln;
}

int main(){

    string s1="adebc";
    string s2="dcadba";

    // string s1="abcdaac";
    // string s2="aabdacca";
    // lcs=abdac
    cout<<lcs(s1,s2);
}