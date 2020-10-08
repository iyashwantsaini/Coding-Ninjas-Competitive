// Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
// Input Format :
// 9 Lines where ith line contains ith row elements separated by space
// Output Format :
//  true or false
// Sample Input :
// 9 0 0 0 2 0 7 5 0 
// 6 0 0 0 5 0 0 4 0 
// 0 2 0 4 0 0 0 1 0 
// 2 0 8 0 0 0 0 0 0 
// 0 7 0 5 0 9 0 6 0 
// 0 0 0 0 0 0 4 0 1 
// 0 1 0 0 0 5 0 8 0 
// 0 9 0 0 7 0 0 0 4 
// 0 8 2 0 4 0 0 0 6
// Sample Output :
// true

#include<iostream>
using namespace std;

bool find_empty(int board[][9],int &row,int &col){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}

bool check_row(int board[][9],int i,int j,int num){
    for(int row=0;row<9;row++){
        if(board[row][j]==num){
            return false;
        }
    }
    return true;
}

bool check_col(int board[][9],int i,int j,int num){
    for(int col=0;col<9;col++){
        if(board[i][col]==num){
            return false;
        }
    }
    return true;
}

bool check_block(int board[][9],int i,int j,int num){
    int checki=i>=0&&i<3?0:i>=3&&i<6?3:6;
    int checkj=j>=0&&j<3?0:j>=3&&j<6?3:6;
    for(int row=checki;row<checki+3;row++){
        for(int col=checkj;col<checkj+3;col++){
            if(board[row][col]==num){
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(int board[][9]){
    int row,col;
    bool found=find_empty(board,row,col);
    if(found){
        // go from 1 to 9 and
        for(int i=0;i<=9;i++){
            bool rowcheck=check_row(board,row,col,i);
            bool colcheck=check_col(board,row,col,i);
            bool blockcheck=check_block(board,row,col,i);
            if(rowcheck&&colcheck&&blockcheck){
                board[row][col]=i;
                bool findifvalid=solve_sudoku(board);
                if(findifvalid){
                    return true;
                }
                board[row][col]=0;
            }
        }
        // check row
        // check col
        // check block
        // fill that row,col and call solve_sudoku again
        // if returned true - return true
        // if returned false - try for another num
    }else{
        // no empty means sudoku is filled or solved
        return true;
    }
    return false;
}

bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    return solve_sudoku(board);

}

int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}

