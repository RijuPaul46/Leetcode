class Solution {
public:
    int minimumTotal(vector<vector<int>>& tgl) {
        int r=tgl.size();
        vector<vector<int>> dp(r);
        for(int i=0;i<r;i++){
            dp[i]=vector<int>(i+1);
        }
        dp[0][0]=tgl[0][0];
        for(int i=1;i<r;i++){
            for(int j=0;j<i+1;j++){
                int a=INT_MAX;
                int b=INT_MAX;
                if(j<i && j>=0)b=dp[i-1][j];
                if(j-1>=0 && j-1<i)a=dp[i-1][j-1];
                dp[i][j]=tgl[i][j]+min(b,a);
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<r;i++){
            mn=min(dp[r-1][i],mn);
        }
        return mn;
    }
};