class Solution {
public:
    int find_par(int u,vector<int>&par){
        if(par[u]==u)return u;
        return par[u]=find_par(par[u],par);
    }
    void uni(int u,int v,vector<int>&par){
        int paru=find_par(u,par);
        int parv=find_par(v,par);
        if(paru!=parv){
            par[paru]=parv;
            return;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n);
        vector<int>par(n);
        for(int i=0;i<n;i++)par[i]=i;
        for(auto &ed:edges){
            int u=ed[0];
            int v=ed[1];
            uni(u,v,par);
            indegree[u]++;
            indegree[v]++;
        }
        for(int i=0;i<n;i++){
            find_par(i,par);
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[par[i]].push_back(i);
        }
        int cnt=0;
        for(auto &pr:mp){
            int nd=pr.first;
            auto &arr=pr.second;
            int sz=arr.size();
            bool flag=true;
            for(auto &x:arr){
                if(indegree[x]!=sz-1){flag=false;break;}
            }
            if(flag)cnt++;
        }
        return cnt;
    }
};