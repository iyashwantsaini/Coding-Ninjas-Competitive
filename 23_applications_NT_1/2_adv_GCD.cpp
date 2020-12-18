/*
Varun explained its friend Sanchit the algorithm of Euclides to calculate the GCD of two numbers. Then Sanchit implements the algorithm
int gcd(int a, int b)
{

    if (b==0)
    return a;
    else
    return gcd(b,a%b);
}
and challenges to Varun to calculate gcd of two integers, one is a little integer and other integer has 250 digits.
Your task is to help Varun an efficient code for the challenge of Sanchit.
Input
The first line of the input file contains a number representing the number of lines to follow. Each line consists of two number A and B (0 <= A <= 40000 and A <= B < 10^250).
Output
Print for each pair (A,B) in the input one integer representing the GCD of A and B..
Sample Input:
2
2 6
10 11
Sample Output:
2
1
*/

#include<bits/stdc++.h>
using namespace std;

// O(len(a))
int findmod(string a,int b){
    int mod=0;
    // find for each integer based on previous => so now it'll never get out of range
    for(int i=0;i<a.length();i++){
        int curr_num=int(a[i]-'0');
        mod=(mod*10+curr_num)%b;
    }
    return mod;
}

// O(log(max(a,b)))
int find_gcd(int a,int b){
    // special cases
    if(a<b){
        return find_gcd(b,a);
    }
    // base case
    if(b==0){
        return a;
    }
    // recursive case
    return find_gcd(b,a%b);
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int b;
        string a;
        cin>>b>>a;
        if(b==0){
            cout<<a<<"\n";
            continue;
        }
        // we know gcd(a,b)=gcd(b,a%b)
        // finding a%b => here "a" is a string
        int a_mod_b=findmod(a,b);
        // finding gcd
        cout<<find_gcd(b,a_mod_b)<<"\n";
    }
	return 0;
}