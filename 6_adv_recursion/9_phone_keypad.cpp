// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
// Return empty string for numbers 0 and 1.
// Note : 1. The order of strings are not important.
// 2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
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

int get_ans(int num,string out[],vector<vector<char>> v){
    // index is static to maintain output string array size over all recursions
    static int index=0;
    
    //base case n==0,n==1
    if(num==0||num==1){
        out[index++]="";
        return index;
    }
    
    // except rem all will be sent to next recursive call
    int rem=num%10;
    // get new sizeof output after all the lower recursive calls, output is also filled upto that size
    index = get_ans(num/10,out,v);

    int bakupindex=index;

    // add all rem's key mappings to all elements present in output 
    for(int i=0;i<bakupindex;i++){
        string bakupoi=out[i];
        out[i]=out[i]+v[rem-2][0];
        for(int j=1;j<v[rem-2].size();j++){
            out[index++]=bakupoi+v[rem-2][j];
        }
    }
    // return new size after adding rem's mappings to all
    return index;
}

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    // key mappings
    vector<vector<char>> v;
    v.push_back({'a','b','c'}); //2 key
    v.push_back({'d','e','f'}); //3 key
    v.push_back({'g','h','i'}); //...
    v.push_back({'j','k','l'});
    v.push_back({'m','n','o'});
    v.push_back({'p','q','r','s'});
    v.push_back({'t','u','v'});
    v.push_back({'w','x','y','z'});
    return get_ans(num,output,v);
}

int main(){
    int num;
    cin >> num;
    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}