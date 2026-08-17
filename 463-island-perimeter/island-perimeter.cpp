class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int add=4;
                    if(i-1>=0 && grid[i-1][j]==1)add--;
                    if(i+1<m && grid[i+1][j]==1)add--;
                    if(j+1<n && grid[i][j+1]==1)add--;
                    if(j-1>=0 && grid[i][j-1]==1)add--;
                    cnt+=add;
                }
            }
        }
        return cnt;
    }
};