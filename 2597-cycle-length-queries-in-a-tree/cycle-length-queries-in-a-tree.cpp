class Solution {
public:
    // int mx_log;
    // vector<vector<int>> par;
    // int lca(int u,int v){
    //         if(u==v)return u;
    //         if(u<v)swap(u,v);
    //         int diff=log2(u)-log2(v);
    //         for(int i=mx_log;i>=0;i--){
    //             if(diff==0)break;
    //             else if((1<<i)<=diff){
    //                 u=par[u][i];
    //                 diff-=(1<<i);
    //             }
    //         }
    //         //they are at same level now
    //         for(int i=mx_log;i>=0;i--){
    //             if(par[u][i]!=par[v][i]){
    //                 u=par[u][i];
    //                 v=par[v][i];
    //             }
    //         }
    //         return par[u][0];
    // }
    int lca(int u,int v){
        while(u!=v){
            if(u<v)v>>=1;
            else u>>=1;
        }
        return u;
    }
    int depth(int i){
        int d=0;
        while(i>1){i>>=1;d++;}
        return d;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        // mx_log=n+1;
        // par=vector<vector<int>>((1<<n),vector<int>(mx_log+1));
        // par[1][0]=0;
        // for(int i=2;i<(1<<n);i++){
        //     par[i][0]=i/2;
        // }
        // for(int i=1;i<(1<<n);i++){
        //     for(int j=1;j<=mx_log;j++){
        //         par[i][j]=par[par[i][j-1]][j-1];
        //     }
        // }
        int q=queries.size();
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            int lc=lca(u,v);
            ans[i]=1+depth(u)+depth(v)-2*depth(lc);
            
        }
        return ans;

    }
};