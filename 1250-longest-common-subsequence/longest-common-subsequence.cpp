class Solution {
public:
    int solve(int i,int j,string &t1,string &t2,vector<vector<int>>&dp){
        int m=t1.size();
        int n=t2.size();
        if(i==m || j==n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(t1[i]==t2[j]){
            return dp[i][j]=1+solve(i+1,j+1,t1,t2,dp);
        }
        return dp[i][j]=max(solve(i+1,j,t1,t2,dp),solve(i,j+1,t1,t2,dp));
    }
    int longestCommonSubsequence(string t1, string t2) {
        int m=t1.size();
        int n=t2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // memset(dp,-1,sizeof(dp));
        return solve(0,0,t1,t2,dp);
    }
};