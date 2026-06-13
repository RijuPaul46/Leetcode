class Solution {
public:
    vector<int>lvl;
    vector<vector<pair<int,int>>> adj;
    vector<vector<int>> anc;
    int max_log;
    int lca(int u,int v){
        if(lvl[u]<lvl[v])swap(u,v);
        int diff=lvl[u]-lvl[v];
        //make same level 
        for(int j=max_log;j>=0;j--){
            if((1<<j)<=diff){
                u=anc[u][j];
                diff-=(1<<j);
                }
        }
        if(u==v)return u;
        for(int j=max_log;j>=0;j--){
            if(anc[u][j]!=anc[v][j]){
                u=anc[u][j];
                v=anc[v][j];
            }
        }
        return anc[u][0];
    }
    void dfs(int node,int par,vector<vector<int>> &freq,int w){
        if(par!=-1)
        {lvl[node]=lvl[par]+1;
        freq[node]=freq[par];
        freq[node][w]++;
        anc[node][0]=par;}
        for(auto &arr:adj[node]){
            int v=arr.first;
            int wt=arr.second;
            if(v!=par)dfs(v,node,freq,wt);
        }
        
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        max_log=log2(n)+1;
        // 0 is always root
        lvl.resize(n,0);
        adj=vector(n,vector<pair<int,int>>());
        anc.resize(n,vector<int>(max_log+1,-1));
        vector<vector<int>> freq(n,vector<int>(27,0));
        for(auto &ed:edges){
            int u=ed[0];
            int v=ed[1];
            int wt=ed[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        dfs(0,-1,freq,-1);
        for(int j=1;j<max_log+1;j++){
            for(int i=0;i<n;i++){
                if(anc[i][j-1]!=-1){
                    anc[i][j]=anc[anc[i][j-1]][j-1];
                }
            }
        }
        int m=queries.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            int lc=lca(u,v);
            int total=0;
            int mx=0;
            for(int i=0;i<27;i++){
                int fr=freq[u][i]+freq[v][i]-2*freq[lc][i];
                total+=fr;
                mx=max(mx,fr);
            }
            ans[i]=total-mx;
        }
        return ans;
    }
};