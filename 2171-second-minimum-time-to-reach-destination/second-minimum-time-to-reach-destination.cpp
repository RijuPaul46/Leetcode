class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<pair<int,int>> best(n+1);
        for(int i=1;i<=n;i++){
            best[i].first=INT_MAX;
            best[i].second=INT_MAX;
        }
        vector<vector<int>>adj(n+1);
        for(auto &ed:edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        while(!pq.empty()){
            auto [t,u]=pq.top();
            pq.pop();
            if(t>best[u].second)continue;
            if(u==n){
                if(best[n].second!=INT_MAX)break;
            }
            int slot=t/change;
            int wait=change*(slot+1)-t;
            if(slot%2==1)t+=wait;
            for(auto &ch:adj[u]){
                int nt=t+time;
                if(nt<best[ch].first){
                    best[ch].second=best[ch].first;
                    best[ch].first=nt;
                    pq.push({nt,ch});
                }
                else if(nt>best[ch].first && nt<best[ch].second){
                    best[ch].second=nt;
                    pq.push({nt,ch});
                }
            }
        }
        return best[n].second;
    }
};