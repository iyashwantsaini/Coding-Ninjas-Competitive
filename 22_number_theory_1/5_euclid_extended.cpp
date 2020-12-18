/*
given ax+by=gcd(a,b) => find a & b
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

int main(){
    int a=16,b=10;
    triplet ans=extended_euclid(a,b);
    cout<<"X: "<<ans.x<<" | Y: "<<ans.y<<" | GCD: "<<ans.gcd_<<"\n";
    return 0;
}