#define state tuple<int,int,int>
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fee) {
        int n=fee.size();
        vector<vector<pair<int,int>>> adj(n);
        for(auto &ed:edges){
            int u=ed[0];
            int v=ed[1];
            int w=ed[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<vector<int>>best(n,vector<int>(maxTime+1,INT_MAX));
        best[0][0]=fee[0];
        queue<state>q;
        //state-- node,time,cost
        q.push({0,0,fee[0]});
        while(!q.empty()){
            auto[node,time,cost]=q.front();
            q.pop();
            if(best[node][time]<cost || node==n-1)continue;
            for(auto &vec:adj[node]){
                int nd=vec.first;
                int ntm=vec.second+time;
                if(ntm>maxTime)continue;
                int ncst=fee[nd]+cost;
                if(ncst<best[nd][ntm]){
                    best[nd][ntm]=ncst;
                    q.push({nd,ntm,ncst});
                }
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<=maxTime;i++)mn=min(mn,best[n-1][i]);
        return mn==INT_MAX?-1:mn;
    }
};