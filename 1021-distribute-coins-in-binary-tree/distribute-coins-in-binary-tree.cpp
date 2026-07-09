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
    int cost;
    int solve(TreeNode* node){
        if(!node)return 0;
        int left=solve(node->left);
        int right=solve(node->right);
        cost+=abs(left)+abs(right);
        int avail=node->val-1;
        return avail+right+left;
    }
    int distributeCoins(TreeNode* root) {
        cost=0;
        int x=solve(root);
        return cost;
    }
};