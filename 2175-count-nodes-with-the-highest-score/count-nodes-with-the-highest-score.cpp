#define ll long long
class Solution {
public:
    int post(int node,vector<vector<int>>& adj,vector<pair<int,int>> &sz){
        int left=0;
        int right=0;
        if(adj[node].size()==1)left=post(adj[node][0],adj,sz);
        else if(adj[node].size()==2){
            left=post(adj[node][0],adj,sz);
            right=post(adj[node][1],adj,sz);
        }
        sz[node].first=left;
        sz[node].second=right;
        return 1+left+right;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            adj[parents[i]].push_back(i);
        }
        vector<pair<int,int>> sz(n);
        post(0,adj,sz);
        map<ll,ll>mp;
        for(int i=0;i<n;i++){
            int left=sz[i].first;
            int right=sz[i].second;
            int rem=n-left-right-1;
            ll ans=1;
            if(left!=0)ans*=left;
            if(right!=0)ans*=right;
            if(rem!=0)ans*=rem;
            mp[ans]++;
        }
        auto it=prev(mp.end());
        return (int)it->second;
    }
};