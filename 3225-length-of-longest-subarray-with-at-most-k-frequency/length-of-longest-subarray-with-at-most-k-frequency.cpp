class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int i=0,j=0;
        int ans=0;
        while(i<n){
            int x=nums[i];
            mp[x]++;
            while(mp[x]>k){
                mp[nums[j++]]--;
            }
            ans=max(ans,(i-j+1));
            i++;
        }
        return ans;
    }
};