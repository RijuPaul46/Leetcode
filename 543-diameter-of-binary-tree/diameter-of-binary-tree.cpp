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
    int dfs(TreeNode* node,int &dia){
        if(node==nullptr)return 0;
        int left=dfs(node->left,dia);
        int right=dfs(node->right,dia);
        int diameter=1+left+right;
        dia=max(dia,diameter);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=1;
        dfs(root,dia);
        return dia-1;
    }
};