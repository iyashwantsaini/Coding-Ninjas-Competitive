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

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// arr - input array
// n - size of array

int minAbsoluteDiff(int arr[], int n) {
    sort(arr,arr+n);
    int mindiff=INT_MAX;
    for(int i=0;i<n-1;i++){
        int diff=arr[i+1]-arr[i];
        if(diff<mindiff){
            mindiff=diff;
        }
    }
    return mindiff;
}


int main() {
	int size;
	cin >> size;
	int *input = new int[1 + size];
	for(int i = 0; i < size; i++)
		cin >> input[i];
	cout<< minAbsoluteDiff(input,size) << endl;
	return 0;
}
