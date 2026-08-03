class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&arr,int idx){
        int n=arr.size();
        if(idx==n)return 0;
        if(dp[idx]!=INT_MIN)return dp[idx];
        int sm=0;
        int ans=INT_MIN;
        for(int j=idx;j<n && j<idx+3;j++){ 
            sm+=arr[j];
            ans=max(ans,sm-solve(arr,j+1));
        }
        return dp[idx]=ans;
    }
    string stoneGameIII(vector<int>& stn) {
        int total=0;
        int n=stn.size();
        dp.assign(n,INT_MIN);
        for(int i=0;i<stn.size();i++)total+=stn[i];
        int diff=solve(stn,0);
        if(diff==0)return "Tie";
        if(diff>0)return "Alice";
        return "Bob";

    }
};