class Solution {
public:
    int solve(int idx,int state,vector<int>& prices,int mx_tr,vector<vector<int>> &dp){
        int n=prices.size();
        if(idx==n){
            return 0;
        }
        if(state>=mx_tr)return 0;
        // 0, 2, 4 --- represent can buy
        auto &ref=dp[idx][state];
        if(ref!=-1)return ref;
        int ans=0;
        if((state%2)==0){
            ans=max(ans,-prices[idx]+solve(idx+1,state+1,prices,mx_tr,dp));
            // cout<<"Buy:"<<ans<<" "<<state<<endl;
        }
        // odd represetn can sell 
        else {
            ans=max(ans,prices[idx]+solve(idx+1,state+1,prices,mx_tr,dp));
            // cout<<"sell,state:"<<ans<<" "<<state<<endl;
        }
        //skip this 
        ans=max(ans,solve(idx+1,state,prices,mx_tr,dp));
        // cout<<"skip,state:"<<ans<<" "<<state<<endl;
        return ref=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
       return solve(0,0,prices,4,dp); 
    }
};