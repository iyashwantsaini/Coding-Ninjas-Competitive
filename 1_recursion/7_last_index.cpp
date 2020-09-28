// Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
// Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
// You should start traversing your array from 0, not from (N - 1).

#include<iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    static int isize=size;
    static int store=-1;
	//base
    if(size==0) {
        if(store!=-1){
            return store;
        }
        return -1;
    }
    if(input[0]==x){
        store = isize-size;
    }
    return lastIndex(input+1,size-1,x);
}

int main(){
    int input[]={1,2,3,4,5,3,2,3,4};
    cout << lastIndex(input, 9, 3) << endl;
}


