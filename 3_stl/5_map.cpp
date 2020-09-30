#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    int arr[]={1,2,3,1,4,5,6,1,2,3};
    // map uses binary search tree - o(logn)
    map<int,int> m;
    // unordered map uses hash table - avg case o(1) : mostly used
    // doesn't care about order
    // unordered_map<int,int> m;
    for(int i=0;i<10;i++){
        m[arr[i]]++;
    }
    // remove a key and its val from map : pass a key to erase
    m.erase(1);
    // iterator
    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" : "<<it->second<<endl;
    }
    
    return 0;
}