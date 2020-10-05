// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
// Note : The order of strings are not important. Just print different strings in new lines.
// Input Format :
// Integer n
// Output Format :
// All possible strings in different lines
// Constraints :
// 1 <= n <= 10^6
// Sample Input:
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf

#include <bits/stdc++.h>
using namespace std;

void print_combinations(int num,string out,vector<vector<char>> keys){
    // base case
    if(num==0||num==1){
        cout<<out<<endl;
        return;
    }
    //get last number in num
    int rem=num%10;
    //print all combinations by using all chars from rem's key mappings
    for(int i=0;i<keys[rem-2].size();i++){
        print_combinations(num/10,keys[rem-2][i]+out,keys);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    vector<vector<char>> keys;
    keys.push_back({'a','b','c'}); //2nd key
    keys.push_back({'d','e','f'}); //3rd key
    keys.push_back({'g','h','i'}); //4th key
    keys.push_back({'j','k','l'}); //5th key
    keys.push_back({'m','n','o'}); //6th key
    keys.push_back({'p','q','r','s'}); //7th key
    keys.push_back({'t','u','v'}); //8th key
    keys.push_back({'w','x','y','z'}); //9th key
	string out;
    print_combinations(num,out,keys);
}
