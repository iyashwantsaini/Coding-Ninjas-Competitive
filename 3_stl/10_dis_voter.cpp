// https://www.codechef.com/problems/VOTERS

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    set<int> s;
    set<int> ans;
    for(int i=0;i<n1;i++){
        int num;
        cin>>num;
        if(s.find(num)==s.end()){
            s.insert(num);
        }
    }
    for(int i=0;i<n2;i++){
        int num;
        cin>>num;
        if(s.find(num)!=s.end()){
            ans.insert(num);
        }else{
            s.insert(num);
        }
    }
    for(int i=0;i<n3;i++){
        int num;
        cin>>num;
        if(s.find(num)!=s.end()){
            ans.insert(num);
        }else{
            s.insert(num);
        }
    }
    // sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    set<int>::iterator it;
    for(it=ans.begin();it!=ans.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}