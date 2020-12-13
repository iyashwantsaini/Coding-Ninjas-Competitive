/*
Given a sequence A1 , A2 , A3 .. AN of length N . Find total number of wave subsequences having length greater than 1.
Wave subsequence of sequence A1 , A2 , A3 .. AN is defined as a set of integers i1 , i2 .. ik such that Ai1 < Ai2 > Ai3 < Ai4 .... or Ai1 > Ai2 < Ai3 > Ai4 .... and i1 < i2 < ...< ik.Two subsequences i1 , i2 .. ik and j1 , j2 .. jm are considered different if k != m or there exists some index l such that il ! = jl
INPUT
First line of input consists of integer N denoting total length of sequence.Next line consists of N integers A1 , A2 , A3 .. AN .
OUTPUT
Output total number of wave subsequences of given sequence . Since answer can be large, output it modulo 10^9+7
CONSTRAINTS
1 ≤ N ≤ 10^5

1 ≤ Ai ≤ 10^5
SAMPLE INPUT
5
1 3 5 4 2
SAMPLE OUTPUT
17
Explanation
All the possible sequences are: [ 1 3 ] , [1 5 ] , [ 1 4 ] , [1 2 ] , [1 3 2] , [1 4 2 ] , [1 5 2] , [1 5 4] , [3 5] , [3 4] , [3 2] , [3 5 2] , [3 4 2] , [3 5 4] , [5 4] , [5 2 ] , [4 2] . Note that value in the bracket are the values from the original sequence whose positions are maintained.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

	return 0;
}