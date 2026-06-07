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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> ch;
        unordered_set<int> pa;
        TreeNode* root=new TreeNode();
        for(auto & arr:descriptions){
            int p=arr[0];
            pa.insert(p);
            int c=arr[1];
            ch.insert(c);
            int l=arr[2];
            TreeNode* par=mp.count(p)?mp[p]:new TreeNode(p);
            mp[p]=par;
            TreeNode* child=mp.count(c)?mp[c]:new TreeNode(c);
            mp[c]=child;
            if(l)par->left=child;
            else par->right=child;   
        }
        int rt=-1;
        for(auto & x:pa){
            if(!ch.count(x)){
                rt=x;
                break;
            }
        }
        return mp[rt];
    }
};