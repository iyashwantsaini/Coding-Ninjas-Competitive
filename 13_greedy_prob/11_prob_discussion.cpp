/*
Harshit gave Aahad an array of size N and asked to minimize the difference between the maximum value and minimum value by modifying the array under the condition that each array element either increase or decrease by k(only once).
It seems difficult for Aahad so he asked for your help
Input Format
The First line contains two space-separated integers: N,K
Next lines contain N space-separated integers denoting elements of the array
Output Format
The output contains a single integer denoting the minimum difference between maximum value and the minimum value in the array
Constraints
1 =< N <= 10^5 
1 <= Ai,K <= 10^9
Sample Input1:
3 6
1 15 10
Sample Output1:
5
Explaination
We change from 1 to 7, 15 to  9 and 10 to 4. Maximum difference is 5 (between 4 and 9). We can't get a lower difference.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,k;
    cin>>n>>k;
    int *el=new int[n];
    for(int i=0;i<n;i++){
        cin>>el[i];
    }
    // as we have to find min diff between the biggest and smallest values in the arrray
    // we'll sort the array , add k to smallest and remove k from largest
    // the diff will be the ans
    sort(el,el+n);
    cout<<(el[n-1]-k)-(el[0]+k)<<endl;
    delete el;
    return 0;
}