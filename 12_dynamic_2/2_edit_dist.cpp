/*
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll e_dist_rec(string s1,string s2,ll **storage){
    // base cases
    if(s1.length()==0) return s2.length();
    if(s2.length()==0) return s1.length();

    // if work already done
    if(storage[s1.length()][s2.length()]>=0){
        return storage[s1.length()][s2.length()];
    }

    // if 1st of both same - no change needed | cost =0
    if(s1[0]==s2[0]){
        ll ans=e_dist_rec(s1.substr(1),s2.substr(1),storage);
        storage[s1.length()][s2.length()]=ans;
        return ans;
    }
    
    // if 1st not same
    // possibility 1 - replace s1's first and make it same as s2's first | cost =1
    ll poss1=1+e_dist_rec(s1.substr(1),s2.substr(1),storage);
    // possibility 2 - delete s1's first | cost = 1
    ll poss2=1+e_dist_rec(s1.substr(1),s2,storage);
    // possibility 3 - delete s2's first | cost = 1
    ll poss3=1+e_dist_rec(s1,s2.substr(1),storage);

    ll ans=min(poss1,min(poss2,poss3));
    storage[s1.length()][s2.length()]=ans; 
    return ans;
}

int editDistance(string s1, string s2){
    int n=s1.length();
    int m=s2.length();
    ll **storage=new ll*[n+1];
    for(int i=0;i<=n;i++){
        storage[i]=new ll[m+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            storage[i][j]=-1;
        }
    }
    ll dist=e_dist_rec(s1,s2,storage);
    dist=(int)dist;

    for(int i=0;i<=n;i++){
        delete storage[i];
    }
    delete storage;

    return dist;
}


int main(){
  string s1;
  string s2;
  cin >> s1;
  cin >> s2;
  cout << editDistance(s1,s2) << endl;
}


