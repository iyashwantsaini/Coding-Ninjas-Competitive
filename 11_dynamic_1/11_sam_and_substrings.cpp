// https://www.hackerrank.com/challenges/sam-and-substrings/problem

/*
INPUT
123
OUTPUT
164
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the substrings function below.
int substrings(string n) {
    int m=1000000007;
    long long sum=0,last=0;
    sum=n[0]-'0';
    last=n[0]-'0';
    if(n.length()==1){
        return sum;
    }
    for(int i=1;i<n.length();i++){
        last=(last*10+(n[i]-'0')*(i+1))%m;
        sum=(sum+last)%m;
    }
    return sum;
}

int main()
{
    string n;
    getline(cin, n);
    int result = substrings(n);
    cout << result << "\n";
    return 0;
}
