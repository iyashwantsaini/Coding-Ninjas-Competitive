/*
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/

#include <bits/stdc++.h>
using namespace std;

// O(n^4) solution - TLE
int max_sum(int n,int m,int **mat){
    // find sum from each index to the end
    
    int **storage=new int*[n];
    for(int i=0;i<n;i++){
        storage[i]=new int[m]{};
    }
    // O(n^4)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            // find sum for each ~ [i][j] till end ~ [n-1][m-1]
            for(int r=i;r<n;r++){
                for(int c=j;c<m;c++){
                    storage[i][j]+=mat[r][c];
                }
            }

        }
    }
    int overall_max=INT_MIN;
    // select one start and 1 end
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            // find sum from that [i][j] till [r][c]
            for(int r=i;r<n;r++){
                for(int c=j;c<m;c++){
                    int curr_sum=0;
                    curr_sum+=storage[i][j];

                    if(r<n-1){
                        curr_sum-=storage[r+1][j];
                    }
                    
                    if(c<m-1){
                        curr_sum-=storage[i][c+1];
                    }
                    
                    if(r<n-1&&c<m-1){
                        curr_sum+=storage[r+1][c+1];
                    }

                    if(curr_sum>overall_max){
                        overall_max=curr_sum;
                    }    
                }
            }

        }
    }

    for(int i=0;i<n;i++){
        delete storage[i];
    }
    delete storage;
    return overall_max;
}

int max_sum_optimized(int n,int m, int **mat){
    // select start and end col
    // int *sum_storage = new int[n]{}; 

    int overall_max=INT_MIN;

    for(int s=0;s<m;s++){
        
        int *sum_storage = new int[n]{}; 
        for(int e=s;e<m;e++){

            // find sum of all rows in between these start and end columns
            // using previously stored sum to find next sum
            for(int i=0;i<n;i++){
                sum_storage[i]+=mat[i][e];
            }

            // now i have a storage of sums of rows between start and end columns
            // use kadane's algo to find the max sum consecutive subarray and their indices in this sums of rows
            
            int max_sum_kadane=INT_MIN;
            int curr_sum_kadane=0;
            for(int i=0;i<n;i++){
                curr_sum_kadane+=sum_storage[i];
                max_sum_kadane=max(max_sum_kadane,curr_sum_kadane);
                if(curr_sum_kadane<0){
                    curr_sum_kadane=0;
                }
            }
            overall_max=max(overall_max,max_sum_kadane);
        }
    }

    return overall_max;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int **mat=new int*[n];
    for(int i=0;i<n;i++){
        mat[i]=new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    // O(n^4)
    // cout<<max_sum(n,m,mat)<<endl;
    
    // O(n^3)
    cout<<max_sum_optimized(n,m,mat)<<endl;

    for(int i=0;i<n;i++){
        delete mat[i];
    }
    delete mat;
    return 0;
}
