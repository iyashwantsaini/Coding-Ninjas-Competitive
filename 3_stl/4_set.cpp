#include<iostream>
#include<set>
using namespace std;

int main(){
    // set is implemented in stl using bin search tree - log(n)
    set<int> s;
    int arr[]={1,2,3,4,5,1,2,3};
    for(int i=0;i<8;i++){
        s.insert(arr[i]);
    }

    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++){
        cout<<*it<<endl;
    }

    // if after iterating through all it reaches end & still not found
    if(s.find(5)==s.end()){
        cout<<"not found"<<endl;
    }else{
        cout<<"found"<<endl;
    }
    return 0;
}