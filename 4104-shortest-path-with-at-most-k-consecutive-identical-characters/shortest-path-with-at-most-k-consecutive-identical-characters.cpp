class Solution {
public:
    // do dijkstra ... if streak>k remove the node ... else we reach goal with min weight
    #define state tuple<int,int,int>
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &ed:edges){
            int u=ed[0];
            int v=ed[1];
            int w=ed[2];
            adj[u].push_back({v,w});
        }
        vector<vector<int>> visited(n,vector<int>(k+1,INT_MAX));
        priority_queue<state,vector<state>,greater<state>> pq;
        pq.push(make_tuple(0,1,0));
        visited[0][1]=0;
        while(!pq.empty()){
            auto [wt,streak,nd]=pq.top();
            pq.pop();
            if(nd==n-1)return wt;
            for(auto &[ch,w]:adj[nd]){
                int nstreak=((labels[nd]==labels[ch])? streak+1 : 1);
                if(nstreak<=k && visited[ch][nstreak]> (wt+w)){
                    visited[ch][nstreak]=(wt+w);
                    pq.push(make_tuple(wt+w,nstreak,ch));
                }
            }
        }
        return -1;
    }
};