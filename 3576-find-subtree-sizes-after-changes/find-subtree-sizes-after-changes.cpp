class Solution {
public:
    void solve(vector<unordered_set<int>> &adj,int node,vector<int>&par,vector<int>curr,string &s){
        char c=s[node];
        if(curr[c-'a']!=-1){
            par[node]=curr[c-'a'];
        }
        curr[c-'a']=node;
        for(auto &ch:adj[node]){
            solve(adj,ch,par,curr,s);
        }
    }
    int count(vector<int>&ans,int node,vector<unordered_set<int>> &adj){
        int cnt=1;
        for(auto &ch:adj[node]){
            cnt+=count(ans,ch,adj);
        }
        return ans[node]=cnt;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        vector<unordered_set<int>> adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].insert(i);
        }
        vector<int>curr(26,-1);
        solve(adj,0,parent,curr,s);
        vector<int>ans(n);
        adj.assign(n, unordered_set<int>());
        for(int i=1;i<n;i++){
            adj[parent[i]].insert(i);
        }
        count(ans,0,adj);
        return ans;

    }
};