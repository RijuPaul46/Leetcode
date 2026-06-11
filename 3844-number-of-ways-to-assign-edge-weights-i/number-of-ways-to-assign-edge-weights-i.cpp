#define ll long long
class Solution {
public:
    const ll m=1e9+7;
    ll f[100007];
    ll pow(ll x,ll r){
        if(r==0)return 1;
        ll ans=pow((x*x)%m,r/2)%m;
        if(r%2==1)return (x*ans)%m;
        return ans;
    }
    ll modInv(ll n){
        return pow(n,m-2)%m;
    }
    ll depth(vector<vector<ll>> &adj, ll node,vector<bool>&visited){
        ll d=0;
        for(auto & n:adj[node]){
            if(!visited[n]){
                visited[n]=true;
            d=max(d,1+depth(adj,n,visited));
            visited[n]=false;
            }
        }
        return d;
    }
    ll C(ll n,ll r){
        return (f[n]%m*((modInv(f[r])*modInv(f[n-r]))%m))%m;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<ll>> adj(n+2);
        vector<bool>visited(n+2);
        for(auto& edg:edges){
            adj[edg[0]].push_back(1ll*edg[1]);
            adj[edg[1]].push_back(1ll*edg[0]);
        }
        f[0]=1;
        for(int i=1;i<=n+2;i++){
            f[i]=(1ll*f[i-1]*i)%m;
        }
        ll way=0;
        visited[1]=true;
        ll d=depth(adj,1,visited);
        for(int i=1;i<=d;i+=2){
            way=(way+C(d,i))%m;
        }
        return (int)way;

    }
};