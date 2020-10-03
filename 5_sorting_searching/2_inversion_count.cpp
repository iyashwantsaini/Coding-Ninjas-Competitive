// For a given integer array/list of size N, find the total number of 'Inversions' that may exist.
// An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
// A pair (arr[i], arr[j]) is said to be an inversion when,
// 1. arr[i] > arr[j] 
// 2. i < j

// Where 'arr' is the input array/list, 'i' and 'j' denote the indices ranging from [0, N).
// Input format :
// The first line of input contains an integer N, denoting the size of the array.

// The second line of input contains N integers separated by a single space, denoting the elements of the array.
// Output format :
// The only line of output prints the total count of inversions in the array.
// Note:
// You are not required to print anything. Return the total number of inversion count.
// Constraints :
// 1 <= N <= 10^5 
// 1 <= arr[i] <= 10^9

// Time Limit: 1sec
// Sample Input 1 :
// 3
// 3 2 1
// Sample Output 1 :
// 3
// Explanation of Sample Input 1:
// We have a total of three pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
// Sample Input 2 :
// 5
// 2 5 1 3 4
// Sample Output 2 :
// 4

#include<bits/stdc++.h>
using namespace std;

long long merge(long long a[],int start,int mid,int end){
    int temp[end-start+1];
    int k=0;
    long long count=0;
    int i=start,j=mid;
    for(;i<mid&&j<=end;){
        if(a[i]<=a[j]){
            // here no inversions will be there as a[i]<a[j]
            temp[k++]=a[i++];
        }else{
            // here inversions will be there
            // for each j inversions in i will be length - current index
            temp[k++]=a[j++];
            count+=mid-i;
        }
    }
        while(i<mid){
            temp[k++]=a[i++];
        }
        while(j<=end){
            temp[k++]=a[j++];
        }
    // copy sorted temp back to unsorted array 
    for(int i=start,j=0;i<=end;i++,j++){
        a[i]=temp[j];
    }
    return count;
}

long long merge_sort(long long a[],int start,int end){
    // here end is the last value (n-1)th, means this must be included
    long long count=0;
    if(start<end){
        int mid=(start+end)/2;
        long long leftinv=merge_sort(a,start,mid);
        long long rightinv=merge_sort(a,mid+1,end);
        long long mergeinv=merge(a,start,mid+1,end);
        return leftinv+rightinv+mergeinv;
    }
    return count;
}

long long getInversions(long long *arr, int n){
    // finding inversions using merge _sort
    // divide array in 2 halves - sort and find inversions in both arrays
    // merge 2 arrays and find inversions while merging
    // calculate total inversions
    long long ans=merge_sort(arr,0,n-1);
    return ans; 
}

int main(){
    int n;
    cin >> n;
    long long* arr = new long long[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cout << getInversions(arr, n);
    delete arr;
}