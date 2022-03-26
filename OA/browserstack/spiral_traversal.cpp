// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/?company[]=BrowserStack&company[]=BrowserStack&page=1&query=company[]BrowserStackpage1company[]BrowserStack

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ssort;
        int counter = r*c;
        for(int rs=0,re=r-1,cs=0,ce=c-1,cnt=0;cnt<counter;){
            
            //first row -fwd
            for(int i=cs;i<=ce && cnt<counter;i++){
                ssort.push_back(matrix[rs][i]);
                cnt++;
            }
            rs++;
            //last col -down
            for(int i=rs;i<=re && cnt<counter;i++){
                ssort.push_back(matrix[i][ce]);
                cnt++;
            }
            ce--;
            //last row -back
            // if(rs!=re){
                for(int i=ce;i>=cs && cnt<counter;i--){
                    ssort.push_back(matrix[re][i]);
                    cnt++;
                }
            // }
            re--;
            //first col -up
            // if(cs!=ce){
                for(int i=re;i>=rs && cnt<counter;i--){
                    ssort.push_back(matrix[i][cs]);
                    cnt++;
                }
            // }
            cs++;
        }
        
        return ssort;
        
    }
};


//6  6  2 28 2 
//12 26 3 28 7 
//22 25 3 4  23