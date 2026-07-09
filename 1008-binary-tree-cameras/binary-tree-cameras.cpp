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
    // int solve(int state,TreeNode*node){
    //     if(!node)return 0;
    //     int keep=1+solve(1,node->left)+solve(1,node->right);
    //     if(state==1){
    //         //already covered by someone else
            
    //         int skip=solve(0,node->left)+solve(0,node->right);
    //         return min(keep,skip);
    //     }
    //     return keep;
       
    // }
    unordered_map<TreeNode*,vector<int>> dp;
    int solve(int state,TreeNode* node){
        if(!node)return 0;
        if(!dp.count(node)){
            dp[node]={-1,-1,-1};
        }
        if(dp[node][state]!=-1)return dp[node][state];
        if(state==0){
            //0-parent has camera;
            //1- parent is covered by someone else may be parent or other child
            int keep=1+solve(0,node->left)+solve(0,node->right);
            int skip=solve(1,node->left)+solve(1,node->right);
            return dp[node][state]=min(keep,skip);
        }
        else if(state==1){
            // parent is covered by some one else may be grand par or other child
            int keep=1+solve(0,node->left)+solve(0,node->right);
            // parent to eke cover korte parbe na ... one of the child should cover it 
            if(!node->left && !node->right)return keep;
            int opt1=INT_MAX,opt2=INT_MAX;
            if(node->left){
            opt1=solve(2,node->left)+solve(1,node->right);
            }
            if(node->right){
            opt2=solve(1,node->left)+solve(2,node->right);
            }
            int skip=min(opt1,opt2);
            return dp[node][state]=min(keep,skip);
        }
        // state==2 we must keep a camera 
        return dp[node][state]=1+solve(0,node->left)+solve(0,node->right);
    }
    int minCameraCover(TreeNode* root) {
        if(!root->left && !root->right)return 1;
        return solve(1,root);
    }
};