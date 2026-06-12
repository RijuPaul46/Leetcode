#define ll long long
class Solution {
public:
    const ll m=1e9+7;
    //duto table 1 ta -- lvl er 2. ancestor -- in pow of 2//
    vector<int> lvl;
    vector<vector<int>> anc;
    int max_log;
    int lca(int u,int v){
        // u is deeper always
        if(u==1 || v==1)return 1; 
        if(lvl[u]<lvl[v])swap(u,v);
        int diff=lvl[u]-lvl[v];
        for(int j=max_log;j>=0;j--){
            if(diff==0)break;
            if((1<<j)<=diff){
                u=anc[u][j];
                diff-=(1<<j);
            }
        }
        //both became same level
        // now find ancestor
        if(u==v)return u;
        for(int j=max_log;j>=0;j--){
            if(anc[u][j]!=-1 && anc[u][j]!=anc[v][j]){
                u=anc[u][j];
                v=anc[v][j];
            }
        }
        // they end just below the lca
        return anc[u][0];
    }
    void dfs(int n,vector<vector<int>>&adj,int level,int par){
        anc[n][0]=par;
        lvl[n]=level;
        for(auto & neigh:adj[n]){
            if(neigh!=par){
                dfs(neigh,adj,level+1,n);
            }
        }
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size()+1;
        lvl=vector<int>(n+1,0);
        int mx_j=log2(n)+1;
        max_log=mx_j;
        anc=vector(n+1,vector<int>(mx_j+1,0));
        vector<vector<int>> adj(n+1);
        for(auto & edg:edges){
            int u=edg[0];
            int v=edg[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,adj,0,0);
        for(int j=1;j<=max_log;j++){
            for(int i=1;i<=n;i++){
                if(anc[i][j-1]!=-1)
                anc[i][j]=anc[anc[i][j-1]][j-1];
            }
        }
        int q=queries.size();
        vector<int>ans(q);
        vector<ll> ways(n+1);
        ways[1]=1;
        for(int i=2;i<=n;i++){
            ways[i]=(ways[i-1]*2)%m;
        }
        for(int i=0;i<q;i++){
            auto &qr=queries[i];
            int u=qr[0];
            int v=qr[1];
            int l=lca(u,v);
            int len=lvl[u]+lvl[v]-2*lvl[l];
            ans[i]=(int)ways[len];
        }
        return ans;
    }
};