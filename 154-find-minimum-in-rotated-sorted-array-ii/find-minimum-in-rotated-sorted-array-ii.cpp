class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int mn=INT_MAX;
        for(auto &x:nums)mn=min(mn,x);
        return mn;
    }
};