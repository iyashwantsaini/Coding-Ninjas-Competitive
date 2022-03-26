/*
Given an array arr[] of size N, the task is to check if the array is spirally sorted or not. If found to be true, then print “YES”. Otherwise, print “NO”.
Note: An array is spirally sorted if arr[0] ≤ arr[N – 1] ≤ arr[1] ≤ arr[N – 2] …

Examples:
Input: arr[] = { 1, 10, 14, 20, 18, 12, 5 } 
Output: YES 
Explanation: 
arr[0] < arr[6]
arr[1] < arr[5]
arr[2] < arr[4]
Therefore, the required output is YES.

Input: arr[] = { 1, 2, 4, 3 } 
Output: NO
*/

#include<bits/stdc++.h>
using namespace std;

bool ssorted(vector<int> &arr,int n){
    if(n==1) return 1;
    int si=0;
    int ei=n-1;
    int prev=arr[si];
    while(si<ei){
        if(arr[si]>arr[ei] || arr[si] < prev){
            return 0;
        }
        prev=arr[ei];
        si++;
        ei--;
    }
    return 1;
}

int main(){
    vector<int> arr = { 1, 10, 14, 20, 18, 12, 5 };
    // vector<int> arr = { 1, 2, 4, 3 };
    cout<< ssorted(arr,arr.size());
}