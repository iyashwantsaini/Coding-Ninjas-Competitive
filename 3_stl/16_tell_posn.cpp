// In a class there are ‘n’ number of students. They have three different subjects: Data Structures, Algorithm Design & Analysis and Operating Systems. Marks for each subject of all the students are provided to you. You have to tell the position of each student in the class. Print the names of each student according to their position in class. Tie is broken on the basis of their roll numbers. Between two students having same marks, the one with less roll number will have higher rank. The input is provided in order of roll number.

// Input Format:
// First line will have a single integer ‘n’, denoting the number of students in the class.
// Next ‘n’ lines each will have one string denoting the name of student and three space separated integers m1, m2, m3 denoting the marks in three subjects.

// Output Format:
// Print ‘n’ lines having two values: First, the position of student in the class and second his name.
// Constraints:
// 1 <= n <= 10^5
// 0 <= m1, m2, m3 <= 100

// Sample Input:
// 3
// Mohit 94 85 97
// Shubham 93 91 94
// Rishabh 95 81 99

// Sample Output:
// 1 Shubham
// 2 Mohit
// 3 Rishabh

#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2){
    //if sum is equal sort on basis of index
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    return p1.second>p2.second;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> p; //index,marks
    map<int,string> v; //index,name
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        int sum=n1+n2+n3;
        if(n==1){
     		cout<<1<<" "<<s<<endl;
            return 0;
        }
        p.push_back(make_pair(i,sum));
        v[i]=s;
    }
    sort(p.begin(),p.end(),compare);
    for(int i=0;i<n;i++){
        cout<<i+1<<" "<<v[p[i].first]<<endl;
    }
	return 0;
}

