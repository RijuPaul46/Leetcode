class Quad{
    public:
    int x,y,obs,step;
    Quad(int a,int b,int c,int d){
        x=a;
        y=b;
        obs=c;
        step=d;
    }
};
class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> best(m,vector<vector<int>>(n,vector<int>(k+1,INT_MAX)));
        for(int i=0;i<=k;i++)best[0][0][i]=0;
        queue<Quad*>q;
        q.push(new Quad(0,0,0,0));
        while(!q.empty()){
            Quad* qd=q.front();
            q.pop();
            int x=qd->x;
            int y=qd->y;
            int step=qd->step;
            int obs=qd->obs;
            if(step>best[x][y][obs])continue;//stale entry it is
            for(auto &it:dir){
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int n_step=best[x][y][obs]+1;
                    int n_o=obs+(grid[nx][ny]);
                    if(n_o>k)continue;
                    if(n_step<best[nx][ny][n_o]){
                        best[nx][ny][n_o]=n_step;
                        q.push(new Quad(nx,ny,n_o,step));
                    }
                }
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<=k;i++)mn=min(mn,best[m-1][n-1][i]);
        return mn==INT_MAX?-1:mn;

    }
};