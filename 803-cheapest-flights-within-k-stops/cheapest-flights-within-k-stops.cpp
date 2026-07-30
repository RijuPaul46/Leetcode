#define state pair<int,int>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> best(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        for(auto &flt:flights){
            adj[flt[0]].push_back({flt[1],flt[2]});
        }
        best[src]=0;
        // tuple of price,stop,node.... 
        queue<state> pq;
        pq.push({0,src});
        int stop=0;
        while(!pq.empty() && stop<=k){
            int sz=pq.size();
            for(int i=0;i<sz;i++){
            auto [prc,node]=pq.front();
            pq.pop();
            if(node==dst)continue;//stale entry
            for(auto &neig:adj[node]){
                auto [v,w]=neig;
                if(prc+w<best[v]){
                    best[v]=prc+w;
                    pq.push({prc+w,v});
                }
            }
            }
            stop++;
        }
        return best[dst]==INT_MAX?-1:best[dst];
    }
};