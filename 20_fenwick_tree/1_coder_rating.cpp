/*
Some of the more elite (and not-so-elite) coders around take part in a certain unnamed programming contest. In said contest, there are multiple types of competitions. Here, we consider the Open and High School competition types. For each type, each competitor receives a rating, an integer between 1 and 100000, inclusive. A coder's rating is based upon his or her level of performance in matches and is calculated using a complicated formula which, thankfully, you will not be asked to implement.
Although the Open and High School ratings for a coder who has participated in both competition types lately are usually close, this is not always the case. In particular, High School matches are more about speed, since many coders are able to solve all the problems, whereas Open matches require more thinking and there is a steeper curve in terms of problem difficulty.
Problem Statement
You are given N coders (1 ≤ N ≤ 300000), conveniently numbered from 1 to N. Each of these coders participates in both High School and Open matches. For each coder, you are also given an Open rating Ai and a High School rating Hi. Coder i is said to be better than coder j if and only if both of coder i's ratings are greater than or equal to coder j's corresponding ratings, with at least one being greater. For each coder i, determine how many coders coder i is better than.
Input Format
On the first line of input is a single integer N, as described above. N lines then follow. Line i+1 contains two space-separated integers, Ai and Hi.
Output Format
 Line i should contain the number of coders that coder i is better than.
Sample Input
8
1798 1832
862 700
1075 1089
1568 1557
2575 1984
1033 950
1656 1649
1014 1473
Sample Output
6
0
2
4
7
1
5
1
*/

#include <bits/stdc++.h>
using namespace std;

class coder{
    public:
        // x=ai,y=hi
        // index=to maintain original index of the coder as we need to give ans in this order only
        int x,y,index;
};

// sort on basis of x value
// if x equal then take y
bool compare(coder A,coder B){
    if(A.x==B.x){
        return A.y<B.y;
    }
    return A.x<B.x;
}

void update(int y,int *BIT){
    for(;y<=100000;y+=y&(-y)){
        BIT[y]++;
    }
}

int query(int y,int *BIT){
    int count=0;
    for(;y>0;y-=y&(-y)){
        count+=BIT[y];
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    coder *a=new coder[n];
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].index=i;
    }
    sort(a,a+n,compare);
    int *BIT=new int[100001]{};
    int *ans=new int[n];
    for(int i=0;i<n;){
        int endindex=i;
        while(endindex<n&&a[i].x==a[endindex].x&&a[i].y==a[endindex].y){
            endindex++;
        }
        for(int j=i;j<endindex;j++){
            // as we want ans in given input order
            // we'll use the stored indices
            // query
            ans[a[j].index]=query(a[j].y,BIT);
        }
        for(int j=i;j<endindex;j++){
            // update
            update(a[j].y,BIT);
        }
        i=endindex;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
