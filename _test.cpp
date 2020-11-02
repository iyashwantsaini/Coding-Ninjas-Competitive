#include <bits/stdc++.h>
using namespace std;
int main()
{
    int b=10;
    int n=5;
    vector<int> ***dp = new vector<int> **[b + 1];
    for (int i = 0; i <= b; i++)
    {
        dp[i] = new vector<int> *[n + 1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = new vector<int>;
            dp[i][j]->push_back(-1);
            dp[i][j]->push_back(-1);
        }
    }

    for(int i=0;i<=b;i++){
        for(int j=0;j<=n;j++){
            bool a=(dp[i][j]->at(0))==-1;
            cout<<a<<endl;
        }
    }
}