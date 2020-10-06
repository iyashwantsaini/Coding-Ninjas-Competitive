// You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).
// Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
// Input Format
// The first line of input contains an integer 'N' representing 
// the dimension of the maze.
// The next N lines of input contain N space-separated 
// integers representing the type of the cell.
// Output Format :
// For each test case, print the path from start position to destination position and only cells that are part of the solution path should be 1, rest all cells should be 0.

// Output for every test case will be printed in a separate line.
// Note:
// You do not need to print anything, it has already been taken care of. Just implement the given function.
// Constraints:
// 0 < N < 11 0 <= Maze[i][j] <=1

// Time Limit: 1sec
// Sample Input 1 :
// 3
// 1 0 1
// 1 0 1
// 1 1 1
// Sample Output 1 :
// 1 0 0 1 0 0 1 1 1 
// Sample Output 1 Explanation :
// Only 1 path is possible

// 1 0 0
// 1 0 0
// 1 1 1
// Which is printed from left to right and then top to bottom in one line.

// Sample Input 2 :
// 3
// 1 0 1
// 1 1 1
// 1 1 1
// Sample Output 2 :
// 1 0 0 1 1 1 1 1 1 
// 1 0 0 1 0 0 1 1 1 
// 1 0 0 1 1 0 0 1 1 
// 1 0 0 1 1 1 0 0 1 
// Sample Output 2 Explanation :
// 4 paths are possible which are printed in the required format.

#include<iostream>
using namespace std;

void print(int **out,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<out[i][j]<<" ";
        }
    }
    cout<<endl;
}

void get_ans(int maze[][20],int n,int **out, int i,int j){
    if(i>=n||j>=n||i<0||j<0){ //limits crossed
        return;
    }
    else if(out[i][j]==1){ //cell already taken in path
        return;
    }
    else if(i==n-1&&j==n-1){ //reached destination
        //make destination as 1
        out[n-1][n-1]=1;
        print(out,n);
        //reset destination for backtracking - not required for destination point btw
        out[n-1][n-1]=0;
        return;
    }
    else if(maze[i][j]==0){ //reached a block
        return;
    }
    else{
        //maze[i][j]==1
        
        out[i][j]=1; //start path
        // i can go to 4 directions L,R,U,D
        
        //left call
        get_ans(maze,n,out,i,j-1);
        //right call
        get_ans(maze,n,out,i,j+1);
        //up call
        get_ans(maze,n,out,i-1,j);
        //down call
        get_ans(maze,n,out,i+1,j);
        
        //backtrack - revert the paths
        out[i][j]=0;
        
    }
}

void ratInAMaze(int maze[][20], int n){

	int **out=new int*[n];
    for(int i=0;i<n;i++){
        out[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            out[i][j]=0;
        }
    }
    get_ans(maze,n,out,0,0);
    for(int i=0;i<n;i++){
        delete out[i];
    }
    delete out;
    
}

int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}

