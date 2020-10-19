/*
Number Of Balanced BTs
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int balancedBTs(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.
  */
    if(h==0||h==1){
        return 1;
    }
    
    // int m=pow(10,9)+7;
    int m=1000000007;
    int x=balancedBTs(h-1);
    int y=balancedBTs(h-2);

    // x*x can't be stored in integer , so we'll first store in long than convert that to int

    ll x_square=(ll)x*x; //typecasting
    ll two_x_y=(ll)x*y*2; //typecasting

    int ans1=(int)(x_square%m);
    int ans2=(int)(two_x_y%m);

    int final_ans=(ans1+ans2)%m;

    return final_ans;

    // the below return may be wrong in some cases as it may exceed integer range
    // return balancedBTs(h-1)*balancedBTs(h-1)+2*balancedBTs(h-1)*balancedBTs(h-2);
}

int main(){
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}