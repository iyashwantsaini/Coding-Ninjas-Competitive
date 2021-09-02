// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    void dfs(TreeNode* root,map<int,vector<pair<int,int>>> &m,int indexc,int indexr){
        if(root==NULL) return;
        m[indexc].push_back({indexr,root->val});
        if(root->left){
            dfs(root->left,m,indexc-1,indexr+1);
        }
        if(root->right){
            dfs(root->right,m,indexc+1,indexr+1);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL) return {};
        map<int,vector<pair<int,int>>> m;
        dfs(root,m,0,0);
        vector<vector<int>> ans;
        for(auto i=m.begin();i!=m.end();i++){
            vector<int> temp;
            sort(i->second.begin(),i->second.end());
            for(int j=0;j<i->second.size();j++){
                temp.push_back(i->second[j].second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    
};