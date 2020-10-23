/*
Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1
*/

#include<bits/stdc++.h>
using namespace std;

// o(n^5)
// appraoch 1 - Brute force 

// O(n^3)
// approach 2 - creating a matrix having the length of the max 0 square ending at each point
int findMaxSquareWithAllZeros_morecomplex(int** arr, int row, int col){
       
    int **storage=new int*[row];
    for(int i=0;i<row;i++){
        storage[i]=new int[col]{};
    }

    // fill first row
    for(int i=0;i<col;i++){
        storage[0][i]=arr[0][i]==1?0:1;
    }
    // fill first col
    for(int i=0;i<row;i++){
        storage[i][0]=arr[i][0]==1?0:1;
    }

    // start filling the other elements using 1st row and first col
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){

            if(arr[i][j]==1){
                storage[i][j]=0;
            }else{

                int lentocheck=storage[i-1][j-1];
                if(lentocheck==0){
                    storage[i][j]=1;
                    continue;
                }
                // check top
                int lenmaxtop=0;
                for(int r=i-1;r>=i-lentocheck;r--){
                    if(arr[r][j]==0){
                        lenmaxtop++;
                    }else{
                        break;
                    }
                }
                // check left
                int lenmaxleft=0;
                for(int c=j-1;c>=j-lentocheck;c--){
                    if(arr[i][c]==0){
                        lenmaxleft++;
                    }else{
                        break;
                    }
                }
                
                storage[i][j]=min(lenmaxtop,lenmaxleft)+1;
            
            }

        }
    }
    int maxnum=INT_MIN;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(storage[i][j]>maxnum){
                maxnum=storage[i][j];
            }
        }
    }

    for(int i=0;i<row;i++){
        delete storage[i];
    }
    delete storage;

    return maxnum;
}

// approach 3 - best approach 
// creating a matrix having the length of the max 0 square ending at each point
// using the [i-1][j-1],[i-1][j],[i][j-1] for filling the [i][j]th box
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int **storage=new int*[row];
    for(int i=0;i<row;i++){
        storage[i]=new int[col]{};
    }
    
    // filling 1st row
    for(int i=0;i<col;i++){
        storage[0][i]=arr[0][i]==1?0:1;
    }
    // filling 1st col
    for(int i=0;i<row;i++){
        storage[i][0]=arr[i][0]==1?0:1;
    }
    // fill others using these
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(arr[i][j]==1){
                storage[i][j]=0;
            }else{
            	storage[i][j]=min(min(storage[i-1][j],storage[i][j-1]),storage[i-1][j-1])+1;
            }
        }
    }
    
    int maxnum=INT_MIN;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(storage[i][j]>maxnum){
                maxnum=storage[i][j];
            }
        }
    }
    
    for(int i=0;i<row;i++){
        delete storage[i];
    }
    delete storage;

    return maxnum;
}

int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}