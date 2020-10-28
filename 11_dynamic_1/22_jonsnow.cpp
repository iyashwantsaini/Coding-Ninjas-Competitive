/*
Jon Snow now has to fight with White Walkers. He has n rangers, each of which has his own strength. Also Jon Snow has his favourite number x. Each ranger can fight with a white walker only if the strength of the white walker equals his strength. He however thinks that his rangers are weak and need to improve. Jon now thinks that if he takes the bitwise XOR of strengths of some of rangers with his favourite number x, he might get soldiers of high strength. So, he decided to do the following operation k times:
Arrange all the rangers in a straight line in the order of increasing strengths.
Take the bitwise XOR of the strength of each alternate ranger with x and update it's strength.

Suppose, Jon has 5 rangers with strengths [9, 7, 11, 15, 5] and he performs the operation 1 time with x = 2. He first arranges them in the order of their strengths, [5, 7, 9, 11, 15]. Then he does the following:
The strength of first ranger is updated to 5 xor 2, i.e. 7.
The strength of second ranger remains the same, i.e. 7.
The strength of third ranger is updated to 9 xor 2, i.e. 11.
The strength of fourth ranger remains the same, i.e. 11.
The strength of fifth ranger is updated to 15 xor 2, i.e. 13.
The new strengths of the 5 rangers are [7, 7, 11, 11, 13]
Now, Jon wants to know the maximum and minimum strength of the rangers after performing the above operations k times. He wants your help for this task. Can you help him?

Input
First line consists of three integers n, k, x (1 ≤ n ≤ 10^5, 0 ≤ k ≤ 10^5, 0 ≤ x ≤ 10^3) — number of rangers Jon has, the number of times Jon will carry out the operation and Jon's favourite number respectively.
Second line consists of n integers representing the strengths of the rangers a1, a2, ..., an (0 ≤ ai ≤ 10^3).

Output
Output two integers, the maximum and the minimum strength of the rangers after performing the operation k times.

Sample Input
5 1 2
9 7 11 15 5
Sample Output
13 7

In
10 1 8
1 2 3 1 4 2 1 3 2 8
Out
12 1

In
10 2 8
1 2 3 1 4 2 1 3 2 8
Out
12 0

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int n,k,x;
    cin>>n>>k>>x;
    int s[n+1]{};
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

    int freq[1024+1]{};
    
    // ATQ - n times do this op
    // step 1 - sort the array in inc order
    // step 2 - apply xor alternatively
    // step 3 - resort array

    // instead of applying xor and sorting again and again - use frequency array
    // save counts of all elements in freq array
    for(int i=0;i<n;i++){
        freq[s[i]]++;
    }

    // for(int i=0;i<=1024;i++){
    //     if(freq[i]!=0){
    //         cout<<i<<" - "<<freq[i]<<" | ";
    //     }
    // }cout<<"\n";

    // apply xor to each element based on previously covered elements
    // if previously odd number of digits are covered - take xor of half of current element count
    // if previously even number of digits are covered - take xor of (half+1) of current element count
    int tillnow=0;
    
    int num_k=k;
    while(k--){
        int newfreq[1024+1]{};
        tillnow=0;
        for(int i=0;i<=1024;i++){
            // till now even numbers are covered
            if(tillnow%2==0){   
                int xor_result=i^x;
                // cout<<xor_result<<endl;
                // save half+1 elements to new index
                tillnow+=freq[i];
                if(freq[i]>0){
                    if(freq[i]%2!=0){
                        newfreq[xor_result]+=(freq[i]/2)+1;
                        freq[i]-=(freq[i]/2)+1;
                    }else{
                        newfreq[xor_result]+=(freq[i]/2);
                        freq[i]-=(freq[i]/2);
                    }
                }
            }
            // odd are covered
            else{
                int xor_result=i^x;
                // save half elements to new index
                tillnow+=freq[i];
                if(freq[i]>0){
                    newfreq[xor_result]+=freq[i]/2;
                    freq[i]-=freq[i]/2;
                }  
            }
        }

        for(int x=0;x<=1024;x++){
            freq[x]+=newfreq[x];
        }

        // for(int x=0;x<=1024;x++){
        //     if(freq[x]!=0){
        //         cout<<x<<" - "<<freq[x]<<" | ";
        //     }
        // }cout<<"\n";
        
    }

    int minnum,maxnum;
    for(int i=0;i<=1024;i++){
        if(freq[i]!=0){
            minnum=i;
            break;
        }
    }
    for(int i=1024;i>=0;i--){
        if(freq[i]!=0){
            maxnum=i;
            break;
        }
    }
    cout<<maxnum<<" "<<minnum<<endl;
    return 0;
}

