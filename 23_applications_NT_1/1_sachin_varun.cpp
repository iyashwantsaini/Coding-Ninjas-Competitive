/*
Varun and you are talking about a movie that you have recently watched while Sachin is busy teaching Number Theory. Sadly, Sachin caught Varun talking to you and asked him to answer his question in order to save himself from punishment. The question says:
Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the given weights? Any of the given weights can be used any number of times (including 0 number of times).
Since Varun is not able to answer the question, he asked you to help him otherwise he will get punished.
Note: Two ways are considered different if either the number of times a is used or number of times b is used is different in the two ways.
Input Format:
The first line of input consists of an integer 
T denoting the number of test cases.
Each test case consists of only one line containing three space separated integers a, b and d.
Output Format:
For each test case, print the answer in a separate line.
Constraints:
1 ≤T≤ 10^5
1 ≤ a < b ≤ 10^9
0≤d≤10^9
Sample Input 1
4
2 3 7
4 10 6
6 14 0
2 3 6
Sample Output 1
1
0
1
2
Explanation
Test case 1: 7 can only be achieved by using 2 two times and 3 one time.
Test case 2: 6 can't be achieved by using 4 and 10 .So, 0ways are there.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class triplet{
    public:
        ll x;
        ll y;
        ll gcd_;
};

triplet extended_euclid(int a,int b){
    // base case
    if(b==0){
        triplet baseans;
        baseans.gcd_=a;
        baseans.x=1;
        baseans.y=0;
        return baseans;
    }
    // get x1,y1,gcd_ from children
    triplet small_ans=extended_euclid(b,a%b);
    // calculate our ans from children
    triplet ans;
    ans.gcd_=small_ans.gcd_;
    ans.x=small_ans.y;
    ans.y=small_ans.x-(a/b)*small_ans.y;
    return ans;
}

ll mm_inverse(int a,int m){
    triplet ans=extended_euclid(a,m);
    ll x=ans.x;
    return (x%m+m)%m;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b,d;
        cin>>a>>b>>d;
        ll g=__gcd(a,b);

        // handling special cases
        // if(d%g==0) => soln does not exist
        if(d%g){
            cout<<"0\n";
            continue;
        }
        // if d==0 => a,b both will be 0 
        if(d==0){
            cout<<"1\n";
            continue;
        }

        a/=g;
        b/=g;
        d/=g;

        // find min value of y1 for which the condition holds
        ll y1=((d%a)*mm_inverse(b,a))%a;
        ll first_val=d/b;

        if(d<y1*b){
            cout<<"0\n";
            continue;
        }
        
        ll n=(first_val-y1)/a;
        cout<<n+1<<"\n";
    }
    return 0;
}