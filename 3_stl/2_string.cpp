#include<iostream>
#include<string>
using namespace std;

int main(){
    string s="yashwant";
    cout<<s<<endl;
    string s1(s);
    cout<<s1<<endl;
    string s2(s1,2,5);
    cout<<s2<<endl;
    string s3=s1.substr(2,5);
    cout<<s3<<endl;

    // LEXOGRAPHIC COMPARISION
    if(s.compare(s1)==0){
        cout<<"s==s1";
    }else{
        cout<<"s!=s1";
    }
    return 0;
}