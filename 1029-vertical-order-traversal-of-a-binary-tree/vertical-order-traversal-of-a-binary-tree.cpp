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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        stack<tuple<TreeNode*,int,int>> st;
        st.push({root,0,0});
        while(!st.empty()){
            auto[nd,row,col]=st.top();
            st.pop();
            mp[col][row].insert(nd->val);
            if(nd->left!=nullptr){
                st.push({nd->left,row+1,col-1});
            }
            if(nd->right!=nullptr){
                st.push({nd->right,row+1,col+1});
            }
        }
        vector<vector<int>> ans(mp.size());
        int i=0;
        for(auto &a:mp){
            for(auto&x:a.second){
                for(auto &elm:x.second){
                    ans[i].push_back(elm);
                }
            }
            i++;
        }
        return ans;

    }
};