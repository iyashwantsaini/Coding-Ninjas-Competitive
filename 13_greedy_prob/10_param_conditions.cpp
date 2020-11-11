/*
Aahad gives an array of integers and asks Harshit to find which three elements form a triangle (non-degenerate). The task seems easy to Harshit.
So, Aahad adds some conditions to this task -
1. Find the triangle with maximum perimeter
2. If there are two or more combinations with same value of maximum perimeter, then find the one with the longest side.
3.If there are more than one combinations which satisfy all the above conditions the find with maximum longest minimum side.
Input Format
The First line contains no of elements of array: N
Each T lines contains N space-separated integers: A [i]
Output Format
The output contains three space-separated elements that denote the length of the sides of triangle. If no such triangle is possible, then print -1.
Constraints
1 =< N <= 10^5 
1 <= A[i] <= 10^9
Time Limit: 1 second
Sample Input1:
5
1 1 1 3 3
Sample Output1:
1 3 3 
Sample Input2:
3
2 2 4
Sample Output3:
-1 
Explaination
In the First Sample case, the elements that form a triangle with maximum perimeter is 1,3,3.
In the Second Sample case, the elements that can form a triangle are degenerate, so, we printed -1.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll *sides=new ll[n];
    for(int i=0;i<n;i++){
        cin>>sides[i];
    }
    // as we need greatest perimeter, we'll sort in descending order
    sort(sides,sides+n,greater<ll>());
    ll ans=0;
    ll a,b,c;

    for(int i=0;i<n-2;i++){
        a=sides[i];
        b=sides[i+1];
        c=sides[i+2];
        // check for non degeneracy
        // the first non degenerate soln can be our answer as we need the largest parimeter 
        if(
            ((a+b)>c)
            &&
            ((a+c)>b)
            &&
            ((b+c)>a)
        ){
            // all conditions passed , means its the best possible solution
            ans=1;
            break;
        }
    }
    if(ans==1){
        cout<<c<<" "<<b<<" "<<a<<endl;
    }else{
        cout<<-1<<endl;
    }
}