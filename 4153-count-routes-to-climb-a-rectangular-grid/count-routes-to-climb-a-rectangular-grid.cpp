#define ll long long

class Solution {
public:
    const ll mod=1e9+7;
    // ll dp[751][751][2];
    // ll solve(int i,int j,int already,vector<string>& grid, int d){
    //     if(grid[i][j]=='#')return 0;
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     if(dp[i][j][already]!=-1)return (int)dp[i][j][already]%mod;
    //     ll ans=0;
    //     if(i==0)ans=1;
    //     if(!already){
    //         for(int col=j+1;col<=min(n-1,j+d);col++){

    //                 ans=(ans+solve(i,col,1,grid,d)%mod)%mod;
                
    //         }
    //         for(int col=j-1;col>=max(0,j-d);col--){

    //                 ans=(ans+solve(i,col,1,grid,d)%mod)%mod;
                
    //         }
    //     }
    //     if(i>0){
    //     int dx=sqrt(1ll*d*d+(1e-9)-1);
    //     int beg=max(0,(j-dx));
    //     int end=min(n-1,(j+dx));
    //     for(int col=beg;col<=end;col++){
    //         ans=(ans+solve(i-1,col,0,grid,d)%mod)%mod;
    //     }
    //     }
    //     return dp[i][j][already]=ans%mod;
    // }
    int numberOfRoutes(vector<string>& grid, int d) {
        int m=grid.size();
        int n=grid[0].size();
        // memset(dp,-1,sizeof(dp));
        // ll ans=0;
        vector<vector<vector<ll>>> dp(m,vector<vector<ll>>(n,vector<ll>(2,0)));
        vector<ll> pre(n,0);
        vector<ll> temp0(n, 0);
ll sum1 = 0;
for(int j = 0; j < n; j++) {
    if(grid[0][j] == '.') {
        dp[0][j][1] = 1;
    }
    sum1 = (sum1 + dp[0][j][1]) % mod;
    temp0[j] = sum1;
}

ll sum0 = 0;
for(int j = 0; j < n; j++) {
    if(grid[0][j] == '.') {
        int beg = max(0, (j - d));
        int end = min(n - 1, (j + d));
        dp[0][j][0] = temp0[end];
        
        if(beg > 0) {
            dp[0][j][0] = (dp[0][j][0] - temp0[beg - 1] + mod) % mod;
        }
    }

    sum0 = (sum0 + dp[0][j][0]) % mod;
    pre[j] = sum0; 
}
        int dx=sqrt(1ll*d*d+(1e-9)-1);
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='.'){
                int beg=max(0,(j-dx));
                int end=min(n-1,(j+dx));
                dp[i][j][1]=pre[end];
                if(beg > 0) {
               dp[i][j][1] = (dp[i][j][1] - pre[beg-1] + mod) % mod;
                }}
            }
            vector<ll>temp(n,0);
            ll sum=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]=='.'){
                sum=(sum+dp[i][j][1])%mod;
                }
                temp[j]=sum;    
            }
            sum=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]=='.'){
                int beg=max(0,(j-d));
                int end=min(n-1,(j+d));
                dp[i][j][0]=temp[end];
                if(beg-1 >= 0) {
                dp[i][j][0] = (dp[i][j][0] - temp[beg-1] + mod) % mod;
                 }
                sum=(sum+dp[i][j][0])%mod;
                }
                pre[j]=sum;
            }
        }
        ll fin=0;
        for(int i=0;i<n;i++){
            fin=(fin+dp[m-1][i][0])%mod;
        }
        return fin;

        
    }
};