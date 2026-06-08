class Solution {
public:
    int solve(int idx,int canbuy,vector<int>& prices,vector<vector<int>> &dp){
    int n=prices.size();
    if(idx>=n)return 0;
    auto & ref=dp[idx][canbuy];
    if(ref!=-1)return ref;
    int ans=0;
    if(canbuy){
        //buy
    ans=max(ans,-prices[idx]+solve(idx+1,0,prices,dp));
    }
    else{
        //sell with one gap
    ans=max(ans,+prices[idx]+solve(idx+2,1,prices,dp));
    }
    //skip
    ans=max(ans,solve(idx+1,canbuy,prices,dp));
    return ref=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};