class Solution {
    //useless question
public:
    int m,n;
    unordered_map<int,vector<vector<int>>> direction={
        {1, { {1,0} , {-1,0} }},
        {2, { {0,1} , {0,-1} }},
        {3, { {-1,0} , {0,1} }},
        {4, { {1,0} , {0,1} }},
        {5, { {-1,0} , {0,-1} }},
        {6, { {1,0} , {0,-1} }},
    };
    bool dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& visited){
        if(i==m-1 && j==n-1)return true;
        visited[i][j]=true;
        bool ans=false;
        for(auto & dir:direction[grid[i][j]]){
            int ni=i+dir[1];
            int nj=j+dir[0];
            if(ni>=0 && ni<m && nj>=0 && nj<n && !visited[ni][nj]){
                for(auto& backdir:direction[grid[ni][nj]]){
                    if((ni+backdir[1]==i) && nj+backdir[0]==j){
                        ans|= dfs(ni,nj,grid,visited);
                    }
                }
            }
        }
        return ans;

    }
    bool hasValidPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        return dfs(0,0,grid,visited);
    }
};