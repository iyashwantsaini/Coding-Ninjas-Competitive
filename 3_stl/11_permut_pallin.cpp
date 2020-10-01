// https://www.codechef.com/problems/PERMPAL

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s.length()==0) 
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(s.length()==1) {
            cout<<"1"<<endl;
            continue;
        }
        map<char,vector<int>> m;
        for(int i=0;i<s.size();i++){
            m[s[i]].push_back(i);
        }
        map<char,vector<int>>::iterator it;
        int numofodd=0;
        for(it=m.begin();it!=m.end();it++){
            if(it->second.size()%2==0){
                continue;
            }else{
                numofodd++;
            }
        }
        if(numofodd>=2){
            cout<<"-1"<<endl;
            continue;
        }
        vector<int> v(s.length());
        int i=0,j=s.length()-1;
        for(it=m.begin();it!=m.end();it++){
            int iinner=0,jinner=it->second.size()-1;
            if(it->second.size()%2==0){
                while(iinner<=jinner){
                    v[i++]=it->second[iinner++];
                    v[j--]=it->second[jinner--];
                }
            }else{
                v[v.size()/2]=it->second[iinner];
                iinner++;
                while(iinner<jinner){
                    v[i++]=it->second[iinner++];
                    v[j--]=it->second[jinner--];
                }
            }
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i]+1<<" ";
        }cout<<"\n";
    }
}