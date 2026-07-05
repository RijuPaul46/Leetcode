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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        TreeNode* curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                res.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* temp=curr->left;
                while(temp->right!=nullptr){
                    temp=temp->right;
                }
                temp->right=curr;
                TreeNode* left=curr->left;
                curr->left=nullptr;
                curr=left;
            }
        }
        return res;
    }
};