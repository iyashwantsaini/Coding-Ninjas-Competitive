// Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save some money out of it daily. After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos. Each of the shops of momos has a rate per momo. She visits the market and starts buying momos (one from each shop) starting from the first shop. She will visit the market for ‘q’ days. You have to tell that how many momos she can buy each day if she starts buying from the first shop daily. She cannot use the remaining money of one day on some other day. But she will save them for other expenses in the future, so, you also need to tell the sum of money left with her at the end of each day.
// Input Format:
// First line will have an integer ‘n’ denoting the number of shops in market.
// Next line will have ‘n’ numbers denoting the price of one momo of each shop.
// Next line will have an integer ‘q’ denoting the number of days she will visit the market.
// Next ‘q’ lines will have one integer ‘X’ denoting the money she saved after buying vegetables.
// Constraints:
// 1 <= n <= 10^5
// 1 <= q <= 10^5
// 1 <= X <= 10^9
// Output:
// There will be ‘q’ lines of output each having two space separated integers denoting number of momos she can buy and amount of money she saved each day.
// Sample Input:
// 4
// 2 1 6 3
// 1
// 11
// Sample Output:
// 3 2
// Explanation:
// Shreya visits the "Momos Market" for only one day. She has 11 INR to spend. She can buy 3 momos, each from the first 3 shops. She would 9 INR (2 + 1 + 6) for the same and hence, she will save 2 INR.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    int q;
    cin>>q;
    int saved[q];
    for(int i=0;i<q;i++){
        cin>>saved[i];
    }
    
    //base case shops = 1
    if(n==1){
        for(int i=0;i<q;i++){
            if(saved[i]>=price[0]){
                cout<<1<<" "<<saved[i]-price[0]<<endl;
            }else{
                cout<<0<<" "<<saved[i]<<endl;
            }
        }
        return 0;
    }
    

    // find continuous sum (prefix sum) - eg array 2,1,3,4 -> cont sum => 2 ,3 ,6 ,10
    for(int i=1;i<n;i++){
        price[i]+=price[i-1];
    }
    
    //for every saved money find its posn in price continuous sum using binary search
    for(int i=0;i<q;i++){
        
        int num_momos=0; //total momos eaten that day
    	int saved_money=0; //money saved after eating momos
        
        int money=saved[i];
        
        //check if this money is less than required at first shop
        if(money<price[0]){
            cout<<0<<" "<<money<<endl;
            continue;
        }
        
        if(money==price[0]){
            cout<<1<<" "<<money-price[0]<<endl;
            continue;
        }
        
        //check if this money is greater than all sums ie. last index
        if(money>=price[n-1]){
            //bought 1 momo from each shop
            cout<<n<<" "<<money-price[n-1]<<endl;
            continue;
        }
        
        int minindex=0;
        int maxindex=n-1;
        
        while(minindex<=maxindex){
            int mid=minindex+(maxindex-minindex)/2;
            if(price[mid]>money){
                maxindex=mid-1;
            }else if(price[mid]<money){
                num_momos=mid+1;
            	minindex=mid+1;
                if(price[mid+1]>money&&mid<n-1){
                    break;
                }
            }else{
                num_momos=mid+1;
                break;
            }
        }
        cout<<num_momos<<" "<< money-price[num_momos-1] <<endl;
    }
    
	return 0;
}
