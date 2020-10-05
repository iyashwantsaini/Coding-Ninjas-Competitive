// print all subsequences of a string - order doesnt matter

#include<bits/stdc++.h>
using namespace std;

void get_all_subseq(string in,string out){
    // if input is empty means we have reached leaves of tree
    if(in==""){
        cout<<out<<endl;
        return;
    }
    // if first char in input included in output
    get_all_subseq(in.substr(1),out+in[0]);
    // if first char in input not included in output
    get_all_subseq(in.substr(1),out);
}

int main(){
    string in="abc";
    string out;
    get_all_subseq(in,out);
    return 0;
}