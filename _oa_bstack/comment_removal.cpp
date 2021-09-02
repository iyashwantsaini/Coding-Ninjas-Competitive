// https://practice.geeksforgeeks.org/problems/comment-removal2017/1/?company[]=BrowserStack&company[]=BrowserStack&page=1&query=company[]BrowserStackpage1company[]BrowserStack

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string removeComments (string code){
    // Your Code Here
    string ans;
    for(int i=0;i<code.size();i++){
        if(code[i]=='/'&&i+1<code.size()&&code[i+1]=='/'){
            while(i!=code.size()){
                i++;
                if((code[i]=='\\'&&i+1<code.size()&&code[i+1]=='n')){
                    i++;
                    i++;
                    break;
                }
            }
        }
        if(code[i]=='/'&&i+1<code.size()&&code[i+1]=='*'){
            while(i!=code.size()){
                i++;
                if(code[i]=='*'&&i+1<code.size()&&code[i+1]=='/'){
                    i++;
                    i++;
                    break;
                }
            }
        }
        ans.push_back(code[i]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // string x="#include int main(int *argc,char **argv){ // First line of code\\n printf(\"Hello World!!!\"); return 0; }";

    string x="#include int main(int *argc,char **argv){ /* First line of code Printing Hello World */ printf(\"Hello World!!! \"); return 0; }";

    string ans=removeComments(x);
    cout<<ans;
    return 0;
}