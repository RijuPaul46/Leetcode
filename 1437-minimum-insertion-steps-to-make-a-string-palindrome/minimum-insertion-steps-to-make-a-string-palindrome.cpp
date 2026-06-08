class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,string &s){
        if(i>=j)return 0;
        auto &ref=dp[i][j];
        if(ref!=-1)return ref;
        if(s[i]!=s[j]){
            int left=1+solve(i,j-1,s);
            int right=1+solve(i+1,j,s);
            return ref=min(left,right);
        }
        return ref=solve(i+1,j-1,s);
    }
    int minInsertions(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
       return solve(0,n-1,s); 
    }
};