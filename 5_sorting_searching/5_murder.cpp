// Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
// Answer may not fit in integer . You have to take long.
// Input
// First line gives T, number of test cases.

// 2T lines follow.

// First line gives you the number of stairs N

// Next line gives you N numbers written on the stairs.
// Output
// For each test case output one line giving the final sum for each test case.
// Constraints
// T<=10

// 1<=N<=10^5

// All numbers will be between 0 and 10^6.
// Sample Input:
// 1
// 5
// 1 5 3 6 4
// Sample Output:
// 15
// Explanation:
// For the first number, the contribution to the sum is 0.
// For the second number, the contribution to the sum is 1.
// For the third number, the contribution to the sum is 1.
// For the fourth number, the contribution to the sum is 9 (1+5+3).
// For the fifth number, the contribution to the sum is 4 (1+3).
// Hence the sum is 15 (0+1+1+9+4).

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll merge(ll s[],ll start, ll mid, ll end){
    ll sum=0;
    ll temp[end-start+1];
    ll k=0;
    // merging by comparing
    ll i=start,j=mid;
    while(i<mid&&j<=end){
        if(s[i]<s[j]){
            sum+=(s[i]*(end-j+1));
            temp[k++]=s[i++];
        }else{
            temp[k++]=s[j++];
        }
    }
    // copy left remaining
    while(i<mid){
        temp[k++]=s[i++];
    }
    // copy right remaining
    while(j<=end){
        temp[k++]=s[j++];
    }
    // copt temp back to s
    for(ll x=0,y=start;y<=end;x++,y++){
        s[y]=temp[x];
    }
    return sum; 
}

ll merge_sort(ll s[],ll start,ll end){
    ll sum=0;
    if(start<end){
        ll mid=(start+end)/2;
        ll ansleft=merge_sort(s,start,mid);
        ll ansright=merge_sort(s,mid+1,end);
        ll ansmerge=merge(s,start,mid+1,end);
        return ansleft+ansright+ansmerge;
    }
    return sum;
}

int main() {
	int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll s[n];
        for(int i=0;i<n;i++){
			cin>>s[i];
        }
        ll ans=merge_sort(s,0,n-1);
        cout<<ans<<endl;
    }
}