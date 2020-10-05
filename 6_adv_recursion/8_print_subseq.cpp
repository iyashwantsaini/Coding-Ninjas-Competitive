// substring - continuous eg. abc -> bc
// subseq - not continuous eg. abc -> ac

#include<bits/stdc++.h>
using namespace std;

int find_all_subseq(string in,string out[]){
    // if in[0]=='\0' means we have reached end of tree
    // now its time ot fill the output array and backtrack
    if(in[0]=='\0'){
        out[0]="";
        return 1;
    }
    // size of output array after passing input without the first character
    int small_prob=find_all_subseq(in.substr(1),out);
    // adding the not passed charcter to first index of every returned string and apppending to output array
    for(int i=0;i<small_prob;i++){
        out[i+small_prob]=in[0]+out[i];
    }
    // now size of output will be twice the original
    return 2*small_prob;
}

int main(){
    string input="abc";
    string *output=new string[1000];
    int num=find_all_subseq(input,output);
    for(int i=0;i<num;i++){
        cout<<output[i]<<endl;
    }
}