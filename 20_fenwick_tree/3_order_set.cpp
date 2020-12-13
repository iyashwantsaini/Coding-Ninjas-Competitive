/*
In this problem, you have to maintain a dynamic set of numbers which support 

=> the two fundamental operations
INSERT(S,x): if x is not in S, insert x into S
DELETE(S,x): if x is in S, delete x from S
=> and the two type of queries
K-TH(S) : return the k-th smallest element of S
COUNT(S,x): return the number of elements of S smaller than x

Input Format
Line 1: Q (1 ≤ Q ≤ 200000), the number of operations
In the next Q lines, the first token of each line is a character I, D, K or C meaning that the corresponding operation is INSERT, DELETE, K-TH or COUNT, respectively, following by a whitespace and an integer which is the parameter for that operation.

If the parameter is a value x, it is guaranteed that ≤ |x| ≤ 10^9. If the parameter is an index k, it is guaranteed that 1 ≤ k ≤ 10^9.`
Output
For each query, print the corresponding result in a single line. In particular, for the queries K-TH, if k is larger than the number of elements in S, print the word 'invalid'.
Input Format
8
I -1
I -1
I 2
C 0
K 2
D -1
K 1
K 2
Output Format
1
2
2
invalid
*/

// incomplete

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int q;
//     cin>>q;

//     map<int,int> m;
//     int *BIT=new int[q+1]{};
    
//     char c;
//     int x;
//     while(q--){
//         cin>>c>>x;
//         if(c=='I'){
//             if(query(m[x])==query(m[x]-1)){
//                 // means element not currently present
//                 m[x]=1;
//                 auto val=m.find(x);
//                 update(q,x,BIT);
//             }
//         }else if(c=='D'){
//             if(query[m[x]]!=query(m[x]-1)){
//                 // means element is present => delete it
//                 del(x,BIT);
//             }
//         }else if(c=='K'){

//         }else{

//         }
//     }
//     return 0;
// }
