class Solution {
public:
    int dp[100][100][400];
    bool solve(vector<vector<char>>& grid,int r,int c,int score){
        int m=grid.size();
        int n=grid[0].size();
        int mask=score+200;
        int nscore=score+(grid[r][c]=='('?1:-1);
        
        if(r==m-1 && c==n-1){
            return nscore==0;
        }
        if(nscore<0)return false;
        auto &ref=dp[r][c][mask];
        if(ref!=-1)return ref;
        bool right=false;
        if(c+1<n)right=solve(grid,r,c+1,nscore);
        if(right)return ref=right;
        bool down=false;
        if(r+1<m)down=solve(grid,r+1,c,nscore);
        return ref=down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0]==')')return false;
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,0);
    }
};