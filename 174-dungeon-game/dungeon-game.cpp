class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& dungeon,vector<vector<int>> &dp){
        int m=dungeon.size();
        int n=dungeon[0].size();
        if(i==m || j==n)return INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==m-1 && j==n-1){
            if(dungeon[i][j]>0){
                return dp[i][j]=1;
            }
            else return dp[i][j]=abs(dungeon[i][j])+1;
        }
        //intermediate cell
        int right=solve(i,j+1,dungeon,dp);
        int down=solve(i+1,j,dungeon,dp);
        int need_to_carry=min(right,down);
        return dp[i][j]=max(1,need_to_carry-dungeon[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,dungeon,dp);
        // arr[0][0].first=dungeon[0][0];
        // arr[0][0].second=dungeon[0][0];
        // for(int i=1;i<n;i++){
        //     arr[0][i].first=arr[0][i-1].first+dungeon[0][i];
        //     arr[0][i].second=min(arr[0][i-1].second,arr[0][i].first);
        // }
        // for(int i=1;i<m;i++){
        //     arr[i][0].first=arr[i-1][0].first+dungeon[i][0];
        //     arr[i][0].second=min(arr[i-1][0].second,arr[i][0].first);
        // }
        // for(int i=1;i<m;i++){
        //     for(int j=1;j<n;j++){
        //         int up=min(arr[i-1][j].first+dungeon[i][j],arr[i-1][j].second);
        //         int left=min(arr[i][j-1].first+dungeon[i][j],arr[i][j-1].second);
        //         if(up>left){
        //             arr[i][j].first=arr[i-1][j].first+dungeon[i][j];
        //             arr[i][j].second=up;
        //         }
        //         else if(up==left){
        //             arr[i][j].first=max(arr[i-1][j].first+dungeon[i][j],arr[i][j-1].first+dungeon[i][j]);
        //             arr[i][j].second=up;
        //         }
        //         else{
        //             arr[i][j].first=arr[i][j-1].first+dungeon[i][j];
        //             arr[i][j].second=left;
        //         }
        //     }
        // }
        // // for(int i=0;i<m;i++){
        // //     for(int j=0;j<n;j++){
        // //         cout<<"("<<arr[i][j].first<<","<<arr[i][j].second<<" )";
        // //     }
        // //     cout<<endl;
        // // }
        // if(arr[m-1][n-1].second>0)return 1;
        // return abs(arr[m-1][n-1].second)+1;
    }
};