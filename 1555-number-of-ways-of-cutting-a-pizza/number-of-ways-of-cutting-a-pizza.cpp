#define ll long long
class Solution {
public:
    const ll mod=1e9+7;
    ll solve(int l,int u,vector<string>& pizza,int cut, vector<vector<vector<ll>>> &dp,vector<vector<ll>> &cnt){
        if(cut==0)return 1;
        if(cnt[u][l]==0)return 0;
        if(dp[u][l][cut]!=-1)return dp[u][l][cut];
        ll ans=0;
        int m=pizza.size();
        int n=pizza[0].size();
        //horizontal cut
        for(int i=u;i<m-1;i++){
            //if valid cut
            if(cnt[i+1][l]!=cnt[u][l] && cnt[i+1][l]>0){
                ans=(ans+solve(l,i+1,pizza,cut-1,dp,cnt))%mod;
            }
        }
        //vertical cut
        for(int i=l;i<n-1;i++){
            if(cnt[u][l]!=cnt[u][i+1] && cnt[u][i+1]>0){
                ans=(ans+solve(i+1,u,pizza,cut-1,dp,cnt))%mod;
            }
        }
        return dp[u][l][cut]=ans;

    }
    int ways(vector<string>& pizza, int k) {
        int m=pizza.size();
        int n=pizza[0].size();
        vector<vector<ll>> cnt(m,vector<ll>(n,0));
        vector<vector<vector<ll>>> dp(m,vector<vector<ll>>(n,vector<ll>(k,-1)));
        cnt[m-1][n-1]=pizza[m-1][n-1]=='A';
        for(int i=n-2;i>=0;i--){
            cnt[m-1][i]=cnt[m-1][i+1]+(pizza[m-1][i]=='A');
        }
        for(int i=m-2;i>=0;i--){
            cnt[i][n-1]=cnt[i+1][n-1]+(pizza[i][n-1]=='A');
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                cnt[i][j]=(pizza[i][j]=='A')+cnt[i][j+1]+cnt[i+1][j]-cnt[i+1][j+1];
            }
        }
        if(k==1){
            return cnt[0][0]>0;
        }
        return (int)solve(0,0,pizza,k-1,dp,cnt);

    }
};