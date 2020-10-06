// You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
// Input Format :
// Line 1 : Integer N
// Output Format :
// One Line for every board configuration. 
// Every line will have N*N board elements printed row wise and are separated by space
// Note : Don't print anything if there isn't any valid configuration.
// Constraints :
// 1<=N<=10
// Sample Input 1:
// 4
// Sample Output 1 :
// 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
// 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 

#include<iostream>
using namespace std;

void print(int **board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
    }
    cout<<endl;
}

bool ispossible(int **board,int n,int i,int j){
    //check col
    for(int row=0;row<n;row++){
        if(board[row][j]==1){
            return false;
        }
    }
    //check row
    for(int col=0;col<n;col++){
        if(board[i][col]==1){
            return false;
        }
    }
    //check diagonal left bend top
    for(int row=i,col=j;row>=0&&col>=0;row--,col--){
        if(board[row][col]==1){
            return false;
        }
    }
    //check diagonal right bend top
    for(int row=i,col=j;row<n&&row>=0&&col>=0&&col<n;row--,col++){
        if(board[row][col]==1){
            return false;
        }
    }
    return true;
}

void find_all_possible(int **board,int n,int i,int j){
    //crossed limits
    if(i==n){
        print(board,n);
    }
    //check for all cols of a particular row
        for(int col=j;col<n;col++){ //col
            if(ispossible(board,n,i,col)){
                board[i][col]=1;
                find_all_possible(board,n,i+1,0);
                board[i][col]=0;
            }
        }
}

void placeNQueens(int n){
    int **board=new int*[n];
    for(int i=0;i<n;i++){
        board[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=0;
        }
    }
	find_all_possible(board,n,0,0);
    for(int i=0;i<n;i++){
        delete board[i];
    }
    delete board;
}

int main(){

  int n; 
  cin >> n ;
  placeNQueens(n);

}