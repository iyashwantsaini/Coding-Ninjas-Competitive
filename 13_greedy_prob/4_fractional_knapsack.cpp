/*
You want to paint your house. The total area of your house is D units. There are a total of N workers. The ith worker is available after time Ti, has hiring cost Xi and speed Yi. This means he becomes available for hiring from time Ti and remains available after that. Once available, you can hire him with cost Xi, after which he will start painting the house immediately, covering exactly Yi units of house with paint per time unit. You may or may not hire a worker and can also hire or fire him at any later point of time. However, no more than 1 worker can be painting the house at a given time.
Since you want the work to be done as fast as possible, figure out a way to hire the workers, such that your house gets painted at the earliest possible time, with minimum cost to spend for hiring workers.
Note: You can hire a previously hired worker without paying him again.
Input
The first line of input contains two integers "N D", the number of workers and the area of your house respectively. The ith of the next N lines denotes the ith worker, and contains three integers "Ti Xi Yi", described in the statement.
Output
Output one integer, the minimum cost that you can spend in order to get your house painted at the earliest.
Constraints
1 ≤ N, T, X, Y ≤ 10^5
1 ≤ D ≤ 10^11
Sample Input
3 3
1 1 1
2 2 2
3 1 5
Sample Output
3
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//our main priority is time
bool compare(ll w1[3],ll w2[3]){
    //if time is same
    if(w1[0]==w2[0]){
        //if speed is same
        if(w1[2]==w2[2]){
            //choose the one with smaller cost
        	return w1[1]<w2[1];
        }else{
            //if speed not same consider the one with faster speed irrespective of cost
            return w1[2]>w2[2];
        }
    }else{
        return w1[0]<w2[0];
    }
}

int main()
{
    ios_base::sync_with_stdio(false) ; 
    cin.tie(NULL) ; 
	ll n,d;
    cin>>n>>d;
    ll **w=new ll*[n+1];
    for(int i=0;i<n;i++){
        w[i]=new ll[3];
        cin>>w[i][0]>>w[i][1]>>w[i][2];
    }
    sort(w,w+n,compare);
    
    // for(int i=0;i<n;i++){
    //     cout<<w[i][0]<<w[i][1]<<w[i][2]<<endl;
    // }
    
    ll area_done=0;
    ll cost=w[0][1]; //cost is of the first worker
    //choosing the first worker as previous and current
    ll prev_worker=0;
    ll curr_worker=0;
    
    for(int i=1;i<n;i++){
        prev_worker=i-1;
        ll time_diff=w[i][0]-w[prev_worker][0];
        
        area_done+=time_diff*w[curr_worker][2];
        
        if(area_done>=d){
            //means we have painted all required area
            break;
        }
        
        //if we found a better worker then use him/her as our current
        if(w[curr_worker][2]<w[i][2]){
            
            curr_worker=i;
            //now as we have choosen our current worker, add his/her cost to our total cost
            cost+=w[curr_worker][1];
            
        }
        
    }
    
    cout<<cost<<endl;
    return 0;
}