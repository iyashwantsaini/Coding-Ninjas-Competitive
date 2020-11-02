/*
You just received another bill which you cannot pay because you lack the money.
Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.
You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.
You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.
Input
The first line of the input specifies your party budget and the number n of parties.

The following n lines contain two numbers each. The first number indicates the entrance fee of each party. Parties cost between 5 and 25 francs. The second number indicates the amount of fun of each party, given as an integer number ranging from 0 to 10.

The budget will not exceed 500 and there will be at most 100 parties. All numbers are separated by a single space.

There are many test cases. Input ends with 0 0.
Output
For each test case your program must output the sum of the entrance fees and the sum of all fun values of an optimal solution. Both numbers must be separated by a single space. 
Sample Input
50 10
12 3
15 8
16 9
16 6
10 2
21 9
18 4
12 4
17 8
18 9 

50 10
13 8
19 10
16 8
12 9
10 2
12 8
13 5
15 5
11 7
16 2

0 0
Sample Output
49 26
48 32
*/

// pair approach 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int,int> party(int b,int n,int **p,pair<int,int> **dp){
    
    // base cases
    if(n==0){
        pair<int,int> ans;
        ans.first=0;
        ans.second=0;
        return ans;
    }
    
    // work already done
    if(dp[b][n].first!=-1&&dp[b][n].second!=-1){
        return dp[b][n];
    }

    // current included
    pair<int,int> final;
    if(p[0][0]<=b){

        pair<int,int> opt1=party(b-p[0][0],n-1,p+1,dp);
        opt1.first+=p[0][0];
        opt1.second+=p[0][1];

        pair<int,int> opt2=party(b,n-1,p+1,dp);

        if(opt1.second>opt2.second){
            final=opt1;
        }
        else if(opt1.second<opt2.second){
            final=opt2;
        }
        // fun is same
        // choose the one with less cost
        else{
            if(opt1.first>opt2.first){
                final=opt2;
            }else{
                final=opt1;
            }
        }

    }else{
        // current not included
        final=party(b,n-1,p+1,dp);
    }
    dp[b][n].first=final.first;
    dp[b][n].second=final.second;
    return final;
}

int main(){
    while(1){

        // budget,no of parties
        int b,n;
        cin>>b>>n;
        if(b==0&&n==0){
            return 0;
        }
        int **p=new int*[n+1];
        for(int i=0;i<=n;i++){
            p[i]=new int[2];
        }
        for(int i=0;i<n;i++){
            // entrance fee, amount of fun
            cin>>p[i][0]>>p[i][1];
        }
        
		pair<int, int>** dp = new pair<int, int> * [b+1];
		for (int i = 0;i<=b; i++){
			dp[i] = new pair<int, int>[n + 1];
			for (int j=0;j<=n; j++){
				dp[i][j].first = -1;
				dp[i][j].second = -1;
			}
		}

        pair<int,int> a;
        a=party(b,n,p,dp);
        cout<<a.first<<" "<<a.second<<endl;

        for(int i=0;i<=n;i++){
            delete p[i];            
        }
        delete p;

    }
    return 0;
}


// 3D array approach - 2 TLE
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// vector<int> party(int b,int n,int **p,int ***dp){
	
//     // 0 index =cost, 1 index =fun
//     vector<int> ans11(2,0),ans12(2,0),ans21(2,0);
    
//     // base cases
//     if(n==0){
//         vector<int> ans(2,0);
//         ans[0]=0;
//         ans[1]=0;
//         return ans;
//     }
    
//     // work already done
//     if(dp[b][n][0]!=-1&&dp[b][n][1]!=-1){
//         vector<int> a(2,0);
//         a[0]=dp[b][n][0];
//         a[1]=dp[b][n][1];
//         return a;
//     }

//     // current included
//     vector<int> final(2,0);
//     if(p[0][0]<=b){

//         ans11=party(b-p[0][0],n-1,p+1,dp);
//         ans11[0]+=p[0][0];
//         ans11[1]+=p[0][1];

//         ans12=party(b,n-1,p+1,dp);

//         if(ans11[1]>ans12[1]){
//             final=ans11;
//         }
//         else if(ans11[1]<ans12[1]){
//             final=ans12;
//         }
//         // fun is same
//         // choose the one with less cost
//         else{
//             if(ans11[0]>ans12[0]){
//                 final=ans12;
//             }else{
//                 final=ans11;
//             }
//         }

//     }else{
//         // current not included
//         final=party(b,n-1,p+1,dp);
//     }
//     dp[b][n][0]=final[0];
//     dp[b][n][1]=final[1];
//     return final;
// }

// int main(){
//     while(1){

//         // budget,no of parties
//         int b,n;
//         cin>>b>>n;
//         if(b==0&&n==0){
//             return 0;
//         }
//         int **p=new int*[n+1];
//         for(int i=0;i<=n;i++){
//             p[i]=new int[2];
//         }
//         for(int i=0;i<n;i++){
//             // entrance fee, amount of fun
//             cin>>p[i][0]>>p[i][1];
//         }
//         int ***dp=new int**[b+1];
//         for(int i=0;i<=b;i++){
//             dp[i]=new int*[n+1];
//             for(int j=0;j<=n;j++){
//                 dp[i][j]=new int[2];
//             }
//         }

//         for(int i=0;i<=b;i++){
//             for(int j=0;j<=n;j++){
//                 dp[i][j][0]=-1;
//                 dp[i][j][1]=-1;
//             }
//         }

//         vector<int> a(2,0);
//         a=party(b,n,p,dp);
//         cout<<a[0]<<" "<<a[1]<<endl;

//         for(int i=0;i<=b;i++){
//             for(int j=0;j<=n;j++){
//                 delete dp[i][j];
//             }
//             delete dp[i];
//         }
//         delete dp;

//         for(int i=0;i<=n;i++){
//             delete p[i];            
//         }
//         delete p;

//     }
//     return 0;
// }
