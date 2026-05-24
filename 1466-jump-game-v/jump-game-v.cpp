class Solution {
public:
    int solve(int idx,vector<int>& arr, int d,vector<int> &dp){
        int n=arr.size();
        if(dp[idx]!=-1)return dp[idx];
        int mx=1;
        for(int i=idx+1;i<=min(n-1,idx+d);i++){
            if(arr[idx]>arr[i]){
            mx=max(mx,1+solve(i,arr,d,dp));
            }
            else break;
        }
        for(int i=idx-1;i>=max(0,idx-d);i--){
            if(arr[idx]>arr[i]){
                mx=max(mx,1+solve(i,arr,d,dp));
            }
            else break;
        }
        return dp[idx]=mx;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> dp(n,-1);
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,solve(i,arr,d,dp));
        }
        return ans;
    }
};