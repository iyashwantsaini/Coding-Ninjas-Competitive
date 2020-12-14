/*
Given a sequence A1 , A2 , A3 .. AN of length N . Find total number of wave subsequences having length greater than 1.
Wave subsequence of sequence A1 , A2 , A3 .. AN is defined as a set of integers i1 , i2 .. ik such that Ai1 < Ai2 > Ai3 < Ai4 .... or Ai1 > Ai2 < Ai3 > Ai4 .... and i1 < i2 < ...< ik.Two subsequences i1 , i2 .. ik and j1 , j2 .. jm are considered different if k != m or there exists some index l such that il ! = jl
INPUT
First line of input consists of integer N denoting total length of sequence.Next line consists of N integers A1 , A2 , A3 .. AN .
OUTPUT
Output total number of wave subsequences of given sequence . Since answer can be large, output it modulo 10^9+7
CONSTRAINTS
1 ≤ N ≤ 10^5

1 ≤ Ai ≤ 10^5
SAMPLE INPUT
5
1 3 5 4 2
SAMPLE OUTPUT
17
Explanation
All the possible sequences are: [ 1 3 ] , [1 5 ] , [ 1 4 ] , [1 2 ] , [1 3 2] , [1 4 2 ] , [1 5 2] , [1 5 4] , [3 5] , [3 4] , [3 2] , [3 5 2] , [3 4 2] , [3 5 4] , [5 4] , [5 2 ] , [4 2] . Note that value in the bracket are the values from the original sequence whose positions are maintained.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void update(int index,int **BIT,int type,int val,int n){
	for(;index<=100001;index+=index&(-index)){
		BIT[index][type]=(BIT[index][type]+val)%mod;
	}
}

int query(int index,int **BIT,int type,int n){
	int count=0;
	for(;index>0;index-=index&(-index)){
		count=(count+BIT[index][type])%mod;
	}
	return count;
}

int main(){
	int n;
	cin>>n;
	int *a=new int[n+1]{};
	int maxtill=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxtill=max(maxtill,a[i]);
	}
	// 3 binary index trees
	// 0 => for all subseq j<i || a[j]<a[i]
	// 1 => for all subseq j<i || a[j]>a[i] 
	// 2 => for how many a[j]'s are smaller than a[i]

	// creating 3 BIT's
	int **BIT=new int*[100001];
	for(int i=0;i<=100000;i++){
		BIT[i]=new int[3]{};
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		int el=a[i];

		// for values less than a[i]
		// 0=> find sigma(a[j]<a[i]) part by finding for a[i]-1
		//  2=> for sigma(1) part
        int a=(query(el-1,BIT,0,n)+query(el-1,BIT,2,n))%mod;

		// now for values grater than a[i]
		int b=(query(maxtill,BIT,1,n)-query(el,BIT,1,n)+query(maxtill,BIT,2,n)-query(el,BIT,2,n))%mod;

		// updating calculated values in all BIT's
		update(el,BIT,0,b,n);
		update(el,BIT,1,a,n);
		update(el,BIT,2,1,n);

        // saving to total ans
        // ans=a+b;
		a=(a+mod)%mod;
        b=(b+mod)%mod;
		ans=(ans+a)%mod;
        ans=(ans+b)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}