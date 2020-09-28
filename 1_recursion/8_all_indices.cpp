// Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
// Do this recursively. Indexing in the array starts from 0.

#include<iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    static int isize=size;
    static int index=0;
    static int flag=0;
	//base
    if(size==0) {
        if(flag==1){
            return index;
        }
        return -1;
    }
    if(input[0]==x){
        output[index]=isize-size;
        index++;
        flag=1;
    }
    return allIndexes(input+1,size-1,x,output);
}

int main(){
    int n=10;
    int input[] = {1,3,5,6,3,2,1,7,3,4};
    int x=3;
    int output[n];
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
}
