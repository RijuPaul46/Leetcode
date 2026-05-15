class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int l=0;
        int r=n-1;
        if(nums[l]<nums[r])return nums[l];
        while(l<r-1){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[l]){
                l=mid;
            }
            else r=mid;
        }
        return nums[r];
    }
};