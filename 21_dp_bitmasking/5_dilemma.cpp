/*
Abhishek, a blind man recently bought N binary strings all of equal length .A binary string only contains '0's and '1's . The strings are numbered from 1 to N and all are distinct, but Abhishek can only differentiate between these strings by touching them. In one touch Abhishek can identify one character at a position of a string from the set. Find the minimum number of touches T Abhishek has to make so that he learn that all strings are different .
Constraints :
2<=N<=10
1<=|L|<=100 , L is length of the strings .
Input Format:
Line 1 : An Integer N, denoting the number of binary strings .
Next N lines : strings of equal length
Output Format:
Return the minimum number of touches
Sample Input :
2
111010
100100
Sample Output :
2
*/

#include<bits/stdc++.h>
using namespace std;

int mintouch(int n,vector<string> v,int mask,int **dp,int curr_char){
    // base cases 
    // 1=> only 1 bit is set in mask
    if(!(mask&(mask-1))){
        // no touches required as 1 string remaining
        return 0;
    }
    // 2=> limit crossed
    if(curr_char<0){
        // for int_max
        return 10000;
    }

    if(dp[curr_char][mask]!=INT_MAX){
        return dp[curr_char][mask];
    }

    int touches=0;
    int newmask1=0; // for handling 1's
    int newmask2=0; // for handling 0's

    // go to mask and check for 1 bits to set
    for(int i=0;i<v.size();i++){
        // if string can be used i.e if its one
        if(mask&(1<<i)){
            touches++;
            if(v[i][curr_char]=='1'){
                newmask2|=(1<<i);
            }else{
                newmask1|=(1<<i);
            }
        }
    }
    int ans1=mintouch(n,v,newmask1,dp,curr_char-1)+mintouch(n,v,newmask2,dp,curr_char-1)+touches;
    int ans2=mintouch(n,v,mask,dp,curr_char-1);
    int ans=min(ans1,ans2);

    dp[curr_char][mask]=ans;
    return ans;
}

int minimumTouchesRequired(int n, vector<string> v) {
    // start with mask 1111...utpo n
    int **dp=new int*[v[0].size()];
    for(int i=0;i<v[0].size();i++){
        dp[i]=new int[1<<(n+1)];
        for(int j=0;j<(1<<(n+1));j++){
            dp[i][j]=INT_MAX;
        }
    }
    int ans=mintouch(n,v,(1<<n)-1,dp,v[0].size()-1);
    return ans;
}

int main() {
    int n;
    vector<string> v;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string a;
		cin >> a;
		v.push_back(a);
	}
	cout << minimumTouchesRequired(n, v) << endl;
}