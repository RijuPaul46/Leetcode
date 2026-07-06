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
 #define ll unsigned long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* ,ll>> q;
        q.push({root,0});
        int width=1;
        while(!q.empty()){
            int sz=q.size();
            int mx=0,mn=0;
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                if(i==0)mn=it.second;
                if(i==sz-1)mx=it.second;
                TreeNode* nd=it.first;
                if(nd->left!=nullptr)q.push({nd->left,2*it.second+1});
                if(nd->right!=nullptr)q.push({nd->right,2*it.second+2});
            }
            width=max(width,mx-mn+1);
        }
        return width;
    }
};