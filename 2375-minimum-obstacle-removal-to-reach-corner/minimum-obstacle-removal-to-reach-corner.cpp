class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> cost(m,vector<int>(n,INT_MAX));
        int first=grid[0][0];
        cost[0][0]=first;
        deque<tuple<int,int,int>> dq;
        dq.push_front({first,0,0});
        while(!dq.empty()){
            auto [d,x,y]=dq.front();
            dq.pop_front();
            if(d>cost[x][y])continue;
            for(int i=0;i<4;i++){
                int nx=x+dir[i].first;
                int ny=y+dir[i].second;
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int ob=grid[nx][ny];
                    int nc=cost[x][y]+ob;
                    if(nc<cost[nx][ny]){
                        cost[nx][ny]=nc;
                        if(ob)dq.push_back({nc,nx,ny});
                        else dq.push_front({nc,nx,ny});
                    }
                }
            }
        }
        return cost[m-1][n-1];
    }
};