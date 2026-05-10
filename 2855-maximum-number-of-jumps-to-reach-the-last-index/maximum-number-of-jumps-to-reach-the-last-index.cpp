#define ll long long
class Solution {
public:
    int solve(int i,vector<vector<int>> &canJump,vector<int>&dp,int n){
        if(i==n-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MIN;
        if(canJump[i].size()>0){
        for(auto &x:canJump[i]){
            int val=solve(x,canJump,dp,n);
            if(val!=INT_MIN) ans=max(ans,1+val);
        }
        }
        return dp[i]=ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> canJump(n);
        for(int i=0;i<n;i++){
            ll low=1ll*nums[i]-target;
            ll high=1ll*nums[i]+target;
            for(int j=i+1;j<n;j++){
                if(nums[j]>=low && nums[j]<=high){
                    canJump[i].push_back(j);
                }
            }
        }
        vector<int>dp(n,-1);
        int ans= solve(0,canJump,dp,n);
        if(ans==INT_MIN)return -1;
        return ans;
        // int lvl=0;
        // queue<int> q;
        // q.push(0);
        // while(!q.empty()){
        //     int sz=q.size();
        //     for(int i=0;i<sz;i++){
        //         int idx=q.front();
        //         q.pop();
        //         if(idx==n-1){
        //             ans=max(ans,lvl);
        //         }
        //         else{
        //             for(auto &x:canJump[idx]){
        //                 q.push(x);
        //             }
        //         }
        //     }
        //     lvl++;
        // }
        
    }
};