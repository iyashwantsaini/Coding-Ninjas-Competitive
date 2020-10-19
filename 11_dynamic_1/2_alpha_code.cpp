/*
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
Input
Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.
Output
For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"
Sample Input:
25114
1111111111
3333333333
0
Sample Output:
6
89
1
*/

// bug_in_zero_consideration

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// simple fn - exponential complexity
// ll alpha_code(int n[],ll size){
//     // base case
//     if(size==0||size==1){
//         return 1;
//     }
//     // rec case
//     ll ans=alpha_code(n,size-1);
//     if((n[size-2]*10+n[size-1])<=26){
//         ans+=alpha_code(n,size-2);
//     }
//     return ans;
// }

// recursive fn with storage
// ll alpha_code(int *n,ll size,int *storage){
//     // base case
//     if(size==0||size==1){
//         return 1;
//     }
//     if(storage[size]>0){
//         return storage[size];
//     }
//     // rec case
//     ll output=alpha_code(n,size-1,storage);
//     if((n[size-2]*10+n[size-1])<=26){
//         output+=alpha_code(n,size-2,storage);
//     }
//     storage[size]=output;
//     return output;
// }


// iterative fn with storage
ll alpha_code_iter(int n[],ll size){
    int *storage=new int[size+1]{};
    storage[0]=1;
    storage[1]=1;
    
    for(int i=2;i<=size;i++){
        storage[i]=storage[i-1];
        if((storage[i-2]*10+storage[i-1])<=26){
            storage[i]+=storage[i-2];
        }
    }
    
    ll ans=storage[size];
    delete storage;
    return ans;
}

int main()
{
    while(1){
        ll n;
        cin>>n;
        if(n==0){
            return 0;
        }
        ll size=0;
        ll num=n;
        while(num>0){
            num/=10;
            size++;
        }
        int *num_arr=new int[size+1]{};
        for(int i=size-1;i>=0;i--){
            num_arr[i]=n%10;
            n/=10;
        }
        
        // simple
        // cout<<alpha_code(num_arr,size)<<endl;
        
        // recursive
        // int *storage=new int[size+1]{};
        // cout<<alpha_code(num_arr,size,storage)<<endl;
        // delete storage;

        // iterative
        cout<<alpha_code_iter(num_arr,size)<<endl;
    }
    return 0;
}