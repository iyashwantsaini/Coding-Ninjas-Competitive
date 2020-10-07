// https://www.codechef.com/problems/AX06

// Example
// Input:
// 023456789
// 406789123
// 780123456
// 234067891
// 567801234
// 891230567
// 345678012
// 678912305
// 912345670

// Output:
// 123456789
// 456789123
// 789123456
// 234567891
// 567891234
// 891234567
// 345678912
// 678912345
// 912345678

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 9 

bool ispossible(int board[N][N],int num,int row,int col){
	// check row
	for(int i=0;i<N;i++){
		if(board[row][i]==num){
			return false;
		}
	}
	// check col
	for(int i=0;i<N;i++){
		if(board[i][col]==num){
			return false;
		}
	}
	// check box of 9 nums
	int rowfactor=row-(row%3);
	int colfactor=col-(col%3);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i+rowfactor][j+colfactor]==num){
				return false;
			}
		}
	}

	// int checkrow=(row>=0&&row<3)?0:(row>=3&&row<6)?3:(row>=6&&row<9)?6:0;
	// int checkcol=(col>=0&&col<3)?0:(col>=3&&col<6)?3:(col>=6&&col<9)?6:0;
	// for(int i=checkrow;i<checkrow+3;i++){
	// 	for(int j=checkcol;j<checkcol+3;j++){
	// 		if(board[i][j]==num){
	// 			return false;
	// 		}
	// 	}
	// }

	return true;
}

bool find_empty_posn(int board[N][N],int& row,int &col){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(board[i][j]==0){
				row=i;
				col=j;
				return true;
			}
		}
	}
	return false;
}

bool solve_board(int board[N][N]){
	// int flag=0;
	int row,col;
	// find empty posn
	bool found=find_empty_posn(board,row,col); //row&col will now have empty posn indexes
	if(!found){
		return true;
	}
	
	// fill with possible number
	for(int x=1;x<=9;x++){
		if(ispossible(board,x,row,col)){
			board[row][col]=x; //set to this and start exploring next
			// call solve_board again
			bool issolved=solve_board(board);
			// if return true - print board 
			if(issolved){
				return true;
			}
			board[row][col]=0; // to revert for next num try
		}
	}

	return false;  //recursion will not reach to this point at any time if sodoku is solvable
}

int main(){
    // used for fast IO
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    // sets precision for required datatype
    // cout.precision(numeric_limits<double>::max_digits10);
	int board[N][N];
	// we'll be given 9 strings in total
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		for(int j=0;j<s.length();j++){
			board[i][j]=s[j]-'0';
		}
	}
	solve_board(board);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<board[i][j];
		}
		cout<<endl;
	}
	return 0;
}