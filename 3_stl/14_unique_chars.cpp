// Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.

#include<iostream>
#include<map>
using namespace std;

char* uniqueChar(char *str){
	map<char,int> m;
    for(int i=0;str[i]!='\0';i++){
        m[str[i]]=1;
    }
    char *ans=new char[m.size()];
    int x=0;
    for(int i=0;str[i]!='\0';i++){
        if(m[str[i]]==1){
            ans[x++]=str[i];
            m[str[i]]=0;
        }
    }
    return ans;
}

int main() {
	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}