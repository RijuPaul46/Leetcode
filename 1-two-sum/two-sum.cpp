class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(mp.count(x)){
                return {mp[x],i};
            }
            else mp[target-x]=i;
        }
        return {-1,-1};
    }
};