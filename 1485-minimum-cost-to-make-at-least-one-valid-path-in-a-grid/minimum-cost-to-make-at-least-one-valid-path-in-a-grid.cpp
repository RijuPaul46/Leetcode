#define state tuple<int,int,int>
class Solution {
public:
    
    // int solve(int i,int j,vector<vector<int>>& grid,vector<vector<bool>> &visited){
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     if(i<0 || j<0 || i>=m || j>=n){
    //         return 5000;
    //     }
    //     if(i==m-1 && j==n-1)return 0;
    //     if(visited[i][j])return 5000;
    //     visited[i][j]=true;
    //     int type=grid[i][j]-1;
    //     int ans=5000;
    //     for(int k=0;k<4;k++){
    //         int x=dir[k][0];
    //         int y=dir[k][1];
    //         int temp=solve(i+x,i+y,grid,visited)+((k==type)?0:1);
    //         ans=min(temp,ans);
    //     }
    //     visited[i][j]=false;
    //     return ans;
    // }
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> cost(m,vector<int>(n,INT_MAX));
        cost[0][0]=0;
        deque<state> pq;
        pq.push_back({0,0,0});
        while(pq.size()){
            auto [c,x,y]=pq.front();
            pq.pop_front();
            if(c>cost[x][y])continue;
            for(int k=0;k<4;k++){
                auto &it=dir[k];
                int nx=x+it[0];
                int ny=y+it[1];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int type=grid[x][y]-1;
                    int cst=cost[x][y]+(k==type?0:1);
                    if(cst<cost[nx][ny]){
                        cost[nx][ny]=cst;
                        if(k==type)
                        pq.push_front({cst,nx,ny});
                        else pq.push_back({cst,nx,ny});
                    }
                }
            }
        }
        return cost[m-1][n-1];
        
    }
};