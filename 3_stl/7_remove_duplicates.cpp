#include<bits/stdc++.h>
using namespace std;

// remove duplicates from arr

int main(){
    vector<int> arr={1,3,4,5,2,1,4,5,7,8};
    
    // method 1 use set
    // set<int> s; 
    // vector<int> result;
    // for(int i=0;i<10;i++){
    //     if(s.find(arr[i])==s.end()){
    //         result.push_back(arr[i]);
    //         s.insert(arr[i]);
    //     }
    // }
    // for(int i=0;i<result.size();i++){
    //     cout<<result[i]<<" ";
    // }

    // method 2 - sort, check with prev element
    vector<int> result;
    sort(arr.begin(),arr.end());
    result.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(arr[i]!=arr[i-1]){
            result.push_back(arr[i]);
        }
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}