
#define db double
class Solution {
public:
    bool dfs(int node,int tgt,db &prdt,vector<vector<pair<db,db>>> &adj,vector<bool>&visited){
        if(node==tgt){
            return 1;
        }
        visited[node]=true;
        for(auto &[v,w]:adj[node]){
            if(!visited[v]){
                prdt*=w;
                bool ans=dfs(v,tgt,prdt,adj,visited);
                if(ans)return true;
                prdt/=w;
            }
        }
        visited[node]=false;
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& qr) {
        unordered_map<string,int>mp;
        int n=eq.size();
        vector<vector<pair<db,db>>> adj(2*n);
        int cnt=0;
        for(int i=0;i<n;i++){
            auto e=eq[i];
            string a=e[0];
            string b=e[1];
            if(!mp.count(a))
            mp[a]=cnt++;
            if(!mp.count(b))
            mp[b]=cnt++;
            int u=mp[a];
            int v=mp[b];
            adj[u].push_back(make_pair(v,val[i]));
            adj[v].push_back(make_pair(u,(db)1/val[i]));
        }
        int q=qr.size();
        vector<db> ans(q);
        for(int i=0;i<q;i++){
            if(mp.count(qr[i][0]) && mp.count(qr[i][1])){
            int src=mp[qr[i][0]];
            int dst=mp[qr[i][1]];
            
                vector<bool> visited(2*n,false);
                db prdt=1;
                bool found=dfs(src,dst,prdt,adj,visited);
                if(found)ans[i]=prdt;
                else ans[i]=-1.0;

            
            }
            else ans[i]=-1.0;

        }
        return ans;

    }
};