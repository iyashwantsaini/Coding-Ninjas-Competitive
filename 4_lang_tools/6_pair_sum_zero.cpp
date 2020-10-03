// Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
// Array A can contain duplicate elements.
// While printing a pair, print the smaller element first.
// That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.
// Input format :
// Line 1 : Integer N (Array size)
// Line 2 : Array elements (separated by space)
// Output format :
// Line 1 : Pair 1 elements (separated by space)
// Line 2 : Pair 2 elements (separated by space)
// Line 3 : and so on
// Constraints :
// 0 <= N <= 10^4
// Sample Input:
// 5
// 2 1 -2 2 3
// Sample Output :
// -2 2
// -2 2

void pairSum(int *input, int n) 
{
    //Write your code here
    //     set<pair<int,int>> s;
    // for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(i!=j){
    //             if(input[i]+input[j]==0){
    //             // 	s.insert(make_pair(i,j));
    //             // }
    //             cout<<min(input[i],input[j])<<" "<<max(input[i],input[j])<<endl;
    //             }
    //         }
    //     }
    // }
//     set<pair<int,int>>::iterator it;
//     for(it=s.begin();it!=s.end();it++){
//         cout<<min(input[it->first],input[it->second])<<" "<<max(input[it->first],input[it->second])<<endl;
//     }
    
    if(n==0||n==1) return;
    if(n==2){
        if(input[0]+input[1]==0){
            cout<<min(input[0],input[1])<<" "<<max(input[0],input[1])<<endl;
            return;
        }
    }
    map<int,int> m;
    for(int i=0;i<n;i++){
        if(input[i]==0){
            if(m[input[i]]!=0){
                for(int j=0;j<m[input[i]];j++){
                	cout<<0<<" "<<0<<endl;
            	}
            }
            m[input[i]]++;
            continue;
        }
	    m[input[i]]++;
        if(m[input[i]*-1]!=0){
            for(int j=0;j<m[input[i]*-1];j++){
                	cout<<min(input[i]*-1,input[i])<<" "<<max(input[i],input[i]*-1)<<endl;
            }
            // m[input[i]*-1]=0;
        }
    }
    // map<int,int>::iterator it;
    // for(it=m.begin();it!=m.end();it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    
}
