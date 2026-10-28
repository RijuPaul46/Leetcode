class Solution {
public:
    // void solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){

    // }
    //max xor value can be 1024 
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(1024,0)));
        dp[0][0][grid[0][0]]=1;
        for(int i=1;i<n;i++){
            for (int j=0;j<1024;j++){
                if(dp[0][i-1][j]){
                int a=j^grid[0][i];
                dp[0][i][a]=1;
                }
            }
            
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<1024;j++){
                if(dp[i-1][0][j]){
                    int a=j^grid[i][0];
                    dp[i][0][a]=1;
                }
            }
            
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                for(int k=0;k<1024;k++){
                    if(dp[i][j-1][k] || dp[i-1][j][k]){
                        int a=k^grid[i][j];
                        dp[i][j][a]=1;
                    }
                }
            }
        }
        for(int k=0;k<1024;k++){
            if(dp[m-1][n-1][k])return k;
        }
        return 0;
    }
};