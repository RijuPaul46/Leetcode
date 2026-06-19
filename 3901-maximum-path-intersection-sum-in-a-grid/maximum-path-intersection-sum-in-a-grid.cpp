class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxi=INT_MIN;
        vector<vector<int>> dp0(m,vector<int>(n));
        vector<vector<int>> dp1(m,vector<int>(n));

        for(int i=0;i<m;i++){   
            dp0[i][0]=grid[i][0];        
            for(int j=1;j<n;j++){
                dp0[i][j]=max(grid[i][j]+grid[i][j-1],dp0[i][j-1]+grid[i][j]);
                maxi=max(dp0[i][j],maxi);
            }
        }
        
        for(int j=0;j<n;j++){
            dp1[0][j]=grid[0][j];
            for(int i=1;i<m;i++){
                dp1[i][j]=max(grid[i-1][j],dp1[i-1][j])+grid[i][j];
                maxi=max(dp1[i][j],maxi);
            }     
        }
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                maxi=max(maxi,grid[i][j]);
            }
        }
        
        return maxi;
    }
};