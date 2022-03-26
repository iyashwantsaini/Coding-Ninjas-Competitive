/*
The Government Public School of Wadiya city is holding a congress of students. The number of representations from each grade is equal to the grade number. From the first grade, the congress has only 1 representative, from the second grade, the congress has only 2 representatives and so on and so forth. All the representatives are told to assemble in the main ground. All the same grade representatives are standing together.
A representative of grade P comes to the stage and says that he is unable to find his group of representatives. The organisers are busy with other tasks. You have to find the group for the lost representative.
The main ground is a huge N*N matrix. You are given this matrix as input. Each representative occupies a cell. An occupied cell is represented by integer 1 and an unoccupied cell by integer 0. All the representatives of the same grade are connected to each other and disconnected from other grade representatives. An occupied cell is said to be connected to those occupied cells which are reachable from its cell. A representative can move across to other occupied cells with which it shares its edges.
For example:
Alt Text

In this diagram of a part of the ground, red coloured cells represents the connected group of sixth grade students, yellow cell represents the connected group of first grade student and green represents the connected group of fourth grade students.
You will be given the matrix and you have to find the starting cell of the connected group of the lost representative.
Starting Cell is the one with the lowest row value. (If row number of two or more cells is same, then starting cell among them is the one with lowest column value)
It may be possible that the representative may be confused, and the grade he says he is from is actually not present. In that case, print starting cell as -1 -1.
Input Format:
First line of input contains integer t, representing the number of test cases.
First line of each test case contains integer n, representing the size of the matrix.
The second line onwards, the next 'N' lines or rows represent the ith row values.
Each of the ith rows constitutes 'N' column values separated by a single space.
Last line of each test case contains integer p, representing the grade of the lost representative.
Constraints:
1 <= N <= 1000
1 <= p <= 100
Output Format:
For each test case, you need to print the starting cell of the connected group of the lost representative.
Sample Input 1:
1
5
1 1 0 0 0
0 1 0 0 1
1 1 0 1 1
0 0 0 0 0
1 1 0 0 1
3
Sample Output 1:
1 4
Explanation:
The lost representative is from the 3rd grade. In the given matrix, the 3rd grade is represented by the cluster of 1s where the starting cell of this cluster is 1,4.
*/

#include<bits/stdc++.h>
using namespace std;

int dfs(int n,int i,int j,int **mat,int **visited){
    visited[i][j]=1;
    int ans=1;
    //     down
    if((i+1<=n)&&(visited[i+1][j]==0)&&mat[i+1][j]==1){
        ans+=dfs(n,i+1,j,mat,visited);
    }
    //     up
    if((i-1>=1)&&(visited[i-1][j]==0)&&mat[i-1][j]==1){
        ans+=dfs(n,i-1,j,mat,visited);
    }
    //     right
    if((j+1<=n)&&(visited[i][j+1]==0)&&mat[i][j+1]==1){
        ans+=dfs(n,i,j+1,mat,visited);
    }
    //     left
    if((j-1>=1)&&(visited[i][j-1]==0)&&mat[i][j-1]==1){
        ans+=dfs(n,i,j-1,mat,visited);
    }
    return ans;
}

int main(){
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int **mat=new int*[n+1];
        for(int i=0;i<=n;i++){
            mat[i]=new int[n+1]{};
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>mat[i][j];
            }
        }
        int p;
        cin>>p;
        int ansi=0;
        int ansj=0;
        int **visited=new int*[n+1];
        for(int i=0;i<=n;i++){
            visited[i]=new int[n+1]{};
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(visited[i][j]==0&&mat[i][j]==1){
                    int num=dfs(n,i,j,mat,visited);
                    if(num==p){
                        ansi=i;
                        ansj=j;
                        break;
                    }
                }
            }
        }
        cout<<ansi-1<<" "<<ansj-1<<"\n";
    }
    return 0;
}