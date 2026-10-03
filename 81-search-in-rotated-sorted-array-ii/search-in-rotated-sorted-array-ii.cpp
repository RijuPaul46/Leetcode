class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target)return 1;
            if(nums[mid]==nums[l] && nums[mid]==nums[h]){
                l++;
                h--;
                continue;
            }
            if(nums[l]<=nums[mid]){
                // left half sorted
                if(target<nums[mid] && target>=nums[l])h=mid-1;
                else l=mid+1;
            }
            else{
                // right half sorted fs
                if(target>nums[mid] && target<=nums[h]){
                    l=mid+1;
                }
                else h=mid-1;
            }
        }
        return 0;
    }
};