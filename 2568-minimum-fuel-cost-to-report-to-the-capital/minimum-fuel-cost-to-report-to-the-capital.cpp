#define ll long long
class Solution {
public:
    ll cost;
    int seat;
    ll dfs(int par,int node,vector<vector<int>>& adj){
        ll ppl=1;
        for(auto &child:adj[node]){
            if(child!=par){
                ppl+=dfs(node,child,adj);
            }
        }
        cost+=(ppl+seat-1)/seat;
        return ppl;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        cost=0;
        seat=seats;
        vector<vector<int>> adj(n+1);
        for(auto &r:roads){
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }
        ll total=dfs(-1,0,adj);
        return cost-(total+seat-1)/seat;
    }
};