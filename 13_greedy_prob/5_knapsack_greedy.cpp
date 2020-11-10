#include<bits/stdc++.h>
using namespace std;

bool compare(int *i1,int *i2){
    //find the bigger val/wt item
    //means val must be big, wt must be small
    double comparision1=(double)i1[0]/(double)i1[1];
    double comparision2=(double)i2[0]/(double)i2[1];
    return comparision1>comparision2;
}

double frac_knap(int **items,int W){
    sort(items,items+3,compare);
    double maxval=0;
    for(int i=0;i<3;i++){
        if(items[i][1]<=W){
            maxval+=items[i][0];
            W-=items[i][1];
        }else{
            // add remaining required cost to the total value
            double rem_val=((double)W/(double)items[i][1])*(double)items[i][0];
            maxval+=rem_val;
            break;
        }
    }
    return maxval;
}

int main(){
    // val, weight
    int **items=new int*[3];
    for(int i=0;i<3;i++){
        items[i]=new int[2];
    }
    items[0][0]=60; //val
    items[0][1]=10; //wt
    items[1][0]=100; //val
    items[1][1]=20; //wt
    items[2][0]=120; //val
    items[2][1]=30; //wt
    int W=50;
    cout<<frac_knap(items,W);
}