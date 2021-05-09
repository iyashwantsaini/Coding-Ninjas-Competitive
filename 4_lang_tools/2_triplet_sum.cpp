// You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.
// Note :
// Given array/list can contain duplicate elements.
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First line of each test case or query contains an integer 'N' representing the size of the first array/list.

// Second line contains 'N' single space separated integers representing the elements in the array/list.

// Third line contains an integer 'X'.
// Output format :
// For each test case, print the total number of triplets present in the array/list.

// Output for every test case will be printed in a separate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^3
// 0 <= X <= 10^9

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 1 2 3 4 5 6 7 
// 12
// Sample Output 1:
// 5
// Sample Input 2:
// 2
// 7
// 1 2 3 4 5 6 7 
// 19
// 9
// 2 -5 8 -6 0 5 10 11 -3
// 10
// Sample Output 2:
// 0
// 5


//  Explanation for Input 2:
// Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.

// For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)

#include<bits/stdc++.h>
using namespace std;

int tripletSum(int *arr, int n, int num)
{
    int size=n;
    int x=num;
    sort(arr, arr+size);
    int countpairs=0;
	for (int i = 0; i < size; i++){
		int val = x-arr[i];
		int j = i+1;
		int k = size-1;
		while(j<k ){	
			if (arr[j]+arr[k]>val){
				k--;
			}else if (arr[j]+arr[k]<val){
				j++;
			}else{
				int leftcount = 0;
				int rightcount = 0;
				for (int ptr = j; ptr <= k; ++ptr){
					if (arr[ptr] == arr[j]){
						leftcount++;
					}else
						break;
				}
				for (int ptr = k; ptr >= j; ptr--){
					if (arr[ptr] == arr[k]){
						rightcount++;
					}else
						break;
				}

				int total = leftcount*rightcount;
				if (arr[j]==arr[k]){
					total = ((k-j+1)*(k-j))/2;
				}
				for(int m=0;m<total;m++){
                    cout<<arr[i]<<arr[j]<<arr[k]<<endl;
					countpairs++;
				}
				j+=leftcount;
				k=k-rightcount;
			}
		}
	}
    
    return countpairs;
}