/*
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
Output format :
Print the the maximum money that can be looted.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
*/

#include <bits/stdc++.h>
using namespace std;
#define m 1000000007

int get_ans_rec(int *arr,int n,int i,int *storage){
    if(i>=n){
        return 0;
    }
    if(storage[i]!=-1){
        return storage[i];
    }
    int possible_ans1=(arr[i]+get_ans_rec(arr,n,i+2,storage))%m;
    int possible_ans2=get_ans_rec(arr,n,i+1,storage)%m;
    int ans=max(possible_ans1,possible_ans2);
    storage[i]=ans;
    return ans;
}

int get_ans_iter(int *arr,int n,int i, int *storage){
    storage[0]=arr[0];
    storage[1]=max(arr[0],arr[1]);

    int max_sum=0;
    for(int i=2;i<n;i++){
        int ans=max(arr[i]+storage[i-2],storage[i-1]);
        storage[i]=ans;
        max_sum=ans;
    }
    return max_sum;
}

int maxMoneyLooted(int *arr, int n)
{
    // base cases
    if(n==0) return 0;
    if(n==1) return arr[0];

    int *storage=new int[n];
    for(int i=0;i<n;i++){
        storage[i]=-1;
    }

    // recursive approach
    // return get_ans_rec(arr,n,0,storage);

    // iterative approach
    int ans= get_ans_iter(arr,n,0,storage);
    
    delete storage;
    return ans;
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}

// this approach is not complete as of now
/*
int maxMoneyLooted(int *arr, int n)
{
    int m=1000000007;
    // base cases
    if(n==0) return 0;
    if(n==1) return arr[0];

    // included ~ 1, not included ~ 0
    int *included=new int[n]{};
    included[0]=1;

    long long overall_sum=included[0];

    for(int i=1;i<n;i++){
        long long new_possible_sum=0;
        
        if(arr[i-1]==0){
            // previous was not included
            overall_sum=(overall_sum + arr[i])%m;
            included[i]=1;
        }else{
            // previous was included
            // exclude prev , include current , take max
            new_possible_sum=(overall_sum-arr[i-1]+arr[i])%m;
            if(new_possible_sum>overall_sum){
                included[i]=1;
                included[i-1]=0;
                overall_sum=new_possible_sum;
            }
        }

        overall_sum=overall_sum%m;
        new_possible_sum=new_possible_sum%m;
    }
    delete included;
    return overall_sum;
}
*/