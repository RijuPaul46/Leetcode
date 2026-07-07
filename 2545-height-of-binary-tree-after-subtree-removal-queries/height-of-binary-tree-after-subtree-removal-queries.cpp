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
    unordered_map<int,pair<int,int>> mp;
    vector<multiset<int>> lvl;
    int dfs(TreeNode* node,int depth){
        if(node==nullptr)return 0;
        if(lvl.size()<=depth)lvl.resize(depth+1);
        int lht=dfs(node->left,depth+1);
        int rht=dfs(node->right,depth+1);
        int mx_ht=max(lht,rht);
        lvl[depth].insert(mx_ht);
        mp[node->val].first=depth;
        mp[node->val].second=mx_ht;
        return 1+mx_ht;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
      dfs(root,0);
      int m=queries.size();
      vector<int> ans(m);
      for(int i=0;i<m;i++){
        int nd=queries[i];
        int dep=mp[nd].first;
        int ht=mp[nd].second;
        auto& all_ht=lvl[dep];
        // for(auto &x:all_ht){
        //     cout<<x<<" ";
        // }
        cout<<endl;
        auto it=prev(all_ht.end());
        int rest=0;
        if(*it==ht){
            if(it!=all_ht.begin()){
                it--;
                rest=*it;
            }
            else rest=-1;
        }
        else rest=*it;
        
        // cout<<"node="<<nd<<"depth="<<dep<<"height= "<<ht<<"rest="<<rest<<endl;
        ans[i]=dep+rest;
      } 
      return ans; 
    }
};