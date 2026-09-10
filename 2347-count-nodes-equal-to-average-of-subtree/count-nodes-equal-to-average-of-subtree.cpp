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
    int cnt;
    pair<int,int> solve(TreeNode* node){
        if(node==nullptr)return {0,0};
        auto [ls,ln]=solve(node->left);
        auto [rs,rn]=solve(node->right);
        int val=node->val;
        if(val==(ls+rs+val)/(ln+rn+1)){cnt++;}
        return {ls+rs+val,ln+rn+1};
    }
    int averageOfSubtree(TreeNode* root) {
        cnt=0;
        solve(root);
        return cnt;
    }
};