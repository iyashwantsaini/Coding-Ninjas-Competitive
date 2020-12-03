/*
Ninja has been appointed as a data scientist for a MNC. He has been provided with a huge list of people who belong to some countries. He doesn't know who belongs to which country, but he knows which two people belong to the same country. Now, he has been asked to find the total number of unique countries this group of people belong to.
Ninja has many other projects to work on, therefore he has passed on this task to you. Are you up to the challenge?
Input Format
First line of input contains two space separated integers representing the total number of people in the group (n) and number of pairs of people (p) whose country is known to Ninja.
Next p lines contain two integers representing which two people belong to the same country.
Output Format
Print the number of unique countries the given group of people belong to.
Sample Input 1:
4 3
0 1
1 3 
0 3
Sample Output 1:
2
Explanation:
Person 0,1 and 3 belong to the same country. No information about person 2 is mentioned. Hence, we can say that person 2 belongs to a separate country than that of person 0,1 and 3. Therefore, there are people from 2 countries in the given group.
Sample Input 2:
6 4
0 1 
0 2
1 2
3 4
Sample Output 2:
3
*/

#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
        int ei;
        int ej;
};

int get_parent(int num,int *par,int *rank){
    if(num==par[num]){
        return num;
    }
    int p=get_parent(par[num],par,rank);
    if(rank[num]<=rank[p]){
    	par[num]=p;
        rank[p]++;
    }else{
        par[p]=num;
        rank[num]++;
    }
    return p;
}

int main(){
    int n,m;
    cin>>n>>m;
    edge *edges=new edge[m];
    for(int i=0;i<m;i++){
        cin>>edges[i].ei>>edges[i].ej;
    }
    int *parents=new int[n];
    for(int i=0;i<n;i++){
        parents[i]=i;
    }
    edge *mst=new edge[n-1];
    int *rank=new int[n]{};
    int count=0;
    for(int i=0;i<m;i++){
        if(count>=n-1){
            break;
        }
        edge curr=edges[i];
        int p1=get_parent(curr.ei,parents,rank);
        int p2=get_parent(curr.ej,parents,rank);
        if(p1!=p2){
            mst[count]=curr;
            if(rank[p1]<=rank[p2]){
                parents[p1]=p2;
                rank[p2]++;
            }else{
                parents[p2]=p1;
                rank[p1]++;
            }
            count++;
        }
    }
	int ncount=0;
    for(int i=0;i<n;i++){
        if(i==parents[i]){
            ncount++;
        }
    }
    cout<<ncount<<"\n";
}