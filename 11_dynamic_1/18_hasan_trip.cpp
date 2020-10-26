/*
Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
Input format:
First line contain integer N.
Next N lines contains three integers each, i-th line contains coordinates of i-th city Xi, Yi and Fi.
Output format:
Output one number rounded to 6 digits after floating point, the maximum possible happiness Hasan can get. Note: If answer is 2 print 2.000000
Constraints:
1 <= N <= 3,000
0 <= Xi, Yi, Fi <= 100,000
Sample Input
3
0 0 1
3 1 1
6 0 9
Sample Output
4.675445
*/

#include <bits/stdc++.h>
using namespace std;
typedef double d;

d dist_find(int x1,int x2,int y1,int y2){
    d xdiff=x1-x2;
    d ydiff=y1-y2;
    d ans=sqrt(xdiff*xdiff+ydiff*ydiff);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int **cord=new int*[n];
    for(int i=0;i<n;i++){
        cord[i]=new int[3];
    }
    for(int i=0;i<n;i++){
        cin>>cord[i][0]>>cord[i][1]>>cord[i][2];
    }
    
    // dp array to store happiness
    d *dp=new d[n]{};
    // at first city there will only be happiness
    dp[0]=cord[0][2];

    for(int i=1;i<n;i++){
        dp[i]=INT_MIN;
        for(int j=i-1;j>=0;j--){
            d dist=dist_find(cord[i][0],cord[j][0],cord[i][1],cord[j][1]);
            dp[i]=max(dp[i],dp[j]-dist);
        }
        dp[i]+=cord[i][2];
    }

    d ans= dp[n-1];

    for(int i=0;i<n;i++){
        delete cord[i];
    }
    delete cord;

    cout<<fixed<<setprecision(6)<<ans;
    return 0;
}

