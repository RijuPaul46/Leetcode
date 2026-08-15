class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(auto &x:nums){
            ans^=x;
        }
        if(ans!=0)return n;
        return (nums[n-1]==0)?0:n-1;
    }
};