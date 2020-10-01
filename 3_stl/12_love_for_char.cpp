// Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v(3,0);
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
        	v[0]++;
        }
        if(s[i]=='s'){
        	v[1]++;
        }
        if(s[i]=='p'){
        	v[2]++;
        }
    }
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
	return 0;
}
