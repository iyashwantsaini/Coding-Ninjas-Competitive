// There are ‘n’ number of balls in a container. Mr. Sharma and Singh want to take balls out from the container. At each step, Mr. Sharma took ‘k’ balls out of the box and Mr. Singh took one-tenth of the remaining balls. Suppose there are 29 balls at the moment and k=4. Then, Mr. Sharma will take 4 balls and Mr. Singh will take 2 balls (29-4 = 25; 25/10 = 2). If there are less than ‘k’ balls remaining at some moment, then Mr. Sharma will take all the balls which will get the container empty. The process will last until the container becomes empty. Your task is to choose minimal ‘k’ for Mr. Sharma such that Mr. Sharma will take at least half of the balls from the container.
// Input Format:
// The Only line of input contains a single integer ‘n’.

// Output Format:
// Print a single integer denoting the minimal value of ‘k’.
// Constraints:
// 1 <= n <= 10^18
// Time Limit: 1 second
// Sample Input:
// 68
// Sample Output:
// 3
// Explanation:
// 68-3 = 65; 65/10 = 6; 65-6 = 59
// 59-3 = 56; 56/10 = 5; 56-5 = 51
// 51-3 = 48; 48/10 = 4; 48-4 = 44
// 44-3 = 41; 41/10 = 4; 41-4 = 37
// …..
// …..
// …..
// 6-3 = 3; 3/10 = 0; 3-0 = 3
// 3-3 = 0; 0/10 = 0; 0-0 = 0

// using iteration

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool process(ll n,ll k){
    ll N=n;
    ll sum=0;
    while(n>0&&n>=k){
        sum+=k;
        n=n-k;
        n=n-(n/10);
    }
    sum+=n;
	if(2*sum>=N){
        return true;
    }
    return false;
}

int main()
{
    // n max 10^18 , so nearly logn will work
    // logn time - bin search, logn time doing given process in ques
    // total (logn)^2 which will satisfy 10^18

    ll n;
    cin>>n;

    ll minval=1;
    ll maxval=n;
    ll overall_min=INT_MAX;
    while(minval<=maxval){
        ll mid=(minval+maxval)/2;
        if(process(n,mid)){
            maxval=mid-1;
            overall_min=mid;
        }else{
            minval=mid+1;
        }
    }
    cout<<overall_min<<endl;
	return 0;
}


// using recursion

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// ll solve_fn(ll start,ll end,ll n,ll &ans){
//     if(start>end){
//         return ans;
//     }
//     ll k=(start+end)/2; //testing for this
    
//     ll N=n;
    
//     ll sharma=0;
//     while(N>=k&&N>0){
//         sharma+=k;
//         N=N-k;
//         N=N-(N/10);
//     }
//     sharma+=N; //give remaining less than 'k' if left to sharma
    
//     if(2*sharma<n){
//         return solve_fn(k+1,end,n,ans);
//     }else{
//         //means it is a valid k
//         ans=k;
//         return solve_fn(start,k-1,n,ans);
//     }
// }

// int main()
// {
//     // n max 10^18 , so nearly logn will work
//     // logn time - bin search, logn time doing given process in ques
//     // total (logn)^2 which will satisfy 10^18
    
// 	// ios_base::sync_with_stdio(false) ; 
// 	// cin.tie(NULL) ; 
    
//     ll n;
//     cin>>n;
// 	if(n<=1){
//         cout<<n<<endl;
//         return 0;
//     }
//     cout<<solve_fn(1,n,n,n)<<endl;
// 	return 0;
// }
