/*
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250
*/

#include<bits/stdc++.h>
using namespace std;

bool compare(int j1[],int j2[]){
    return j1[1]<j2[1];
}

// binary search to find index
int find_prev(int n,int **in,int s,int e,int limit){
    // base cases
    if(s>e){
        return -1;
    }
    if(s==e){
        if(in[s][1]<=limit){
            return s;
        }else{
            return -1;
        }
    }
    int mid=(s+e)/2;
    // found or less
    if(in[mid][1]<=limit){
        int index=find_prev(n,in,mid+1,e,limit);
        if(index==-1){
            return mid;
        }
        return index;
    }
    // big
    return find_prev(n,in,s,mid-1,limit);
}

int max_profit(int n,int **in){
    // first sort on basis of finishing time
    sort(in,in+n,compare);
    // for(int i=0;i<n;i++){
    //     cout<<in[i][0]<<" "<<in[i][1]<<" "<<in[i][2]<<endl;
    // }

    // create array for storing the max profit at each index
    int dp[n];

    // for every index find max value at that index
    // use previously found values to calc current val
    
    // for 0th index max profit will be value at 0th itself
    dp[0]=in[0][2];
    for(int i=1;i<n;i++){
        // currrent items value may be the max
        int possibleans1=dp[i-1];
        // find max possible before current
        // int possibleans2=0;
        int possibleans2=in[i][2];

        // finding latest previous posn of greater profit
        // using simple method - O(n)
        // for(int j=i-1;j>=0;j--){
        //     // if the times for jobs are not clashing, then find possible ans
        //     if(in[j][1]<=in[i][0]){
        //         // if its profit is greater than current max
        //         if(dp[j]>possibleans2){
        //             possibleans2=dp[j];
        //             break;
        //         }
        //     }
        // }
        
        // 0 = start, end = i-1, starting = in[i][0]
        int poss_index=0;
        poss_index=find_prev(n,in,0,i-1,in[i][0]);
        // using binary search

        // prev possible element not found
        if(poss_index!=-1){
            possibleans2+=dp[poss_index];
        }

        dp[i]=max(possibleans1,possibleans2);

        // dp[i]=max(possibleans1,possibleans2+in[i][2]);
    }
    return dp[n-1];
}

int main()
{
	int n;
    cin>>n;
    int **in=new int*[n];
    for(int i=0;i<n;i++){
        in[i]=new int[3];
    }
    for(int i=0;i<n;i++){
        cin>>in[i][0]>>in[i][1]>>in[i][2];
    }
    cout<<max_profit(n,in)<<endl;
    return 0;
}