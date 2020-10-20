/*
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. 
For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.
We have to find the length of the LIS. In this case it's 6.

INPUT
9
10 22 9 33 21 50 41 60 80
OUTPUT
6

*/

// approach - find LIS length at each index and use it to find for next

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int lis(int n,int a[],int storage[]){
    storage[0]=1;
    for(int i=1;i<n;i++){
        storage[i]=1;
        for(int j=i-1;j>=0;j--){
            if(a[j]<a[i]){
                if((storage[j]+1)>storage[i]){
                    storage[i]=storage[j]+1;
                }
            }
        }
    }
    int maxnum=INT_MIN;
    for(int i=0;i<n;i++){
        if(storage[i]>maxnum){
            maxnum=storage[i];
        }
    }
    return maxnum;
}

int main(){
    int n;
    cin>>n;
    int *a=new int[n]{};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int *storage=new int[n]{};
    cout<<lis(n,a,storage)<<endl;
    delete a;
    delete storage;
}