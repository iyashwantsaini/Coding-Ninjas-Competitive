/*
Given an integer array A of size N, find and return the minimum absolute difference between any two elements in the array.
We define the absolute difference between two elements ai, and aj (where i != j ) is |ai - aj|.
Input format :
Line 1 : Integer N, Array Size
Line 2 : Array elements (separated by space)
Output Format :
Minimum difference
Constraints :
1 <= N <= 10^6
Sample Input :
5
2 9 0 4 5
Sample Input :
1
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
    cin>>n;
    int cal[n+1];
    for(int i=0;i<n;i++){
        cin>>cal[i];
    }
    // to avoid big*big condition, we'll multiply largest with smallest and add
    sort(cal,cal+n,greater<int>());
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=cal[i]*pow(2,i);
    }
    cout<<ans;
    return 0;
}