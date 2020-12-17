/*
Given a string 's' consisting of upper case alphabets, i.e. from 'A' to 'Z'. Your task is to find how many strings 't' with length equal to that of 's', also consisting of upper case alphabets are there satisfying the following conditions:
-> String 't' is lexicographical larger than string 's'.
-> When you write both 's' and 't' in the reverse order, 't' is still lexicographical larger than 's'.
Find out number of such strings 't'. As the answer could be very large, take modulo 10^9 + 7.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int countStrings(char* s){
   
}

int main(){
	char s[100005];
    cin>>s;
    int ans = countStrings(s);
    cout<<ans<<endl;
}