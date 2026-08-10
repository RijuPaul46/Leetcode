class Solution {
public:
    int dp[100001][2];
    int solve(int turn,int n){
        if(n==0)return false;
        if(dp[n][turn]!=-1)return dp[n][turn];
        int ans=0;//false
        int nturn=1;
        if(turn==1)nturn=0;
        for(int i=1;i*i<=n;i++){
            ans|=(!solve(nturn,n-(i*i)));
        }
        return dp[n][turn]=ans;
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n);
    }
};