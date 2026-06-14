class Solution {
public: 
    unordered_map<int,int> dp;

    int solve(int mask,vector<int>& arr, int k){
        int n=arr.size();
        int ans=INT_MAX;
        int broken=0;
        if(dp.count(mask))return dp[mask];
        vector<int> avail;
        for(int i=0;i<n;i++){
            if((mask>>i)&1)broken++;
            else avail.push_back(i);
        }
        if(avail.size()==0)return dp[mask]=0;
        for(auto &av:avail){
            int n_mask=mask|(1<<av);
            int take=ceil(arr[av]*1.0/(1+broken*k));
            ans=min(ans,take+solve(n_mask,arr,k));
        }
        return dp[mask]=ans;
    }
    int findMinimumTime(vector<int>& strength, int k) {

        int n=strength.size();
        return solve(0,strength,k);

    }
};