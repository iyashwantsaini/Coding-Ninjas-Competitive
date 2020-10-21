/*
Given a MATRIX of cost. Find min cost to go from starting (0,0) index to ending (n,n) index.
Possible directions -> right, down, diagonally down

Input
3 3
4 3 2
1 8 3
1 1 8
Output
14
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int min_cost_iter(int curr_row,int curr_col,int rows,int cols,int **matrix,int **storage){
    // fill destination
    storage[rows-1][cols-1]=matrix[rows-1][cols-1];
    // fill last row
    for(int i=cols-2;i>=0;i--){
        storage[rows-1][i]=matrix[rows-1][i]+storage[rows-1][i+1];
    }
    // fill last col
    for(int i=rows-2;i>=0;i--){
        storage[i][cols-1]=matrix[i][cols-1]+storage[i+1][cols-1];
    }
    // fill rest matrix
    for(int i=rows-2;i>=0;i--){
        for(int j=cols-2;j>=0;j--){
            storage[i][j]=matrix[i][j]+min(min(storage[i][j+1],storage[i+1][j]),storage[i+1][j+1]);
        }
    }
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //         cout<<storage[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return storage[0][0];
}

// int min_cost_rec(int curr_row,int curr_col,int rows,int cols,int **matrix,int **storage){
    
//     // we have reached destination
//     if(curr_row==rows-1&&curr_col==cols-1){
//         return matrix[curr_row][curr_col];
//     }
//     // gone out of bound
//     if(curr_row>=rows||curr_col>=cols){
//         return INT_MAX;
//     }
//     // already path explore
//     if(storage[curr_row][curr_col]>0){
//         return storage[curr_row][curr_col];
//     }
//     // right
//     int dir1=min_cost_rec(curr_row,curr_col+1,rows,cols,matrix,storage);
//     // down
//     int dir2=min_cost_rec(curr_row+1,curr_col,rows,cols,matrix,storage);
//     // diagonally down
//     int dir3=min_cost_rec(curr_row+1,curr_col+1,rows,cols,matrix,storage);

//     // select min path
//     int ans=matrix[curr_row][curr_col]+min(min(dir1,dir2),dir3);
//     storage[curr_row][curr_col]=ans;
//     return ans;
// }

int main(){
    // m rows,n cols
    int m,n;
    cin>>m>>n;
    int **matrix=new int*[m];
    for(int i=0;i<m;i++){
        matrix[i]=new int[n];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    // storage_matrix
    int **storage=new int*[m];
    for(int i=0;i<m;i++){
        storage[i]=new int[n]{};
    }

    // cout<<min_cost_rec(0,0,m,n,matrix,storage);
    cout<<min_cost_iter(0,0,m,n,matrix,storage);

    // clearing memory
    for(int i=0;i<m;i++){
        delete storage[i];
        delete matrix[i];
    }
    delete storage;
    delete matrix;
}