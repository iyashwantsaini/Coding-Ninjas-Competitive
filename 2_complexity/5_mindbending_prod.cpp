// create a product array such that p[i] = multiplication of all other elemnts of array except current

// 2
// 5
// 10 3 5 6 2
// 2
// 12 20

// 180 600 360 300 900
// 20 12

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// O (n^2) time method
void calcprod_on2(int a[],int n){
    int p[n];
    for(int i=0;i<n;i++){
        p[i]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=i){
                p[i]*=a[j];
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
}

// O (n) time method
void calcprod(int a[],int n){
    int p[n];
    // create left multi array
    int curr_prod=1;
    for(int i=0;i<n;i++){
        p[i]=curr_prod;
        curr_prod*=a[i];
    }
    // create right multi array in same p array
    curr_prod=1;
    for(int i=n-1;i>=0;i--){
        p[i]*=curr_prod;
        curr_prod*=a[i];
    }

    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        // calcprod_on2(a,n);
        calcprod(a,n);
        cout<<"\n";
    }
    return 0;
}