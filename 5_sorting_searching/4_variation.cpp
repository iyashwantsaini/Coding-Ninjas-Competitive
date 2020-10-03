// https://www.codechef.com/ZCOPRAC/problems/ZCO15002

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    if(n==0||n==1) {
        cout<<0<<endl;
        return 0;
    }
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // sort array
    sort(a,a+n); //nlogn

    // find count -method1 //o(n)
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(abs(a[i]-a[j])>=k){
                count+=n-j;  //as all next a[j]'s are greater than current j
                break;
            }
        }
    }
    cout<<count<<endl;
    
    // find count -method2 : bin search //o(nlogn)

}