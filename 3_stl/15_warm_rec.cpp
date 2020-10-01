// There is only one beauty parlour in the town CodingNinjasLand. The receptionist at the beauty parlor is flooded with appointment requests because the “Hakori” festival is round the corner and everyone wants to look good on it.
// She needs your help. The problem is they don’t have chairs in reception. They are ordering chairs from NinjasKart. They don’t want to order more than required. You have to tell the minimum number of chairs required such that none of the customers has to stand.

// 8
// 307 2007 1736 2314 2101 1719 435 2214 
// 400 2100 1800 2359 2200 1800 500 2300
// Expected Output
// 2

// 9
// 1708 1607 2012 605 605 101 1002 127 2304
// 1900 1800 2300 1800 1700 1500 1200 1200 2359
// Expected Output
// 5

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
    cin>>n;
    int arrival[n];
    for(int i=0;i<n;i++){
        cin>>arrival[i];
    }
    int departure[n];
    for(int i=0;i<n;i++){
        cin>>departure[i];
    }
	int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=i){
                if(arrival[i]<=arrival[j]&&(departure[i]-arrival[i])>=arrival[j]){
                    count++;
                    break;
                }
            }
        }
    }
    cout<<count<<endl;
}