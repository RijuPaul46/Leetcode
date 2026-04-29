class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> arr(m,vector<int>(n,INT_MIN));
        stack<int>st;
        int mn=grid[0][0];
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            arr[0][i]=max(arr[0][i],grid[0][i]-mn);
            ans=max(ans,arr[0][i]);
            mn=min(grid[0][i],mn);
        }
        mn=grid[0][0];
        for(int i=1;i<m;i++){
            arr[i][0]=max(arr[i][0],grid[i][0]-mn);
            ans=max(ans,arr[i][0]);
            mn=min(grid[i][0],mn);
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int up=max(0,arr[i-1][j])+grid[i][j]-grid[i-1][j];
                int left=max(0,arr[i][j-1])+grid[i][j]-grid[i][j-1];
                arr[i][j]=max(arr[i][j],max(up,left));
                ans=max(ans,arr[i][j]);
            }
        }
        return ans;
      
    }
};