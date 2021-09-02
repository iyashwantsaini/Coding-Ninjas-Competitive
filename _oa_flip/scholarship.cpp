#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//
/*
6
1 0 1 0 0 1
1 1 1 0 1 1
*/

int main(){
    int n;
    cin>>n;
    vector<int> stud; //students prefer
    vector<int> coll; //college gives
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        stud.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        coll.push_back(x);
    }
    int count=0;
    while(count<stud.size()){
        if(stud[0]==coll[0]){
            stud.erase(stud.begin()+0);
            coll.erase(coll.begin()+0);
            count=0;
        }else{
            int x=stud[0];
            stud.erase(stud.begin()+0);
            stud.push_back(x);
            count++;
        }
    }
    cout<<"\n"<<stud.size()<<"\n";
    return 0;
}