class Solution {
public:
    // linearize the matrix number ... row=num/n -1. .. col=num%n -1;num=(num+k)%m*n
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x=n*i+j;
                x=(x+k)%(m*n);
                int row=x/n;
                int col=x%n;
                ans[row][col]=grid[i][j];
            }
        }
        return ans;
    }
};