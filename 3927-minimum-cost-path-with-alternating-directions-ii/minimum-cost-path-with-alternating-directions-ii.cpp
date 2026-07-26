#define ll long long
class Solution {
public:
    vector<vector<vector<ll>>> dp;
    ll solve(int i,int j,int parity,int m, int n, vector<vector<int>>& waitCost){
        if(i==m-1 && j==n-1)return 1ll*m*n;
        auto &ref=dp[i][j][parity];
        if(ref!=-1)return ref;
        ll wait=(i+1)*(j+1);
        if(parity==0)wait+=waitCost[i][j];
        //right 
        ll r=LLONG_MAX;
        if(j+1<n)r=solve(i,j+1,0,m,n,waitCost);
        ll d=LLONG_MAX;
        if(i+1<m)d=solve(i+1,j,0,m,n,waitCost);
        ll mn=min(r,d);
        return ref=wait+mn;
    }
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        dp.resize(m,vector<vector<ll>>(n,vector<ll>(2,-1)));
        return solve(0,0,1,m,n,waitCost);
    }
};