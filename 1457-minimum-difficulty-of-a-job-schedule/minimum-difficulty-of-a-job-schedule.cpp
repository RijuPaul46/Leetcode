#define ll long long
class Solution {
public:
    ll solve(int i,int d,vector<int>& jd,vector<vector<ll>> &dp){
        int n=jd.size();
        if(i>=n){
            if(d==0)return 0;
            else return 1ll*INT_MAX;
        }
        if(d<=0 && i<n)return 1ll*INT_MAX;
        if(dp[i][d]!=-1)return dp[i][d];
        ll mx=jd[i];
        ll ans=1ll*INT_MAX;
        for(int j=i;j<n;j++){
            mx=max(mx,1ll*jd[j]);
            ans=min(ans,mx+solve(j+1,d-1,jd,dp));
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        vector<vector<ll>> dp(n,vector<ll>(d+1,-1));
        int ans=solve(0,d,jobDifficulty,dp);
        int rt= ans>=INT_MAX?-1:ans;
        return rt;
    }
};