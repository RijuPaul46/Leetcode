#define ll long long
class Solution {
public:
    const ll inf=LLONG_MAX;
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<tuple<ll,ll,ll>>> adj(n);
        for(auto &road:roads){
            ll u=road[0];
            ll v=road[1];
            ll c=road[2];
            ll tx=road[3];
            adj[u].push_back({v,c,c*tx});
            adj[v].push_back({u,c,c*tx});
        }
        vector<vector<ll>> c0(n,vector<ll>(n,inf));//empty without tax
        vector<vector<ll>> c1(n,vector<ll>(n,inf));// cost with tax
        auto com0=[&](tuple<ll,ll,ll>& t1,tuple<ll,ll,ll> &t2){
            return get<1>(t1)>get<1>(t2);
        };
        auto com1=[&](tuple<ll,ll,ll> t1,tuple<ll,ll,ll> t2){
            return get<2>(t1)>get<2>(t2);
        };
        for(int src=0;src<n;src++){
            priority_queue<tuple<ll,ll,ll>,
                vector<tuple<ll,ll,ll>>,
                decltype(com0)> pq0(com0);
            priority_queue<tuple<ll,ll,ll>,
                vector<tuple<ll,ll,ll>>,
                decltype(com1)> pq1(com1);
            vector<bool>vis0(n);
            vector<bool>vis1(n);
            pq0.push({src,0,0});
            pq1.push({src,0,0});
            int proc=0;
            while(!pq0.empty()&& proc<n){
                auto tp=pq0.top();
                ll node=get<0>(tp);
                ll cost=get<1>(tp);
                pq0.pop();
                if(vis0[node])continue;
                proc++;
                vis0[node]=true;
                c0[src][node]=min(c0[src][node],cost);
                for(auto & t:adj[node]){
                    ll neigh=get<0>(t);
                    ll ncost=c0[src][node];
                    if(c0[src][node]!=inf)
                    ncost=c0[src][node]+get<1>(t);
                    if(!vis0[neigh] && ncost<c0[src][neigh]){
                        c0[src][neigh]=ncost;
                        pq0.push({neigh,ncost,get<2>(t)});
                    }
                }
            }
            proc=0;
            while(!pq1.empty()&& proc<n){
                auto tp=pq1.top();
                ll node=get<0>(tp);
                ll cost=get<2>(tp);
                pq1.pop();
                if(vis1[node])continue;
                vis1[node]=true;
                proc++;
                
                c1[src][node]=min(c1[src][node],cost);
                for(auto & t:adj[node]){
                    ll neigh=get<0>(t);
                    ll ncost=c1[src][node];
                    if(c1[src][node]!=inf)
                    ncost=c1[src][node]+get<2>(t);
                    if(!vis1[neigh] && ncost<c1[src][neigh]){
                        c1[src][neigh]=ncost;
                        pq1.push({neigh,get<1>(t),ncost});
                    }
                }
                
            }

        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ll price=prices[i];
            for(int j=0;j<n;j++){
                if(c0[i][j]!=inf && c1[j][i]!=inf){
                ll cost=c0[i][j]+prices[j]+c1[j][i];
                price=min(price,cost);
            }}
            ans[i]=(int)price;
        }
        return ans;



    }
};