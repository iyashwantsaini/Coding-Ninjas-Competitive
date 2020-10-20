/*
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.
 Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1:
4
Sample Output 1:
7
Sample Input 2:
10
Sample Output 2:
274
*/

// nth possible ways can be found by adding (n-1)th,(n-2)th and (n-3)th
// so we can store them and use again and again for all repetitve calls

#include <bits/stdc++.h>
using namespace std;

long get_ans(int n,long *storage){
    if(n==0||n==1||n==2){
        return storage[n];
    }
    if(storage[n]!=0){
        return storage[n];
    }
    long ans=get_ans(n-1,storage)+get_ans(n-2,storage)+get_ans(n-3,storage);
    storage[n]=ans;
    return ans;
}

long staircase(int n)
{
	//Write your code here
    long *storage=new long[10000+1]{};
    storage[0]=1;
    storage[1]=1;
    storage[2]=2;
    long result = get_ans(n,storage);
    delete storage;
    return result;
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
