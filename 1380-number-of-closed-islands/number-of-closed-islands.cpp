class Solution {
public:
    // for 0 if any side is boundary of grid then only it is not closed 
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool find(vector<vector<int>>& grid,vector<vector<int>> &visited,int r,int c){
        int m=grid.size();
        int n=grid[0].size();
        bool flag=true;
        queue<pair<int,int>> q;
        visited[r][c]=true;
        q.push({r,c});
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if(nx<0 || nx>=m || ny<0 || ny>=n){
                    flag=false;
                }
                else{
                    if(grid[nx][ny]!=1 && !visited[nx][ny]){
                        visited[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && !visited[i][j]){
                    cnt+=find(grid,visited,i,j);
                }
            }
        }
        return cnt;
    }
};