/*
Given a sequence of N (1 ≤ N ≤ 10,000) integers S1, ..., SN (0 ≤ Si < 100,000), compute the number of increasing subsequences of S with length K (1 ≤ K ≤ 50 and K ≤ N); that is, the number of K-tuples i1, ..., iK such that 1 ≤ i1 < ... < iK ≤ N and Si1 < ... < SiK.
Input
The first line contains the two integers N and K. The following N lines contain the integers of the sequence in order.
Output
Print a single integer representing the number of increasing subsequences of S of length K, modulo 5,000,000.
Sample Input
4 3
1
2
2
10
Output:
2
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 5000000

int query(int **BIT,int index,int bitval){
	int count=0;
	for(;index>0;index-=index&(-index)){
		count=(count+BIT[bitval][index])%mod;
	}
	return count;
}

void update(int **BIT,int index,int bitval,int val,int n){
	for(;index<=n;index+=index&(-index)){
		BIT[bitval][index]=(BIT[bitval][index]+val)%mod;
	}
}

// eg 11,43,31,32,51,21 => 1,5,3,4,6,2
void compress_values(int *a,int n){
	int *b=new int[n+1]{};
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	map<int,int> m;
	int k=1;
	for(int i=1;i<=n;i++){
		if(m.find(b[i])==m.end()){
			m[b[i]]=k++;
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=m[a[i]];
	}
}

int main(){
	int n,k;
	cin>>n>>k;
	if(k==1){
		cout<<1<<"\n";
		return 0;
	}
	int *a=new int[n+1]{};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	// as we use previous element for further answers
	// we will sort and assign 1 to n number to the elements
	// this will also reduce time taken
	compress_values(a,n);

	int **BIT=new int*[52];
	for(int i=0;i<=51;i++){
		BIT[i]=new int[300001]{};
	}

	int ans=0;
	// i for indices
	for(int i=1;i<=n;i++){
		// j for length
		for(int j=1;j<=k;j++){
			int x;
			// for length 1
			if(j==1){
				x=1;
			}else{
				// for all other length query
				x=query(BIT,a[i]-1,j-1);
			}
			// now update this current in the tree
			update(BIT,a[i],j,x,n);
			if(j==k){
				// if required length subseq found
				ans=(ans+x)%mod;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}