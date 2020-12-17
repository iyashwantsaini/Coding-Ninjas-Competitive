/*
Given an array of n positive integers. The task is to count the number of Arithmetic Progression subsequences in the array. As the answer could be very large, output it modulo 100001.
Note: Empty sequence or single element sequence is Arithmetic Progression.
Input Format:
First Line: N (the size of the array)
Second Line: Elements of the array separated by spaces.
Output:
Print total number of subsequences
Input Constraints:
1 <= arr[i] <= 1000
1 <= sizeof(arr) <= 1000
Sample Input 1 :
3
1 2 3
Sample output:
8
Sample Output Explanation:
Total subsequence are: {}, { 1 }, { 2 }, { 3 }, { 1, 2 }, { 2, 3 }, { 1, 3 }, { 1, 2, 3 }
Sample Input 2:
7
1 2 3 4 5 9 10
Sample Output:
37
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 100001
typedef long long ll;

int numofAP(int *arr, int N){
    // empty string is also an AP =>1
    // single character is also an AP =>n
    ll ans=N+1;
    // for every index fint all possible different AP's with diffent differences from that index
    unordered_map<int,int> *m=new unordered_map<int,int>[N];
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            int diff=arr[j]-arr[i];
            // at this index with this diff we have 1 more AP
            m[i][diff]+=1;
            // this ++1 will add consideration for 2 lenght AP's also
            ans=(ans+1)%mod;
        }
    } 
    
    // find rest of the AP's =>length 3,4,5 ..
    for(int i=N-3; i>=0; i--){
        for(int j=i+1; j<N; j++){
            int diff=arr[j]-arr[i];
            m[i][diff]=(m[i][diff]%mod+m[j][diff]%mod)%mod;
            ans=(ans%mod+m[j][diff]%mod)%mod;
        }
    }
    delete []m;
    return ans;
}


int main(){
    int N;
    cin >> N;
    int *arr = new int[N+1];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << numofAP(arr, N) << endl;
    return 0;
}
