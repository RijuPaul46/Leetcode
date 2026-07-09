class Solution {
public:
    vector<vector<int>> adj;
    vector<int> sz;
    int dist;
    int post(int node,int par,int lvl){
        int sm=0;
        for(auto & child:adj[node]){
            if(child!=par){
                sm+=post(child,node,lvl+1);
                dist+=lvl+1;
            }
        }
         sz[node]=sm;
         return 1+sm;
    }
    void dfs(int node,int par,vector<int>&ans,int n){
        if(node!=0){
            ans[node]=ans[par]+n-2*(sz[node])-2;
        }
        for(auto & child:adj[node]){
            if(child!=par){
                dfs(child,node,ans,n);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto &ed:edges){
            int u=ed[0];
            int v=ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        sz.resize(n);
        dist=0;
        post(0,-1,0);
        vector<int>ans(n,INT_MIN);
        //let 0 is always the first root
        queue<int>q;
        ans[0]=dist;
        dfs(0,-1,ans,n);
        return ans;

    }
};