/*
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.

Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. 
Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a

Output
For each query output the result in a new line.
Constraints
1 ≤ N ≤ 1000000
1 ≤ M ≤ 1000000
1 ≤ L ≤ R ≤ N
1 ≤ Q ≤ 1000000
1 ≤ X ≤ N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*/

#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int n,m,qnum;
    cin>>n>>m;
    // int rng[m][2];

    // holds number of times range started from a particular index
    int startcount[n+1]{};
    // holds number of times range ended on a particular index
    int endcount[n+1]{};
	int a,b;
    for(int i=0;i<m;i++){
        // cin>>rng[i][0]>>rng[i][1];
        cin>>a>>b;
        startcount[a]++;
        endcount[b]++;
        // startcount[rng[i][0]]++;
        // endcount[rng[i][1]]++;
    }

    int freq[n+1]{};
    // my method to find freq worst case complexity - O(n^2)
    // for(int i=0;i<m;i++){
    //     for(int j=rng[i][1];j>=rng[i][0];j--){
    //         freq[j]++;
    //     }
    // }

    // O(n) method
    // freq[1]=startcount[1];
    for(int i=1;i<=n;i++){
        freq[i]=startcount[i]-endcount[i-1]+freq[i-1];
    }

    // for(int i=1;i<=n;i++){
    //     cout<<freq[i]<<" ";
    // }cout<<"\n";

    // saving the number of each coin counts
    // i.e each index will have the number of boxes having that coin frequency
	// will store ki i coin kitne boxes me h
    int freqcount[n+1]{};
    for(int i=1;i<=n;i++){
        freqcount[freq[i]]++;
    }
    
    for(int i=n-1;i>=0;i--){
        freqcount[i]+=freqcount[i+1];
    }
    
    // now we have the number of times a particular coin frequency occurs
    // saving the answers using previous freqcount array
    // int ans[n+1];
    // ans[n]=freqcount[n];
    // for(int i=n-1;i>=1;i--){
    //     ans[i]=freqcount[i]+ans[i+1];
    // }

    cin>>qnum;
    while(qnum--){
        int q;
        cin>>q;
        cout<<freqcount[q]<<endl;

        // my method complexit is more
        // int count=0;
        // for(int i=1;i<=n;i++){
        //     if(freq[i]>=q){
        //         count++;
        //     }
        // }
        // cout<<count<<endl;
    }
    return 0;
}
