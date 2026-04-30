class Solution {
public:
    int solve(int i,int j,int k,vector<vector<vector<int>>> &dp,vector<vector<int>>& grid){
         int m=grid.size();
        int n=grid[0].size();
        if(i==m || j==n)return INT_MIN;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int pen=1;
        if(grid[i][j]==0)pen=0;
        if(k-pen<0)return dp[i][j][k]=INT_MIN;
        if(i==m-1 && j==n-1)return dp[i][j][k]=grid[i][j];
        
        int down=solve(i+1,j,k-pen,dp,grid);
        int right=solve(i,j+1,k-pen,dp,grid);
        if(max(down,right)==INT_MIN)return dp[i][j][k]=INT_MIN;
        return dp[i][j][k]=grid[i][j]+max(down,right);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        if(solve(0,0,k,dp,grid)==INT_MIN)return -1;
        return solve(0,0,k,dp,grid);
    }
};