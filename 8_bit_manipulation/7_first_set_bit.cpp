// You are given an integer N. You need to return an integer M, in which only one bit is set which at position of lowest set bit of N (from right to left).
// Input Format :
// Integer N
// Output Format :
// Integer M
// Sample Input 1 :
// 7
// Sample Output 1 :
// 1
// Sample Input 2 :
// 12
// Sample Output 2 :
// 4

#include <iostream>
using namespace std;

int returnFirstSetBit(int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    // o(1) approach
    return n&(-n);

    // o(n) approach
    // if(n==0) return 0;
    // for(int i=0;i<9;i++){
    //     if((n&1<<i)==(1<<i)){
    //         return 1<<i;
    //     }
    // }
    
}

int main() {
	int n;
	cin >> n;
	cout<< returnFirstSetBit(n) <<endl;
	return 0;
}

