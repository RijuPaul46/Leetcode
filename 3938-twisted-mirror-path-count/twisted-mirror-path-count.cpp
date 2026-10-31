class Solution {
public:
    #define ll long long
    ll mod =1e9+7;
    ll dpx[500][500][2];
    ll solve(int r,int c,vector<vector<int>>& grid,int prev){
        int m=grid.size();
        int n=grid[0].size();
        if(r==m-1 && c==n-1)return 1;
        if(r<0 || r>=m || c<0 || c>=n)return 0;
        auto &ref=dpx[r][c][prev];
        if(ref!=-1)return ref;
        
        if(grid[r][c]==1){
            if(prev==0){
                return ref=solve(r,c+1,grid,1);
            }
            return ref=solve(r+1,c,grid,0);
        }
        ll right=solve(r,c+1,grid,1);
        ll down=solve(r+1,c,grid,0);
        return ref=(1ll* right+down)%mod;
        


    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // in mirror cell from which direction we came matter 
        // we will not explore mirror cell from same direction 
        // 0 represent from up, 1 represent from left
        // empty cell 
        // vector<vector<vector<ll>>> dp(m,vector<vector<ll>>(n,vector<ll>(2,-1)));
        memset(dpx,-1,sizeof(dpx));
        return (int)solve(0,0,grid,0);
    }
};