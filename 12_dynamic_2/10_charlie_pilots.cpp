/*
Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.
Input
The first line of input contains integer N, 2 ≤ N ≤ 10,000, N is even, the number of pilots working for the Charlie's company. The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated by a space character, X i Y, 1 ≤ Y < X ≤ 100,000, a salary as a captain (X) and a salary as an assistant (Y).
Output
The first and only line of output should contain the minimal amount of money Charlie needs to give for the pilots' salaries. 
Sample Input
4 
5000 3000 
6000 2000 
8000 1000 
9000 6000 
Sample Output
19000 
*/

#include <bits/stdc++.h>
using namespace std;

// here x==noofassistants-noofcaptains
int find_min(int n,int *a,int *c,int x,int**dp){
    if(n==0){
        return 0;
    }
    
    //work already done
    if(dp[n][x]!=-1){
        return dp[n][x];
    }
    
    int ans;
    //if no captain of current index, then he must be assistant
    if(x==0){
        ans=a[0]+find_min(n-1,a+1,c+1,1,dp);
    }
    //if x== remaining unassigned places
    //then it means all next must become captains
    else if(x==n){
        ans=c[0]+find_min(n-1,a+1,c+1,x-1,dp);
    }
    else{
        //i have 2 options now
        int opt1=a[0]+find_min(n-1,a+1,c+1,x+1,dp);
        int opt2=c[0]+find_min(n-1,a+1,c+1,x-1,dp);
        ans=min(opt1,opt2);
    }
    dp[n][x]=ans;
    return ans;
}

int main()
{
    //number of captains
    int n;
    cin>>n;
    //assistant's salary
    int *a=new int[n+1];
    //captain's salary
    int *c=new int[n+1];
    
    for(int i=0;i<n;i++){
        //sal as a captain
        cin>>c[i];
        //sal as a assist
        cin>>a[i];
    }
    
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    // currently noofassistants-noofcaptains=0
    cout<<find_min(n,a,c,0,dp)<<endl;
    return 0;
}
