// In Little Flowers Public School, there are many students with same first names. You are given a task to find the students with same names. You will be given a string comprising of all the names of students and you have to tell the name and count of those students having same. If all the names are unique, print -1 instead.
// Note: We don't have to mention names whose frequency is 1.

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
    string s;
    getline(cin,s);
    map<string,int> m;
    for(int i=0;i<s.length();i++){
        string name;
        while(1){
            if(s[i]==' '||i==s.length()){
                break;
            }
            name.push_back(s[i]);
            i++;
        }
        m[name]++;
    }
    int flag=0;
    map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        if(it->second>1){
            flag=1;
        	cout<<it->first<<" "<<it->second<<endl;
        }
    }
    if(flag==0){
        cout<<"-1"<<endl;
    }
}