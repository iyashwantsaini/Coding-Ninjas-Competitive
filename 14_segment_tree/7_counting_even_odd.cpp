/*
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
        int numodd=0;
        int numeven=0;
};

void build(){

}

void update_set(){

}

int query(){
    return 0;
}

int main(){
    int n;
    cin>>n;
    int *a = new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    node *tree=new node[4*n];
    build();
    int q;
    cin>>q;
    while(q--){
        int qtype,x,y;
        cin>>qtype>>x>>y;
        if(qtype==0){
            update_set();
        }else if(qtype==1){
            int ans=query();
        }else{
            int ans=query();
        }
    }
    return 0;
}