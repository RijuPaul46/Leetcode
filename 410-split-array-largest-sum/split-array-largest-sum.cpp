#include <bits/stdc++.h>
class Solution {
public:
    int dp[1001][51];
    int solve(int idx,vector<int>& nums, int k,vector<int>&pre){
        int n=nums.size();
        if(k==0){
            int a= pre[n-1];
            if(idx-1>=0)a-=pre[idx-1];
            return a;
        }
        if(idx>=n-1)return INT_MAX;
        auto &ref=dp[idx][k];
        if(ref!=-1)return ref;
        int sm=INT_MAX;
        int sum=0;
        for(int i=idx;i<n;i++){
            sum+=nums[i];
            sm=min(sm,max(sum,solve(i+1,nums,k-1,pre)));
            
        }
        return ref=sm;


    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)pre[i]=pre[i-1]+nums[i];
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,k-1,pre);
    }
};