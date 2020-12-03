/*
Pandora has declared war against NinjaLand. The brave soldiers of NinjaLand have been defending their country against attacks for a long time. There is a shortage of food amongst the citizens. The governor of NinjaLand has ordered the army to drop food crates via helicopters.
Each helipad in NinjaLand is located at the nodes of a Generic Tree. Due to constant attacks from Pandora, the dispatched helicopter cannot stay over civilian sky for long or it will be shot down by the enemy. The pilot has decided to cover the entire Helipad Tree with the least number of landings. Each Helipad node can cover the node connected to it by one edge.
If the number of landings exceed a certain number, the helicopter will be shot down by Pandora.
Since it is a high pressure situation, you have to help the pilot figure out the minimum number of times he needs to land his helicopter in order to cover the entire Helipad Tree without being shot and complete its mission (if possible).
Input Format:
We need to input two things- Tree nodes and maximum allowed landings.
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
Since data of each node is irrelevant, it will be taken as 1, representing that the node exists.
Second line of each test case will contain an integer K representing the maximum allowed landings.
Constraints:
Time Limit: 1 sec
Output Format:
If it is possible to complete the mission with <= K landings, print the minimum number of landings required to completely cover the Helipad Tree and the phrase “Mission Successful” , otherwise print the minimum number of landings required to completely cover the Helipad Tree and the phrase “Mission Unsuccessful”.
Sample Input 1:
1 3 1 1 1 2 1 1 0 0 0 0
3
Sample Output 1:
2 Mission Successful
Explanation:
For the given input the tree formed is given below, which can be covered with minimum 2 landings, which is less than the maximum allowed landings.
Alt Text

Sample Input 2:
1 3 1 1 1 2 1 1 1 1 3 1 1 1 0 0 2 1 1 0 0 0 0 0
2
Sample Output 2:
3 Mission Unsuccessful
Explanation:
For the given input the tree formed is given below, which can be covered with minimum 3 landings, which is more than the maximum allowed landings.
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    // write your code
    int n,l;
    cin>>n>>l;
    
    return 0;
}