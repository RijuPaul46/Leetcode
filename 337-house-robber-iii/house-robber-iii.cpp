/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* node,bool canTake,unordered_map<TreeNode*,vector<int>>&dp){
        if(node==nullptr)return 0;
        // skip this node
        if(dp.find(node)==dp.end()){
            dp[node]=vector<int>(2,-1);
        }
        if(dp[node][canTake]!=-1)return dp[node][canTake];
        int skip=solve(node->left,true,dp);
        skip+=solve(node->right,true,dp);
        int take=0;
        if(canTake){take+=node->val;take+=solve(node->left,false,dp);
        take+=solve(node->right,false,dp);}
        return dp[node][canTake]=max(take,skip);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,vector<int>>dp;
        return solve(root,true,dp);
    }
};