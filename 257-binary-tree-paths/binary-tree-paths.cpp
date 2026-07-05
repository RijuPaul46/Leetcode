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
    void dfs(string& path,vector<string> &ans,TreeNode* node){
        if(node->left==nullptr && node->right==nullptr){
            ans.push_back(path+to_string(node->val));
            return;
        }
        string str=to_string(node->val);
        path=path+str+"->";
        int sz=str.size()+2;
        if(node->left!=nullptr)
        dfs(path,ans,node->left);
        if(node->right!=nullptr)
        dfs(path,ans,node->right);
        for(int i=0;i<sz;i++)
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path="";
        vector<string>ans;
        if(root==nullptr)return ans;
        dfs(path,ans,root);
        return ans;
    }
};