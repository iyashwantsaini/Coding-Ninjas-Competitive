#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    // used for fast IO
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    // sets precision for required datatype
    // cout.precision(numeric_limits<double>::max_digits10);

    // code
    // n points provided (width,height)
    int n;
    cin>>n;
    // maintain a map to keep y values for each x
    int *height=new int[5000000+2](); //this is max range given
    int max_x=0;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        // retaining only max value of height for a particular x
        // because all other will be in between the area
        if(height[x/2]<y){
            height[x/2]=y;
        }
        // maintaining the max_x from which we'll start coming towards 0
        if((x/2)>max_x){
            max_x=x/2;
        }
    }

    // start from max_x upto 0 and add max_heights for every index
    ll area=0;
    for(int i=max_x;i>0;i--){
        if(height[i]<height[i+1]){
            height[i]=height[i+1];
        }
        area+=height[i];
    }
    // return ans*2 - as the same area will be present in left
    cout<<area*2<<endl;
	return 0;
}