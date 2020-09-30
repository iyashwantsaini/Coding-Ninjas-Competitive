#include<iostream>
#include<algorithm> //-sort
#include<cmath> //-power
#include<utility>
using namespace std;

struct Interval{
    int start;
    int end;
};

bool compare(Interval i1,Interval i2){
    // on basis of first num
    return i1.start<i2.start;
}

int main(){
    int arr[]={1,4,3,5,7,2,6};

    // sort(start pointer, end pointer)
    sort(arr,arr+7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";    
    }cout<<"\n";
    // sorting in decreasing order
    sort(arr,arr+7,greater<int>());
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }cout<<"\n";

    // sorting in case of pairs/intervals
    // sort on basis of first or second value
    Interval in[]={
        {6,4},{3,4},{4,6},{8,13}
    };
    // sort on basis of first using custom made function
    sort(in,in+4,compare);
    for(int i=0;i<4;i++){
        cout<<in[i].start<<" , "<<in[i].end<<endl;
    }

    // binary search -requires a sorted array
    sort(arr,arr+7);
    cout<<binary_search(arr,arr+7,3)<<endl;
    cout<<binary_search(arr,arr+7,8)<<endl;

    // lower_bound - gives index of found element 
    // if not found returns next index pointer  
    cout<<lower_bound(arr,arr+7,2)-arr<<endl;

    // upper_bound - gives index next to the index of found element 
    cout<<upper_bound(arr,arr+7,2)-arr<<endl;

    // gcd/hcf
    cout<<__gcd(10,6)<<endl;
    // power
    cout<<pow(2,5)<<endl;
    // swap
    int x=10,y=12;
    swap(x,y);
    cout<<x<<" "<<y<<endl;
    // max/min
}