class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto &x:nums)mp[x]++;
        if(k==1 ){
            int mx=-1;
            for(auto &x:nums){
                if(mp[x]<=1)mx=max(mx,x);
            }
            return mx;
        }
        if(k==n){
            int mx=-1;
            for(auto &x:nums)mx=max(mx,x);
            return mx;
        }
        int first=nums[0];
        int last=nums[n-1];
        int mx=-1;
        if(mp[first]==1)mx=max(mx,first);
        if(mp[last]==1)mx=max(mx,last);
        return mx;

    }
};