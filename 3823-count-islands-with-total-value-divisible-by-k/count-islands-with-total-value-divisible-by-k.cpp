class Solution {
public:
    #define ll long long 
    ll mod;
    int  dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int bfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& visited){
        ll sm=0;
        int m=grid.size();
        int n=grid[0].size();
        visited[r][c]=true;
        queue<pair<int,int>> q;
        q.push({r,c});
        sm+=grid[r][c];
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny] && grid[nx][ny]>0){
                    visited[nx][ny]=1;
                    sm=(sm+grid[nx][ny])%mod;
                    q.push({nx,ny});
                }
            }
        }
        return sm;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        mod=1ll*k;
        vector<vector<int>> visited(m,vector<int>(n));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]>0){
                    ll sm=bfs(i,j,grid,visited);
                    if(sm%k ==0 )cnt++;
                }
            }
        }
        return cnt;

    }
};