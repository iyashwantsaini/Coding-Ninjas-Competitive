
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll all_subseq(string s){
    int len=s.length();
    // to store no of subseq upto each index
    ll *dp=new ll[len+1];
    // to store previous occurance index of characters
    // map is showing TLE
    // map<char,int> m;
    ll *previndice=new ll[26];
    for(int i=0;i<26;i++){
        previndice[i]=-1;
    }
    // empty string 1 possibility
    dp[0]=1;
    for(ll i=1;i<=len;i++){
        dp[i]=(dp[i-1]*2)%mod;
        // if(m[s[i-1]]!=0){
        if(previndice[s[i-1]-65]!=-1){
            //as it may go negative, +m %m will give us the required answer
            // dp[i]=(dp[i]-dp[m[s[i-1]]-1]+mod)%mod;
            dp[i]=(dp[i]-dp[previndice[s[i-1]-65]-1]+mod)%mod;
        }
        // m[s[i-1]]=i;
    	previndice[s[i-1]-65]=i;
    }
    ll ans=dp[len]%mod;
    delete dp;
	delete previndice;
    return ans;
}

// recursive approach TLE
// void all_subseq(string input,string output,map<string,int> &m){
//     if(input==""){
//         if(output==""){
//             m[" "]=1;
//         }else{
//             m[output]=1;
//         }
//         return;
//     }
//     // for each char in string we have 2 options
//     // include
//     all_subseq(input.substr(1),output+input[0],m);
//     // not include
//     all_subseq(input.substr(1),output,m);
// }

// TLE coming in some cases
// ll all_subseq(string s){
    
//     map<string,int> m;
//     map<string,int>::iterator it;
    
//     // go from end to start ans find all subseq starting at current index
//     for(int i=s.length()-1;i>=0;i--){
    	
//         map<string,int> m_curr;
//         map<string,int>::iterator it_curr;
        
//         // generate new subsequences from previous, by adding just current char in front of all previous
//         for(it=m.begin();it!=m.end();it++){
//        		string curr_s=s[i]+it->first;
//             m_curr[curr_s]++;
//         }
        
//         // single current char is also a subseq
//         string single(1,s[i]);
//         m[single]++;
        
//         // add all newly generated subseq to the map
//         for(it=m_curr.begin();it!=m_curr.end();it++){
//             m[it->first]=1;
//         }
        
//     }

//     // empty is also a subseq
//     m[" "]++;
    
//     return m.size()%mod;
// }

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        map<string,int> m;
        cout<<all_subseq(s)<<endl;
        // cout<<all_subseq(s)<<endl;
        // string out;
        // all_subseq(s,out,m);
        // cout<<m.size()<<endl;
    }
    return 0;
}
