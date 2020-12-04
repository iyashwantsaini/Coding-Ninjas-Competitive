/*
Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
Input Format :
String S
Output Format :
count of palindrome substrings
Constraints :
1 <= Length of S <= 1000
Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba").
*/

#include <bits/stdc++.h>
using namespace std;

// we'll use longest substring approach here
// we'll add 1 substring for each single element palindrome as well
int countPalindromeSubstrings(char s[]) {
    int len=0;
    for(int i=0;s[i]!='\0';i++){
        len++;
    }
    int l,r;
    int count=0;

    for(int i=0;i<len;i++){
        // for odd length palindromes
        l=i;
        r=i;
        while(l>=0&&r<len&&s[l]==s[r]){
            count++;
            l--;
            r++;
        }
        // for even length palindromes
        l=i;
        r=i+1;
        while(l>=0&&r<len&&s[l]==s[r]){
            count++;
            l--;
            r++;
        }
    }
    return count;
}

int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}
