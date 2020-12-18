/*
(a*b)%m=1 => find b if valid
*/

#include<bits/stdc++.h>
using namespace std;

class triplet{
    public:
        int x;
        int y;
        int gcd_;
};

triplet extended_euclid(int a,int b){
    // base case
    if(b==0){
        triplet baseans;
        baseans.gcd_=a;
        baseans.x=1;
        baseans.y=0;
        return baseans;
    }
    // get x1,y1,gcd_ from children
    triplet small_ans=extended_euclid(b,a%b);
    // calculate our ans from children
    triplet ans;
    ans.gcd_=small_ans.gcd_;
    ans.x=small_ans.y;
    ans.y=small_ans.x-(a/b)*small_ans.y;
    return ans;
}

int mm_inverse(int a,int m){
    triplet ans=extended_euclid(a,m);
    return ans.x;
}

int main(){
    int a=5,m=17;
    int ans=mm_inverse(a,m);
    cout<<"Multiplicative Modulo Inverse : "<<ans<<"\n";
    return 0;
}