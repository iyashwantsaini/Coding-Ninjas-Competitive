// Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He want to distibute them in a way such that:
// 1. All students get equal number of candies.
// 2. All the candies which a student get must be from a single box only.
// As he want to make all of them happy so he want to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.
// Input
// First line contains 1<=T<=20 the number of test cases. Then T test cases follow. First line of each test case contains N and K. Next line contains N integers, ith of which is the number of candies in ith box.
// Output
// For each test case print the required answer in a seperate line.
// Sample Input:
// 2
// 3 2 
// 3 1 4
// 4 1
// 3 2 3 9
// Sample Output:
// 3
// 9

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> v,int num,int p){
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]>=num){
            count+=v[i]/num;
            v[i]=v[i]%num;
            if(count>=p){
            	return true;
        	}
        }
    }
    return false;
}

int main() {
	int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(n==0){
         	cout<<0<<endl;
            continue;
        }
        vector<int> candies;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            candies.push_back(num);
        }
        if(n==1){
            cout<<candies[0]/k<<endl;
            continue;
        }
        sort(candies.begin(),candies.end());
        
        // using bin search to find max possible mandy that is possible 
        int mincandy=0;
        int maxcandy=candies[candies.size()-1];
        int totalcandies=0;
        
        while(mincandy<=maxcandy){
            int mid=(mincandy+maxcandy)/2;
            if(check(candies,mid,k)){
                if(mid>totalcandies){
                    totalcandies=mid;
                }
                mincandy=mid+1;
            }else{
                maxcandy=mid-1;
            }
        }
        cout<<totalcandies<<endl;
        
    }
}