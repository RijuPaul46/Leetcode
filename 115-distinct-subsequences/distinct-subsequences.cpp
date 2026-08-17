class Solution {
public:
    int solve(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        int n=s.size();
        int m=t.size();
        if(j==m)return 1;
        if(i==n)return 0;
        auto &ref=dp[i][j];
        if(ref!=-1)return ref;
        if(s[i]!=t[j]){
            return ref=solve(i+1,j,s,t,dp);
        }
        int take=solve(i+1,j+1,s,t,dp);
        int skip=solve(i+1,j,s,t,dp);
        return ref=take+skip;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,s,t,dp);
    }
};
