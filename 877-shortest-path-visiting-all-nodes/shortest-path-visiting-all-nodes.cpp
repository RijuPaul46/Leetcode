class Solution {
public:
    // int total_edge;
    // int dp[14][(1<<13)];
    // int solve(int from,int cnt,int mask,int node,vector<vector<int>>& graph){
    //     int n=graph.size();
    //     if(cnt> 2*total_edge)return INT_MAX;
    //     mask=mask|(1<<node);
    //     if(mask==((1<<n)-1))return cnt;
    //     dp[node][from]=1;
    //     int ans=INT_MAX;
    //     for(auto &neigh:graph[node]){
    //         if(!dp[neigh][node])
    //         ans=min(ans,solve(node,cnt+1,mask,neigh,graph));
    //     }
    //     dp[node][from]=0;
    //     return ans;
    // }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int cnt=0;
        int finalState=(1<<n)-1;
        
        //start bfs from all the node because we can start from any node ...
        //bfs will always decide the shortest path to reach the final state
        // once we reached some state (node,mask) we will store it ...
        // as it is bfs .. so later coming to same state will never give me shortest path because we have reached the same state before with less number of edge visit .... the first state to reach the final state is our answer .. because it is the minimum
        set<pair<int,int>> visited;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            q.push({i,(1<<i)});
            visited.insert({i,(1<<i)});
        }
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto [nd,mask]=q.front();
                if(mask==finalState)return cnt;
                q.pop();
                for(auto &neigh:graph[nd]){
                    int nmask=mask|(1<<neigh);
                    if(!visited.count({neigh,nmask})){
                        q.push({neigh,nmask});
                        visited.insert({neigh,nmask});
                    }
                }
            }
            cnt++;
        }

        return -1;

    }
};