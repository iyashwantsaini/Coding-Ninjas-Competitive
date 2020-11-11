/*
Harshit knows by his resources that this time the winning lottery number is the smallest number whose sum of the digits is S and the number of digits is D. You have to help Harshit and print the winning lottery number.
Input Format
The Input line contains two space-separated integers: S,D
Output Format
The output contains a single integer denoting the winning lottery number
Constraints
1 <= D <= 1000
1 <= S <= 9*D
Time Limit: 1 second
Sample Input1:
9 2
Sample Output1:
18
Explanation
There are many other possible numbers like 45, 54, 90, etc with the sum of digits as 9 and number of digits as 2. The smallest of them is 18.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll s,d;
    cin>>s>>d;

    int *digits=new int[d]{};

    // as smallest number must be taken
    // we'll try to give all 9's or remaining to end, 1 in front, 0 in between and remaining just before 9's

    // divide number 's' by 9' it'll show how many 9's must be put at end
    // if its 0 allocate 1 to front, start allocating 0 from front+1 and add remaining to end
    // else give required 9's to end, then allocate 1 at start, start allocating 0 from start+1 and remaining till first 9 reached

    int num9s=s/9;
    if(num9s==0){
        // add 1 at front
        digits[0]=1;
        s-=1;
        
        // start allocating 0 from front, not req as already all are 0
        // for(int i=1;i<d-1;i++){
        //     digits[i]=0;
        // }

        // add remaining to last
        digits[d-1]=s;
    }
    else{
        // allocate 9's from last
        for(int i=0;i<num9s;i++){
            digits[d-1-i]=9;
            s-=9;
        }

        // then allocate 1 to first, only if required
        if(num9s!=d){
        	digits[0]=1;
        	s-=1;
        }

        // allocate 0's in between, not req as already all are 0
        
        // allocate remaining to the last just before 9's
        digits[d-num9s-1]=s;
    }
    
    for(int i=0;i<d;i++){
        cout<<digits[i];
    }

    delete digits;
    return 0;
}