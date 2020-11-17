/*
The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
Input:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.
Output:
For each query of Type 0 print the value modulo 3.
Constraints:
1<= N <=10^5

1<= Q <= 10^5

0 <= l <= r < N
Sample Input
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3
Sample Output
2
1
2
1
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void build(int *tree,int *arr,int s,int e,int i,int *pow2mod3){
    // base case 
    if(s==e){
        tree[i]=arr[s];
        return;
    }
    // build children
    int mid=(s+e)/2;
    build(tree,arr,s,mid,i*2,pow2mod3);
    build(tree,arr,mid+1,e,i*2+1,pow2mod3);
    tree[i]=(tree[i*2+1]+tree[i*2]*pow2mod3[e-mid])%3;
    // fill current
}

void view_tree(int n,int *tree){
    for(int i=1;i<4*n;i++){
        cout<<tree[i]<<" ";
    }
    cout<<"\n";
}

// getter query
int query_zero(int *tree,int s,int e,int i,int l,int r,int *pow2mod3){
    // 3 cases
    // completely outside
    if(l>e||r<s){
        return 0;
    }
    // completely inside
    if(s>=l&&e<=r){
        return (tree[i]*pow2mod3[r-e])%3;
    }
    // partially in, partially out
    int mid=(s+e)/2;
    int left=query_zero(tree,s,mid,i*2,l,r,pow2mod3);
    int right=query_zero(tree,mid+1,e,i*2+1,l,r,pow2mod3);
    return (right+left)%3;
}

// updation query
void query_one(int *tree,int *arr,int s,int e,int i,int *pow2mod3,int index){
    // base
    if(s==e){
        arr[s]=1;
        tree[i]=1;
        return;
    }
    int mid=(s+e)/2;
    if(index>mid){
        query_one(tree,arr,mid+1,e,i*2+1,pow2mod3,index);
    }else{
        query_one(tree,arr,s,mid,i*2,pow2mod3,index);
    }
    tree[i]=(tree[i*2+1]+tree[i*2]*pow2mod3[e-mid])%3;
}

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
	int* arr = new int[n];
	for (int i = 0; i < n; i++){
		arr[i] = s[i]-'0';
	}
    int *tree=new int[4*n];
    int *pow2mod3=new int[100002];
    pow2mod3[0]=1;
    for(int i=1;i<=100001;i++){
        pow2mod3[i]=(pow2mod3[i-1]*2)%3;
    }
    build(tree,arr,0,n-1,1,pow2mod3);
    // view_tree(n,tree);

    int q;
    cin>>q;
    while(q--){
        int qtype;
        cin>>qtype;
        if(qtype==0){
            int l,r;
            cin>>l>>r;
            int ans=query_zero(tree,0,n-1,1,l,r,pow2mod3);
            cout<<ans<<endl;
        }else{
            int index;
            cin>>index;
            query_one(tree,arr,0,n-1,1,pow2mod3,index);
        }
    }
    return 0;
}
