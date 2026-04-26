class Solution {
public:
    bool dfs(int i,int j,int pi,int pj,vector<vector<char>>& grid,vector<vector<bool>> &visited){
        //left
        int m=grid.size();
        int n=grid[0].size();
        if(visited[i][j])return true;
        bool ans=false;
        visited[i][j]=true;
        if(j-1>=0 && j-1!=pj && grid[i][j-1]==grid[i][j]){
            
            ans|= dfs(i,j-1,i,j,grid,visited);
            if(ans)return true;
            
        }
        if(j+1<n && j+1!=pj && grid[i][j+1]==grid[i][j]){
            
            ans|= dfs(i,j+1,i,j,grid,visited);
            if(ans)return true;
        }
        if(i-1>=0 && i-1!=pi && grid[i-1][j]==grid[i][j]){
            
            ans|=dfs(i-1,j,i,j,grid,visited);
            if(ans)return true;
        }
        if(i+1<m && i+1!=pi && grid[i+1][j]==grid[i][j]){
            
            ans|=dfs(i+1,j,i,j,grid,visited);
            if(ans)return true;
        }
        return ans;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                    if(dfs(i,j,-1,-1,grid,visited))return true;
                }
            }
        }
        return false;

    }
};