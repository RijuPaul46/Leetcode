class Solution {
public:
    int solve(int idx,int state,vector<int>& prices,int fee,vector<vector<int>> &dp){
        int n=prices.size();
        if(idx==n){
            return 0;
        }
        // 0, 2, 4 --- represent can buy
        auto &ref=dp[idx][state];
        if(ref!=-1)return ref;
        int ans=0;
        if((state%2)==0){
            ans=max(ans,-prices[idx]+solve(idx+1,1,prices,fee,dp));
        }
        // odd represetn can sell 
        else {
            ans=max(ans,prices[idx]-fee+solve(idx+1,0,prices,fee,dp));
        }
        //skip this 
        ans=max(ans,solve(idx+1,state,prices,fee,dp));
        return ref=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,0,prices,fee,dp); 
    }
};